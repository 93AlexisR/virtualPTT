import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 500
    height: 350
    color: qsTr("#ffffff")
    title: qsTr("virtualPTT")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Button {
        id: button1
        x: 187
        y: 247
        width: 126
        height: 59
        text: qsTr("Calibrate")
        checkable: false
    }

    ComboBox {
        id: comboBox1
        x: 34
        y: 212
        activeFocusOnPress: true
    }

    Label {
        id: label1
        x: 34
        y: 187
        text: "Activation Threshold"
    }

    Text {
        id: text1
        x: 198
        y: 188
        text: qsTr("Current PTT Key")
        font.pixelSize: 12
    }

    TextInput {
        id: textInput1
        x: 362
        y: 187
        width: 80
        height: 20
        text: qsTr("Current Mute Key")
        font.pixelSize: 12
    }

    FocusScope {
        id: focusScope1
        x: 187
        y: 203
        width: 126
        height: 31


        Text {
            id: text2
            x: 8
            y: 9
            width: 36
            height: 14
            text: qsTr("~")
            font.pixelSize: 12
        }
    }

    FocusScope {
        id: focusScope2
        x: 346
        y: 203
        width: 126
        height: 31

        Text {
            id: text3
            x: 8
            y: 9
            text: qsTr("F5")
            font.pixelSize: 12
        }
    }

    CheckBox {
        id: checkBox1
        x: 224
        y: 324
        text: qsTr("Enable mute/unmute when Enter is pressed")
    }

    Text {
        id: text4
        x: 42
        y: 58
        width: 312
        height: 45
        text: qsTr("Status: ")
        font.pixelSize: 19
    }
}
