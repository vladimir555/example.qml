import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Universal 2.2
import QtQuick.Layouts 1.3


Item {
    function updateFormButtonsState(buttons_state) {
        var is_visible_any = false;

        for (var i = 0; i < buttons.count; i++) {
            is_visible_any = is_visible_any | buttons_state[i]
            buttons.itemAt(i).visible = buttons_state[i]
        }

        button_new.visible = is_visible_any

        console.log(buttons_state)
    }

    id: window_main
    objectName: "window_main"

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

        TextField {
            id: text_field_password
            objectName: "password"
            implicitWidth: 150
            maximumLength: 10
            echoMode: TextInput.Password
            Layout.alignment: Qt.AlignCenter
        }

        Button {
            id: button_enter
            implicitWidth: 150
            Layout.alignment: Qt.AlignCenter
            onClicked: form.onButtonEnterClicked()
            text: qsTr("Enter")
        }

        Repeater {
            id: buttons
            model: form.buttons_name

            delegate: Button {
                id: button
                implicitWidth: 150
                Layout.alignment: Qt.AlignCenter
                visible: false
                text: qsTr(modelData)
            }
        }

        Button {
            id: button_new
            implicitWidth: 150
            Layout.columnSpan: parent.columns
            anchors.horizontalCenter: parent.horizontalCenter
            visible: false
            text: qsTr("New window")
            onClicked: {
                form.onButtonNewWindowClicked()
                console.log(form.buttons_state)
            }
        }
    }
}
