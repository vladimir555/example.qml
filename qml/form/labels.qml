import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Universal 2.2
import QtQuick.Layouts 1.3


Item {
    function updateFormLabelsState(button_states) {
        var is_visible_any = false;

        for (var i = 0; i < labels.count; i++) {
            is_visible_any = is_visible_any | button_states[i]
            labels.itemAt(i).visible = button_states[i]
        }

        console.log(button_states)
    }

    id: window_label
    objectName: "window_labels"

    width: 400
    height: 350

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

        Item {
            Layout.columnSpan: parent.columns
            height: 5
        }

        Repeater {
            id: labels
            model: [1, 2, 3, 4, 5, 6]
            delegate: Label {
                Layout.alignment: Qt.AlignCenter
                visible: true
                text: qsTr("Label_" + modelData)
            }
        }
    }
}
