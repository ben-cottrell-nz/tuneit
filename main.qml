import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 2.15

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("TuneIt")
    color: "black"
    property var fftValues: []
    property real peakFreq: 0
    property var peakNote: "?"
    Material.theme: Material.Dark
    Material.accent: Material.Purple
    header: ToolBar {
        id: toolBar
        z: 99
        anchors.right: parent.right
        anchors.left: parent.left
        contentHeight: toolButton.implicitHeight
        RowLayout {
        anchors.fill: parent
            ToolButton {
                id: toolButton
                text: "\u2630"
                onClicked: {
                    drawer.open()
                }
            }
            Label {
                id: headerLabel
                elide: Label.ElideRight
                font.bold: true

                 horizontalAlignment: Qt.AlignHCenter
                 verticalAlignment: Qt.AlignVCenter
                 Layout.fillWidth: true
                text: freqView.viewModeNames[freqView.viewMode]
            }
        }
    }
    Drawer {
        id: drawer
        width: root.width * 0.33
        height: root.height

        Column {
            anchors.fill: parent
            ItemDelegate {
                text: qsTr("Circular Bars")
                width: parent.width
                onClicked: {
                    freqView.viewMode = FrequencyPlotView.ViewMode.CircularBars
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Horizontal Bar Chart")
                width: parent.width
                onClicked: {
                    freqView.viewMode = FrequencyPlotView.ViewMode.BarChart
                    drawer.close()
                }
            }
        }
    }
    WorkerScript {
        id: updateWorker
        source: "updateworker.mjs"
        onMessage: (messageObject) => {
           root.fftValues = messageObject.result;
           root.peakFreq = messageObject.peakFreq;
           freqView.canvas.requestPaint()
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
        anchors.top: toolBar.bottom
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
    FrequencyPlotView { id: freqView }

    /*##^##
    Designer {
        D{i:0;autoSize:true;formeditorZoom:0.33;height:480;width:640}
    }
    ##^##*/

}
