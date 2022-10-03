import QtQuick
import QtQuick.Controls 2.5

import extren 0.1

Window {
    id: mainwindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ExternFunc{
        id: externfunc
    }

    Button {
            text: "Ok"
            onClicked: mainwindow.color = "red"
        }
}
