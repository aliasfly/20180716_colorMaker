import QtQuick 2.2
import QtCharts 2.2
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.3
import DataStore 1.0

Rectangle {
    id:rect
    width: 500;
    height: 600;
    Button {
        id:button
        width: 100
        height: 30
        text: "Roll"
        anchors.top:parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: colorRect.horizontalCenter
        onClicked: {
            rectScoreText.text="Score:"
            colorRectRight.color=Qt.rgba(0,0,0,1)            //color rgba(real red, real green, real blue, real alpha)
            sliderR.value=0
            sliderG.value=0
            sliderB.value=0
            qml_dataStore.produceRand()
            colorRect.color=Qt.rgba(qml_dataStore.randColorNumR,qml_dataStore.randColorNumG,qml_dataStore.randColorNumB,1)
        }
    }
    Rectangle {
        id:colorRect
        anchors.top: button.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 40
        width: 200;
        height: 200;
        border.color: "#888888"
        color: Qt.rgba(0,0,0,1)            //color rgba(real red, real green, real blue, real alpha)
    }
    Rectangle {
        id:colorRectRight
        anchors.top: colorRect.top
        anchors.left: colorRect.right
        anchors.leftMargin: 30
        width: 200;
        height: 200;
        border.color: "#888888"
        color: Qt.rgba(0,0,0,1)            //color rgba(real red, real green, real blue, real alpha)
    }
    Button {
        id:buttonDown
        width: 100
        height: 30
        text: "Try"
        anchors.top:colorRectRight.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: colorRectRight.horizontalCenter
        onClicked: {
            qml_dataStore.calculateSquareError()
            rectScoreText.text="Score:"+qml_dataStore.squareError
        }
    }
    Slider {
        id:sliderR
        width: 200
        height: 20
        stepSize: 1
        value: 0
        minimumValue: 0
        maximumValue:255
        anchors.top: colorRect.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: colorRect.horizontalCenter
        onValueChanged:
        {
//            textlabelR.text="R:"+value
            qml_dataStore.dealcolorR(value)
            colorRectRight.color=Qt.rgba(qml_dataStore.colorNumR,qml_dataStore.colorNumG,qml_dataStore.colorNumB,1)
        }
    }
    Slider {
        id:sliderG
        width: 200
        height: 20
        stepSize: 1
        value: 0
        minimumValue: 0
        maximumValue:255
        anchors.top: sliderR.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: sliderR.horizontalCenter
        onValueChanged:
        {
//            textlabelG.text="G:"+value
            qml_dataStore.dealcolorG(value)
            colorRectRight.color=Qt.rgba(qml_dataStore.colorNumR,qml_dataStore.colorNumG,qml_dataStore.colorNumB,1)
        }
    }
    Slider {
        id:sliderB
        width: 200
        height: 20
        stepSize: 1
        value: 0
        minimumValue: 0
        maximumValue:255
        anchors.top: sliderG.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: sliderG.horizontalCenter
        onValueChanged:
        {
//            textlabelB.text="B:"+value
            qml_dataStore.dealcolorB(value)
            colorRectRight.color=Qt.rgba(qml_dataStore.colorNumR,qml_dataStore.colorNumG,qml_dataStore.colorNumB,1)
        }
    }
    Rectangle {
        id:rectScore
        width:430
        height: 60
        anchors.left: colorRect.left
        anchors.top:sliderB.bottom
        anchors.topMargin: 20
        border.color: "#888888"
        Text {
            id: rectScoreText
            text: "Score:"
            anchors.verticalCenter: rectScore.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 100
            font.pixelSize: 20
        }
    }
}
