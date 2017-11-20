import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtMultimedia 5.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtGraphicalEffects 1.0
import Qt.labs.settings 1.0

import QZXing 2.3
import "qml"

ApplicationWindow
{
    id: mainwindows
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight
    title: "QUẢN LÝ VĂN PHÒNG PHẨM"
    visible: true
    property string current_address: ""
    property double size_width  : Screen.desktopAvailableWidth/480
    property double size_height  : Screen.desktopAvailableHeight/720
    property double size_scale: (size_width + size_height) / 2
    property string current_user: ""
    property string current_password: ""
    property string current_password_change: ""
    property bool open_status: false
    property bool access_status: false

    property bool busystatus: false
    property int count_t: 0

    signal logout();

    Settings {
        id: settings
        property string style: "Material"
    }
    QRcodeScanner{
        id: qrScanAddress
    }
    DashBoard{
        id: dashboard
    }
    ChangePass{
        id: changepass
    }

    Shortcut {
        sequences: ["Esc", "Back"]
        enabled: stackView.depth > 1
        onActivated: {
            stackView.pop()
        }
    }

    Connections {
        target: _bleMgr
        onBackMainPage: {
            console.log('onBackMainPage');
//            stackView.pop();
//            stackView.push(dashboard);
        }
    }

    header: ToolBar {
        Material.foreground: "white"

        height: 70 *size_height
        Rectangle{
            anchors.fill: parent
            color: "#EF6C00"
            Label {
                id: titleLabel
                text:  "QUẢN LÝ VĂN PHÒNG PHẨM"
                color: "white"
                font.pixelSize: 20 *size_scale
                elide: Label.ElideRight
                anchors.centerIn: parent

            }
        }

        RowLayout {
            spacing: 20 *size_width
            anchors.fill: parent
            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad

                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: stackView.depth > 2 ? "images/back.png" : ""
                }
                onClicked: {
                    if (stackView.depth > 2) {
                        stackView.pop()

                    } else {

                    }
                }
            }
        }

    }
    StackView {
        id: stackView
        anchors.fill: parent
        focus: true
        Keys.onReleased: {

        }

        initialItem: LoginPopup{

        }

    }
    PopupMsg{
        id: msgid
        modal: true
        focus: true

        x: (stackView.width - width) / 2
        y: Math.abs(stackView.height -  msgid.height)/2


        closePolicy: Popup.NoAutoClose

    }

   Connections{
       target: _httpClient
       onLogin_status:{
          if(_status == 0){
              stackView.push(dashboard)
              _bleMgr.init()
          } else if(_status === 10) {
              console.log("Network Error.")
              msgid.msg = "Mạng không ổn định.";
              msgid.open()
          }
          else {
              console.log("login dont success")
              msgid.msg = "        Đăng nhập không thành công \n Vui lòng kiểm tra lại tài khoản và mật khẩu";
              msgid.open()
          }
          busystatus = false
       }
       onAccess_status:{
          access_status = true
          if(_status == 0){
                console.log("access to open the door", current_address)
                _bleMgr.advertise(current_address);
          }
          else{
              console.log("DO NOT access to open the door", current_address)
              msgid.msg = "Tài khoản không được cấp quyền mở cửa";
              msgid.open()
          }
          busystatus = false
       }
       onChangePass_status:{
           if(_status == 0){
               stackView.pop()
               msgid.msg = "Thay đổi mật khẩu thành công";
               msgid.open();
           }
           else{
               msgid.msg = "Thay đổi mật khẩu không thành công";
               msgid.open();
           }
       }
   }
   BusyIndicator {
       id: busylogin
       anchors.centerIn: parent

       running: busystatus
   }

   Timer{
       id: timerstop
       running: true
       interval: 15000
       repeat: false
       onTriggered: {

       }
   }

   onClosing: {

   }
}
