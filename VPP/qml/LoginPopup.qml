import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

Page {
    id: loginPage
    property alias username: iduser.text
    property alias password: idPassword.text

    onVisibleChanged: {
        if (visible) {

        }
    }

    Column {
        id: appOptionColumn
        anchors.centerIn: parent
        spacing: 35 *size_height
        Row {
            Label {
                anchors.verticalCenter: parent.verticalCenter
                width: 120 * size_width
                text: "Tài khoản: "
            }

            TextField {
                id: iduser
                width: 220 * size_width
                text: ""
                onDisplayTextChanged: loginErrorMsg.text = ""
            }
        }



        Row {
            Label {
                anchors.verticalCenter: parent.verticalCenter
                width: 120 * size_width
                text: "Mật khẩu: "
            }

            TextField {
                id: idPassword
                width: 220 * size_width
                text: ""
                echoMode: TextInput.Password
                onDisplayTextChanged: loginErrorMsg.text = ""
            }
        }

        Label {
            id: loginErrorMsg
            Layout.alignment: Qt.AlignHCenter
            text: " "
        }

        Row {
            spacing: 10 * size_width
            Layout.alignment: Qt.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: okButton
                text: "Đồng ý"
                width: 150 * size_width
                height: 70 *size_height
                Material.accent: Material.Orange
                highlighted: true
                onClicked: {
                    busystatus = true
                    _httpClient.login_to_server(iduser.text, idPassword.text)
                    current_user = iduser.text;
                    current_password = idPassword.text;
                }
            }

            Button {
                id: cancelButton
                text: "Hủy"
                height: 70 *size_height
                width: 150 * size_width
                onClicked: {
                    idPassword.text = ""
                    iduser.text = ""
                }
            }
        }
    }


    Timer{
        interval: 1
        repeat: false
        running: true
        onTriggered: {
        }
    }
    Connections{
        target: mainwindows
        onLogout:{
            idPassword.text = ""
            iduser.text = ""
            stackView.pop()
        }
    }

}
