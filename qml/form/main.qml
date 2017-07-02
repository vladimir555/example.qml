import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.2
import QtQuick.Controls.Universal 2.2
import QtQuick.Layouts 1.3


ApplicationWindow {
    Material.theme: Material.Dark

    id: window

    width: 300
    height: 100

    minimumWidth: 200
    minimumHeight: 100

    visible: true
    visibility: "AutomaticVisibility"

    GridLayout {
        columns: 2

        rowSpacing: 20
        columnSpacing: 20

        anchors.horizontalCenter: window.horizontalCenter
        anchors.topMargin: 32
        anchors.bottomMargin: 32
        anchors.leftMargin: 32
        anchors.rightMargin: 32

        anchors.left: parent.left
        anchors.right: parent.right

        Label {
            id: label_password
            text: qsTr("Password:")
        }

        TextInput {
            text: "Hello";
            echoMode: TextInput.Password
            anchors.right: parent.right
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            id: button_ok
            Text {
                id: button_ok_label
                text: qsTr("OK")
                anchors.centerIn: parent
            }
        }
    }
}
