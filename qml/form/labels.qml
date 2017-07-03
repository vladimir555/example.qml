import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.2
import QtQuick.Controls.Universal 2.2
import QtQuick.Layouts 1.3


ApplicationWindow {
    Material.theme: Material.Dark

    title: "example.qml"

    id: window_label

    minimumWidth: 400
    minimumHeight: 150

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

        Repeater {
            model: [1, 2, 3, 4, 5, 6]
            delegate: Label {
                id: button
                width: 150
                Layout.alignment: Qt.AlignCenter
                visible: true
                Text {
                    color: "white"
                    text: qsTr("Label " + modelData)
                    anchors.centerIn: parent
                }
            }
        }
    }
}
