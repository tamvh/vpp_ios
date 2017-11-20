import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1
import QtGraphicalEffects 1.0

Popup {
    id: root
    property string msg: ""
    width:  chil.width
    height: chil.height
    Rectangle{
        id: chil
        anchors.centerIn: parent
        width: msgtext.width + 150 *size_width
        height: 200 *size_height
        Text {
            id: msgtext
            text: qsTr(msg)
            font.pixelSize: 23 *size_scale
            anchors.top: parent.top; anchors.topMargin: 50 *size_height
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Button{
            id: okbt
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom:  parent.bottom; anchors.bottomMargin: 10 *size_height

            text: "OK"
            highlighted: true
            width: 150 *size_width
            Material.accent: Material.Orange
            onClicked: {
                   root.close();
            }
        }
    }
}
