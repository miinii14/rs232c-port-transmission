import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

ApplicationWindow {
    id: mainWindow
    visible: true
    width: Screen.width
    height: Screen.height
    flags: Qt.FramelessWindowHint
    color: "#282c34"

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: Rectangle {
            color: "#282c34"
            anchors.fill: parent

            Button {
                id: closeButton
                text: "✖"
                font.pixelSize: 30
                width: 50
                height: 50
                background: Rectangle {
                    color: "#f44336"
                    radius: 25
                    border.color: "#ffffff"
                    border.width: 2
                }
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.margins: 10
                onClicked: {
                    portManager.closeSerialPort();
                    Qt.quit()
                }
            }

            ColumnLayout {
                anchors.centerIn: parent
                spacing: 20

                TextField {
                    id: portNumber
                    placeholderText: "Port Number"
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 24
                    padding: 12
                    background: Rectangle {
                        color: "#ffffff"
                        radius: 10
                        border.color: "#a0a0a0"
                    }
                }

                TextField {
                    id: baudRate
                    placeholderText: "Baud Rate"
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 24
                    width: parent.width * 0.6
                    height: 50
                    padding: 12
                    background: Rectangle {
                        color: "#ffffff"
                        radius: 10
                        border.color: "#a0a0a0"
                    }
                }

                TextField {
                    id: parity
                    placeholderText: "Parity"
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 24
                    width: parent.width * 0.6
                    height: 50
                    padding: 12
                    background: Rectangle {
                        color: "#ffffff"
                        radius: 10
                        border.color: "#a0a0a0"
                    }
                }

                TextField {
                    id: stopBits
                    placeholderText: "Stop Bits"
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 24
                    width: parent.width * 0.6
                    height: 50
                    padding: 12
                    background: Rectangle {
                        color: "#ffffff"
                        radius: 10
                        border.color: "#a0a0a0"
                    }
                }

                TextField {
                    id: byteSize
                    placeholderText: "Byte Size"
                    Layout.alignment: Qt.AlignHCenter
                    font.pixelSize: 24
                    width: parent.width * 0.6
                    height: 50
                    padding: 12
                    background: Rectangle {
                        color: "#ffffff"
                        radius: 10
                        border.color: "#a0a0a0"
                    }
                }

                Button {
                    text: "Open Port"
                    font.pixelSize: 24
                    width: parent.width * 0.6
                    height: 60
                    padding: 12
                    Layout.alignment: Qt.AlignHCenter
                    background: Rectangle {
                        color: "#4CAF50"
                        radius: 10
                    }
                    onClicked: {
                        var error = portManager.openSerialPort(portNumber.text, baudRate.text, parity.text, stopBits.text, byteSize.text);
                        if (error == "Success") {
                            stackView.push("SecondWindow.qml");
                        } else {
                            errorMessage.text = error;
                            errorDialog.visible = true;
                            portManager.closeSerialPort();
                        }
                    }
                }
            }
        }

        Dialog {
            id: errorDialog
            title: "Error"
            visible: false
            modal: true
            width: 300
            height: 150

            Rectangle {
                width: parent.width
                height: parent.height
                color: "#333742"
                radius: 10

                ColumnLayout {
                    anchors.fill: parent
                    spacing: 10

                    Text {
                        id: errorMessage
                        text: ""
                        color: "white"
                        font.pixelSize: 18
                        wrapMode: Text.Wrap
                    }

                    Button {
                        anchors.centerIn: parent
                        text: "Close"
                        font.pixelSize: 18
                        onClicked: {
                            errorDialog.visible = false;
                            errorDialog.text = "";
                        }
                    }
                }
            }
        }
    }
}
