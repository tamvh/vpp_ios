import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import QtGraphicalEffects 1.0

Component{
    Page {
        id: root
         Column {
            id: appOptionColumn
            spacing: 30 *size_height
            anchors.centerIn: parent

            Label {
                text: "Đổi mật khẩu"
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
                color: "#EF6C00"
                font.pixelSize: 20 * size_scale//fntsize + 4
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                Label {
                    anchors.verticalCenter: parent.verticalCenter
                    width: 80 * size_width
                    text: "MK cũ: "
                }

                TextField {
                    id: idOldpass
                    width: 250 * size_width
                    text: ""
                    echoMode: TextInput.Password
                    onDisplayTextChanged: loginErrorMsg.text = ""
                }
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                Label {
                    anchors.verticalCenter: parent.verticalCenter
                    width: 80 * size_width
                    text: "MK mới: "
                }

                TextField {
                    id: idNewpass
                    width: 250 * size_width
                    text: ""//mainController.isDebugmode() ? mainController.getConfigUserpwd() : ""
                    echoMode: TextInput.Password
                    onDisplayTextChanged: loginErrorMsg.text = ""
                }
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                Label {
                    anchors.verticalCenter: parent.verticalCenter
                    width: 80 * size_width
                    text: "MK mới: "
                }

                TextField {
                    id: idNewpass2
                    width: 250 * size_width
                    text: ""//mainController.isDebugmode() ? mainController.getConfigUserpwd() : ""
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
                anchors.horizontalCenter: parent.horizontalCenter

                Button {
                    id: okButton
                    text: "Đồng ý"
                    width: 150 * size_width
                    height: 70 *size_height
                    highlighted: true
                    Material.accent: Material.Orange
                    onClicked: {
                        if(idOldpass.text === current_password ){
                            if(idNewpass.text == idNewpass2.text){
                                current_password_change = idNewpass.text;
                                _httpClient.change_password(current_user,current_password,current_password_change)
                                idNewpass.text = ""
                                idOldpass.text = ""
                                idNewpass2.text = ""
                            }
                            else {
                                idNewpass.text = ""
                                idNewpass2.text = ""
                                msgid.msg = "Nhập lại mật khẩu không đúng";
                                msgid.open();
                            }
                        }
                        else {
                            idNewpass.text = ""
                            idOldpass.text = ""
                            idNewpass2.text = ""
                            msgid.msg = "Mật khẩu cũ không đúng";
                            msgid.open();
                        }
                    }
                }

                Button {
                    id: cancelButton
                    text: "Hủy"
                    height: 70 *size_height
                    width: 150 * size_width
                    onClicked: {
                        stackView.pop()
                    }
                }
            }
        }

    }
}
