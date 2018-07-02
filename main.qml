import QtQuick 2.2
import QtCharts 2.2
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.3
import DataStore 1.0

Rectangle {
    width: 500;
    height: 600;
    Rectangle {
        id:colorRect
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200;
        height: 200;
        border.color: "#888888"
        color: Qt.rgba(0,0,0,1)            //color rgba(real red, real green, real blue, real alpha)
    }
    Text {
        id: textlabel
        anchors.top:colorRect.bottom
        anchors.margins: 20
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 40
        text:"0"
    }
    Slider {
        id:slider
        width: 300
        height: 30
        stepSize: 1
        value: 0
        minimumValue: 0
        maximumValue:255
        anchors.top: textlabel.bottom
        anchors.margins: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onValueChanged:
        {
            textlabel.text=value
            colorRect.color=Qt.rgba(value/255,0,0,1)
        }
    }
    Button {
        width: 50
        height: 30
        anchors.top:slider.bottom
        anchors.margins: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            dataStore.dealcolor()
        }
    }
}
