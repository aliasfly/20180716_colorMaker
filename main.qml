import QtQuick 2.2
import QtCharts 2.2
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.3
import DataStore 1.0

Rectangle {
    id:rect
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
        id: textlabelR
        anchors.top:colorRect.bottom
        anchors.topMargin: 20
        anchors.left: rect.left
        anchors.leftMargin: 90
        font.pixelSize: 40
        text:"R:0"
    }
    Text {
        id: textlabelG
        anchors.top:colorRect.bottom
        anchors.topMargin: 20
        anchors.left: textlabelR.right
        anchors.leftMargin: 50
        font.pixelSize: 40
        text:"G:0"
    }
    Text {
        id: textlabelB
        anchors.top:colorRect.bottom
        anchors.topMargin: 20
        anchors.left: textlabelG.right
        anchors.leftMargin: 50
        font.pixelSize: 40
        text:"B:0"
    }
    Slider {
        id:sliderR
        width: 300
        height: 30
        stepSize: 1
        value: 0
        minimumValue: 0
        maximumValue:255
        anchors.top: textlabelR.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onValueChanged:
        {
            textlabelR.text="R:"+value
            dataStore.dealcolorR(value)
            colorRect.color=Qt.rgba(dataStore.colorNumR,dataStore.colorNumG,dataStore.colorNumB,1)
        }
    }
    Slider {
        id:sliderG
        width: 300
        height: 30
        stepSize: 1
        value: 0
        minimumValue: 0
        maximumValue:255
        anchors.top: sliderR.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onValueChanged:
        {
            textlabelG.text="G:"+value
            dataStore.dealcolorG(value)
            colorRect.color=Qt.rgba(dataStore.colorNumR,dataStore.colorNumG,dataStore.colorNumB,1)
        }
    }
    Slider {
        id:sliderB
        width: 300
        height: 30
        stepSize: 1
        value: 0
        minimumValue: 0
        maximumValue:255
        anchors.top: sliderG.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onValueChanged:
        {
            textlabelB.text="B:"+value
            dataStore.dealcolorB(value)
            colorRect.color=Qt.rgba(dataStore.colorNumR,dataStore.colorNumG,dataStore.colorNumB,1)
        }
    }
}
