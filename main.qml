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
        contentHeight: buttonShowDrawer.implicitHeight
        RowLayout {
        anchors.fill: parent
            ToolButton {
                id: buttonShowDrawer
                text: "\u2630 Menu"
                onClicked: {
                    drawer.open()
                }
            }
            ToolButton {
                id: buttonShowSettings
                text: "\u2699 Settings"
                onClicked: {
                    settingsDialog.visible = true
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
    Dialog {
        id: settingsDialog
        visible: false
        title: "Settings"
        anchors.centerIn: parent
        standardButtons: Dialog.Ok | Dialog.Cancel
        width: 0.83*root.width
        height: 0.83*root.height
        ScrollView {
            width: parent.width
            height: parent.height
            contentWidth: column.width
            contentHeight: column.height
            clip: true
        ColumnLayout {
                id: column
                width: settingsDialog.width * 0.8
            Row {
                spacing: 5
                Layout.fillWidth: true
                Button {
                    id: buttonRestartAudio
    //                Layout.fillWidth: true
                    text: "Restart Audio"
                    onClicked: { audioRecorder.stop(); audioRecorder.start(); }
                }
                Button {
                    id: buttonResetToDefaultSettings
                    text: "Reset to Default Settings"
                }
            }
            Label {
                text: qsTr("Input Device:")
            }
            ComboBox {
                Layout.fillWidth: true
                model: [appSettings.audioInputDeviceName]
//                model: appSettings.getAvailableInputDevNames()
//                currentIndex: appSettings.
            }
            Label {
                text: qsTr("Number of Channels:")
            }
            ComboBox {
                Layout.fillWidth: true
                model: [appSettings.numInputChannels]
//                model: appSettings.getAvailableNumInputChannels()
//                currentIndex: appSettings.getAvailableNumInputChannels()
//                .indexOf(appSettings.numInputChannels)
            }
            Label {
                text: qsTr("Sampling Rate:")
            }
            ComboBox {
                Layout.fillWidth: true
                model: [appSettings.samplingRate]
            }
        }
        }
        onAccepted: console.log("Ok clicked")
        onRejected: console.log("Cancel clicked")
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
    FrequencyPlotView { id: freqView }
}
