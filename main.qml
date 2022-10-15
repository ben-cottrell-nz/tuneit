import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("TuneIt")

    Rectangle {
        //    width: parent.
        anchors.fill: parent

        color: "#222"
        Text {
            color: "white"
            font.family: "Roboto"
            text: `
            <h1 style="font-weight: 300; word-spacing: -36pt">C#<sub>4</sub></h1> <i style="font-size: 40%">217.18 Hz</i>
            `
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 0.76
            textFormat: Text.RichText
    //        width: 200
    //        height: 200
    //        font.pointSize: 58
            minimumPixelSize: 10; font.pixelSize: Math.min(mycanvas.width, mycanvas.height) * 0.06
            fontSizeMode: Text.Fit
            anchors.centerIn: parent
        }

        Canvas {
            id: mycanvas
            width: 300
            height: 300
            anchors.fill: parent

            onPaint: {
                var ctx = getContext("2d");
                var centerX = mycanvas.width / 2
                var centerY = mycanvas.height / 2
                var radius = Math.min(mycanvas.width, mycanvas.height) * 0.9
                var barStrokeWidth = 5
                function deg2rad(val) { return val/180*Math.PI; }
                var numBars = 168
                var barRotSpacing = 360/numBars
    //            var circumOffsetAngle = (41 / (2 * Math.PI * radius) * 360) / 180 * Math.PI
                var circumOffsetAngleDeg = 1
                ctx.clearRect(0,0,ctx.width,ctx.height)
                ctx.fillStyle = 'transparent';
                ctx.beginPath();
                ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI, false);
                //draw 24 segments around the circle
                ctx.lineCap = 'round'
                ctx.lineWidth = barStrokeWidth

                for (var seg=0;seg<filt.numFreqBins;seg++) {
                    ctx.beginPath()
    //                ctx.strokeStyle = Qt.tint("red", Qt.rgba(0.16,1,0.16,seg/numBars))
    //                ctx.strokeStyle = Qt.hsva(lower.value + Math.cos(seg/numBars*Math.PI*2)*upper.value,1,1,1)
    //                ctx.strokeStyle = Qt.tint(
    //                            Qt.hsva(0.34 + Math.sin(seg/numBars*Math.PI*4)*0.3,1,1,1),
    //                            Qt.rgba(1,1,1,0.2))
                    ctx.strokeStyle = Qt.tint(Qt.rgba(0.64,0.83,0.65,1),
                                              Qt.rgba(1,0.878,0.51,0.5+Math.sin(seg/numBars*Math.PI*4)))
                    ctx.fillStyle = ctx.strokeStyle
                    ctx.moveTo(centerX, centerY-(radius*0.33))
                    ctx.lineTo(centerX, centerY-(radius*(0.34+Math.random()*0.065
                                                         * Math.abs(Math.cos(seg/numBars*Math.PI*12)*4) )))

                    ctx.stroke()
    //                ctx.save()
                    ctx.font = "600 12pt sans-serif"
    //                if (seg == 0) {
    //                    ctx.font = "16pt sans-serif"
    //                    ctx.fillText("Kilohertz (kHz)", centerX-81, centerY-(radius*0.33)+78)
    //                    ctx.font = "600 12pt sans-serif"
    //                }
                    ctx.save()
                    ctx.rotate(deg2rad(2))
//                    if (seg % 8 == 0 /*&& seg < numBars - 8*/) {
//                        var freqStr = (seg/numBars*8*1000).toFixed().toString()
//                        ctx.fillText(freqStr, centerX /*- (freqStr.length*4)*/, centerY-(radius*0.33)+4)
//                    }
                    ctx.restore()
                    ctx.translate(centerX, centerY)
                    ctx.rotate(deg2rad(barRotSpacing/*(seg/numBars)*360*//*- circumOffsetAngleDeg*/))
                    ctx.translate(-centerX, -centerY)
    //                ctx.restore()
                }
    //            ctx.translate(centerX, centerY)
    //            ctx.rotate(deg2rad(mycanvas.rot))
    //            ctx.translate(-centerX, -centerY)
    //            context.fill();
            }
        }
    }

    /*##^##
    Designer {
        D{i:0;autoSize:true;formeditorZoom:0.33;height:480;width:640}
    }
    ##^##*/

}
