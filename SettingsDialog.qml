import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 2.15

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
        }
        Label {
            text: qsTr("Number of Channels:")
        }
        ComboBox {
            Layout.fillWidth: true
            model: [appSettings.numInputChannels]
        }
        Label {
            text: qsTr("Sampling Rate:")
        }
        ComboBox {
            Layout.fillWidth: true
            model: [appSettings.samplingRate]
        }
        Label {
            text: qsTr("Horizontal Bar Chart Plot Mode:")
        }
        ComboBox {
            Layout.fillWidth: true
            model: ["Linear", "Log-Log"]
        }
    }
    }
    onAccepted: console.log("Ok clicked")
    onRejected: console.log("Cancel clicked")
}
