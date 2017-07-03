import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.2
import QtQuick.Controls.Universal 2.2
import QtQuick.Layouts 1.3


ApplicationWindow {
    Material.theme: Material.Dark
    Material.foreground: Material.Light

    title: "example.qml"

    id: window_main

    minimumWidth: 400
    minimumHeight: 350

    visible: true


    GridLayout {
        columns: 2

        rowSpacing: 20
        columnSpacing: 20

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 32
        anchors.bottomMargin: 32
        anchors.leftMargin: 32
        anchors.rightMargin: 32

        anchors.left: parent.left
        anchors.right: parent.right

        TextField {
            color: "white"
            implicitWidth: 150
            maximumLength: 10
            echoMode: TextInput.Password
            Layout.alignment: Qt.AlignCenter
        }

        Button {
            id: button_enter
            implicitWidth: 150
            Layout.alignment: Qt.AlignCenter
            Text {
                color: "white"
                text: qsTr("Enter")
                anchors.centerIn: parent
            }
        }

        Repeater {
            model: [1, 2, 3, 4, 5, 6]
            delegate: Button {
                id: button
                implicitWidth: 150
                Layout.alignment: Qt.AlignCenter
                visible: true
                Text {
                    color: "white"
                    text: qsTr("Button " + modelData)
                    anchors.centerIn: parent
                }
            }
        }

        Button {
            id: button_new
            implicitWidth: 150
            Layout.columnSpan: 2
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                color: "white"
                text: qsTr("New window")
                anchors.centerIn: parent
            }
        }

    }
}
