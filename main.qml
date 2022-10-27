import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("TuneIt")
    color: "black"

    WorkerScript {
        id: updateWorker
        source: "updateworker.mjs"
        onMessage: (messageObject) => {
                       mycanvas.fftValues = messageObject.result;
                       mycanvas.peakFreq = messageObject.peakFreq;
                       mycanvas.requestPaint()
                   }
    }

    Connections {
        target: fftProcessor
        function onProcessingDone(numFrames,peakFreq,outputBufferList) {
            updateWorker.sendMessage({outputBufferList: outputBufferList, peakFreq, numFrames: numFrames })
        }
    }
    Text {
        id: infoLabel
        font.pixelSize: 16
        color: "white"
        z: 99
        text: audioRecorder != null ?
`Audio API: ${audioRecorder.apiName != null ? audioRecorder.apiName : "Unknown"}
Channels: ${audioRecorder.numChannels}
Sampling Rate: ${audioRecorder.samplingRate}
Buffer Size: 512
QSG Rendering API: ${qsgInfo.getRenderingApiName()}
` : `audioRecorder null
`
        //Channels: ${audioRecorder.channelCount} channels
        //Sampling rate: ${audioRecorder.samplingRate}`
    }
    Rectangle {
        anchors.top: infoLabel.bottom
        color: "#222"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        Text {
            color: "white"
            font.family: "Roboto"
            z: 999
            text: `
            <h1 style="font-weight: 300; word-spacing: -36pt">${mycanvas.peakNote}</h1> <i style="font-size: 40%">${mycanvas.peakFreq} Hz</i>
            `
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 0.76
            textFormat: Text.RichText
            minimumPixelSize: 10; font.pixelSize: Math.min(mycanvas.width, mycanvas.height) * 0.06
            fontSizeMode: Text.Fit
            anchors.centerIn: parent
        }

        Canvas {
            id: mycanvas
            width: parent.width * 0.33
            height: parent.height * 0.33
            anchors.centerIn: parent
            anchors.fill: parent
            renderTarget: Canvas.FramebufferObject
            renderStrategy: Canvas.Cooperative
            property var fftValues: []
            property real peakFreq: 0
            property var peakNote: "?"

            function repaint() {
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
                var fftValues = mycanvas.fftValues;
                var halfFftValuesLength = fftValues.length / 2;

                for (var seg=0;seg<numBars;seg++) {
                    ctx.beginPath()
                    ctx.strokeStyle = Qt.tint(Qt.rgba(0.64,0.83,0.65,1),
                                              Qt.rgba(1,0.878,0.51,0.5+Math.sin(seg/numBars*Math.PI*4)))
                    ctx.fillStyle = ctx.strokeStyle
                    ctx.moveTo(centerX, centerY-(radius*0.33))
                    ctx.lineTo(centerX, centerY-(radius*(0.34+fftValues[halfFftValuesLength+Math.floor(seg/numBars*halfFftValuesLength)])) )
                    ctx.stroke()
                    ctx.save()
                    ctx.rotate(deg2rad(2))
                    ctx.restore()
                    ctx.translate(centerX, centerY)
                    ctx.rotate(deg2rad(barRotSpacing))
                    ctx.translate(-centerX, -centerY)
                }
                requestAnimationFrame(repaint)
            }

            onPaint: {
                repaint();
            }
        }
    }

    /*##^##
    Designer {
        D{i:0;autoSize:true;formeditorZoom:0.33;height:480;width:640}
    }
    ##^##*/

}
