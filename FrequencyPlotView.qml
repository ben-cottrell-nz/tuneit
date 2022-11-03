import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
Rectangle {
    property alias canvas: mycanvas
    enum ViewMode {
        CircularBars,
        BarChart
    }
    property var viewModeNames: ["Circular Bars","Horizontal Bar Chart"]
    property var viewMode: FrequencyPlotView.ViewMode.BarChart
    onViewModeChanged: function (e) {
        if (viewMode == FrequencyPlotView.ViewMode.CircularBars) {
            mycanvas.paintFunction = mycanvas.repaintCircularBars
        } else if (viewMode == FrequencyPlotView.ViewMode.BarChart) {
            mycanvas.paintFunction = mycanvas.repaintBarChart
        }
        mycanvas.requestPaint();
    }
        anchors.top: parent.top
        color: "#222"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        /*
        Text {
            color: "white"
            font.family: "Roboto"
            z: 999
            text: `
            <h1 style="font-weight: 300; word-spacing: -36pt">${root.peakNote}</h1>
            <i style="font-size: 40%">${root.peakFreq} Hz</i>
            `
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 0.76
            textFormat: Text.RichText
            minimumPixelSize: 10; font.pixelSize: Math.min(mycanvas.width, mycanvas.height) * 0.06
            fontSizeMode: Text.Fit
            anchors.centerIn: parent
        }
        */

        Canvas {
            id: mycanvas
            width: parent.width * 0.33
            height: parent.height * 0.33
            anchors.centerIn: parent
            anchors.fill: parent
            renderTarget: Canvas.FramebufferObject
            renderStrategy: Canvas.Cooperative
            MouseArea {
                id: mouseArea
            }

            property var paintFunction: repaintCircularBars

            function repaintBarChart() {
                var ctx = getContext("2d");
                ctx.resetTransform()
                ctx.fillStyle = 'black'
                ctx.fillRect(0, 0, width, height)
                var numBars = 109
                var barSpace = 1
                var barWidth = (mycanvas.width - numBars * barSpace) / numBars
                var bottom = mycanvas.height
                var halfViewHeight = mycanvas.height / 2
                var fftValues = root.fftValues;
                var binSize = audioRecorder.samplingRate / fftValues.length
                var halfFftValuesLength = fftValues.length / 2;
                var fftValuesLength = fftValues.length;
                ctx.fillStyle = 'lime'
                ctx.font = "bold 16px sans-serif"
                ctx.fillText("Hz", mycanvas.width / 2, halfViewHeight+40)
                var xPos = 0;
                var mouseX = mouseArea.mouseX
                ctx.font = "16px sans-serif";
                for (var seg=0;seg < numBars; seg++) {
                    xPos = seg * (barWidth + barSpace)
                    ctx.fillRect(xPos, halfViewHeight,
                    barWidth,
                    fftValues[halfFftValuesLength+Math.floor(seg/numBars*halfFftValuesLength)]
                    * halfViewHeight * -1)
                    if (seg % 20 == 0) {
                        ctx.fillText( (Math.floor(seg/numBars*halfFftValuesLength)*binSize).toFixed(2),
                                     xPos, halfViewHeight + 20)
                    }
                }

            }

            function repaintCircularBars() {
                var ctx = getContext("2d");
                ctx.resetTransform()
                ctx.fillStyle = 'black'
                ctx.fillRect(0, 0, width, height)
                var centerX = mycanvas.width / 2
                var centerY = mycanvas.height / 2
                var radius = Math.min(mycanvas.width, mycanvas.height) * 0.9
                var barStrokeWidth = 5
                function deg2rad(val) { return val/180*Math.PI; }
                var numBars = 109
                var barRotSpacing = 360/numBars
                var circumOffsetAngleDeg = 1
                ctx.beginPath();
                ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI, false);
                //draw 24 segments around the circle
                ctx.lineCap = 'round'
                ctx.lineWidth = barStrokeWidth
                var fftValues = root.fftValues;
                var halfFftValuesLength = fftValues.length / 2;
                var fftValuesLength = fftValues.length;

                for (var seg=0;seg<numBars;seg++) {
                    ctx.beginPath()
                    ctx.strokeStyle = Qt.tint(Qt.rgba(0.64,0.83,0.65,1),
                                              Qt.rgba(1,0.878,0.51,0.5+Math.sin(seg/numBars*Math.PI*4)))
                    ctx.fillStyle = ctx.strokeStyle
                    ctx.moveTo(centerX, centerY-(radius*0.33))
                    ctx.lineTo(
                        centerX, centerY-radius*(
                                0.33+fftValues[halfFftValuesLength+Math.floor(seg/numBars*halfFftValuesLength)]
                            )
                    )
                    ctx.stroke()
                    ctx.save()
                    ctx.rotate(deg2rad(2))
                    ctx.restore()
                    ctx.translate(centerX, centerY)
                    ctx.rotate(deg2rad(barRotSpacing))
                    ctx.translate(-centerX, -centerY)
                }
            }

            onPaint: {
                paintFunction();
                requestAnimationFrame(paintFunction)
            }
        }
    }
