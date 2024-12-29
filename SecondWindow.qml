import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    visible: true
    width: Screen.width
    height: Screen.height
    color: "#282c34"

    ColumnLayout {
        anchors.fill: parent
        spacing: 15

        Rectangle {
            Layout.fillWidth: true
            height: 60
            color: "#1c1f26"
            radius: 10

            RowLayout {
                anchors.fill: parent
                spacing: 10
                anchors.margins: 10

                Text {
                    id: selectedFile
                    text: "No file selected"
                    color: "white"
                    font.pixelSize: 20
                    Layout.alignment: Qt.AlignVCenter
                }

                Button {
                    text: "Choose File"
                    font.pixelSize: 18
                    Layout.alignment: Qt.AlignVCenter
                    onClicked: {
                        if (isBinary.checked) {
                            if (portManager.readFromBinaryFile() == "Success") {
                                imageToSend.visible = true;
                                imageToReceive.visible = true;
                                imageToSend.source = portManager.getImageUrl();
                                textToSend.visible = false;
                                textToReceive.visible = false;
                            } else {
                                errorMessage.text = "Failed to read binary file";
                                errorDialog.visible = true;
                            }
                        } else {
                            if (portManager.readFromFile() == "Success") {
                                textToSend.text = portManager.getInput();
                                textToSend.readOnly = true;
                                textToReceive.readOnly = true;
                            } else {
                                errorMessage.text = "Failed to read text file";
                                errorDialog.visible = true;
                            }
                        }
                        selectedFile.text = portManager.getPath();
                    }
                }

                RowLayout {
                    spacing: 1
                    CheckBox {
                        id: isBinary
                        Layout.alignment: Qt.AlignVCenter
                        implicitWidth: 30
                        implicitHeight: 30
                    }
                    Text {
                        text: "binary file"
                        font.pixelSize: 18
                        color: "white"
                        verticalAlignment: Text.AlignVCenter
                    }
                }


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
                    Layout.alignment: Qt.AlignVCenter
                    onClicked: {
                        portManager.closeSerialPort();
                        Qt.quit()
                    }
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#282c34"
            radius: 10

            RowLayout {
                anchors.fill: parent
                spacing: 10
                anchors.margins: 10

                Rectangle {
                    color: "#333742"
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    radius: 10
                    TextArea {
                        id: textToSend
                        anchors.fill: parent
                        color: "black"
                        focus: true
                        font.pixelSize: 20
                        wrapMode: TextArea.Wrap
                        visible: true
                        padding: 10
                    }

                    Image {
                        id: imageToSend
                        anchors.fill: parent
                        visible: false
                    }
                }

                Rectangle {
                    color: "#333742"
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    radius: 10

                    TextArea {
                        id: textToReceive
                        anchors.fill: parent
                        color: "black"
                        focus: true
                        font.pixelSize: 20
                        wrapMode: TextArea.Wrap
                        visible: true
                        padding: 10

                    }

                    Image {
                        id: imageToReceive
                        anchors.fill: parent
                        visible: false
                    }
                }
            }
        }

        RowLayout {
            spacing: 20
            Layout.alignment: Qt.AlignHCenter

            Button {
                text: "Send"
                font.pixelSize: 20
                onClicked: {
                    if (selectedFile.text != "No file selected") {
                        if (!isBinary.checked) {
                            if (portManager.writeSerialPort() == "Success") {
                                if (portManager.readSerialPort() == "Success") {
                                    textToReceive.text = portManager.getBuffer();
                                }
                            } else {
                                errorMessage.text = "Error writing to serial port";
                                errorDialog.visible = true;
                            }
                        } else {
                            if (portManager.writeSerialPortBinary() == "Success") {
                                if (portManager.readSerialPortBinary() == "Success") {
                                    portManager.convertToImage();
                                    imageToReceive.source = portManager.getImageOutputUrl();
                                }
                            } else {
                                errorMessage.text = "Error writing binary to serial port";
                                errorDialog.visible = true;
                            }
                        }
                    } else {
                        portManager.setInput(textToSend.text);
                        if (portManager.writeSerialPort() == "Success") {
                            if (portManager.readSerialPort() == "Success") {
                                textToReceive.text = portManager.getBuffer();
                            }
                        } else {
                            errorMessage.text = "Error writing to serial port";
                            errorDialog.visible = true;
                        }
                    }
                }
            }

            Button {
                text: "Clear"
                font.pixelSize: 20
                onClicked: {
                    textToSend.text = "";
                    textToSend.readOnly = false;
                    textToSend.visible = true;
                    textToReceive.visible = true;
                    textToReceive.readOnly = false;
                    textToReceive.text = "";
                    imageToSend.visible = false;
                    imageToSend.source = "";
                    imageToReceive.visible = false;
                    imageToReceive.source = "";
                    selectedFile.text = "No file selected";
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
