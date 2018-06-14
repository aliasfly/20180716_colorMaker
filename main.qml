import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.3

Rectangle {
    width: 640;
    height: 480;
    Text {                          //test to display
        id: txtLabel;
        anchors.centerIn: parent;
        font.pixelSize: 26;
        color: "red";
    }
    Rectangle{
            id:waikuang;
            width: 600;
            height: 450;
            anchors.top:parent.top;
            anchors.topMargin: 15;
            anchors.left: parent.left;
            anchors.leftMargin: 20;
            border.width: 1.5;
            border.color: "#888888";

            Button{                                            //OK
                id:openfile;
                anchors.top:waikuang.top;
                anchors.topMargin: 5;
                text:"open";
                anchors.left: waikuang.left;
                anchors.leftMargin: 5;
                onClicked: fileDialog.open();
            }

            FileDialog {                                       //OK
                id: fileDialog
                title: "Please choose a file"
                folder: shortcuts.home
                onAccepted: {
                    console.log("You chose: " + fileDialog.fileUrl);
                    colorMaker.ReadFile();
                    console.log("read  OK!!!");
                }
                onRejected: {
                    console.log("Canceled")
                }
            }


            Button{                                     //OK
                id:rangemake;
                anchors.top:waikuang.top;
                anchors.topMargin: 5;
                text:"make";
                anchors.left: openfile.right;
                anchors.leftMargin: 5;
                onClicked:
                {
                   messageDialog.open();
                   inputWindow.visible=true;
                }
            }
            MessageDialog {                             //OK
                id: messageDialog;
                title: "range A-B";
                text: "enter number:";
                onAccepted: {
                    console.log("messageDialog.show up.");
                    //put handle function;or connected function;
                    colorMaker.ProduceRange();
                }
                Component.onCompleted: visible = false
            }


            Button{                                    //OK
                id:xmlout;
                anchors.top:waikuang.top;
                anchors.topMargin: 5;
                text:"export"
                anchors.left: rangemake.right;
                anchors.leftMargin: 5;
                onClicked:{
                    console.log("writeXML start");
                    colorMaker.writeXML();
                    console.log("writeXML end");
                }
            }

            Rectangle{                               //input window;
                id:inputWindow;
                visible: false;
                width: 300;
                height: 150;
                anchors.centerIn: waikuang;
                border.color: "#888888";
                border.width: 1.5;
                z:2;
                Button{
                    id:inputWindowOk;
                    anchors.right:inputWindow.right;
                    anchors.rightMargin: 3;
                    anchors.bottom: inputWindow.bottom;
                    anchors.bottomMargin: 3;
                    text:"Ok"
                    onClicked: {

                    }
                }
                Button{
                    id:inputWindowCancel;
                    anchors.right:inputWindowOk.left;
                    anchors.rightMargin: 2;
                    anchors.bottom: inputWindow.bottom;
                    anchors.bottomMargin: 3;
                    text:"Cancel"
                    onClicked: {

                    }
                }
                Text{
                    id:inputWindowLine1;
                    text:"AAA<=20:";
                    font.pixelSize: 24;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindow.top;
                    anchors.topMargin: 6;
                    TextInput{
                        id:textInputLine1;
                        width: 100;
                        height: 50;
                        font.pixelSize: 24;
                        anchors.left:inputWindowLine1.right;
                        validator: IntValidator{top:20; bottom: 1;}
                        color: "red";
                    }
                }
                Text{
                    id:inputWindowLine2;
                    text:"BBB<=30:";
                    font.pixelSize: 24;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindowLine1.bottom;
                    anchors.topMargin: 6;
                    TextInput{
                        id:textInputLine2;
                        width: 100;
                        height: 50;
                        font.pixelSize: 24;
                        anchors.left:inputWindowLine2.right;
                        validator: IntValidator{top:30; bottom: 1;}
                        color: "red";
                    }
                }
                Text{
                    id:inputWindowLine3;
                    text:"CCC<=40:";
                    font.pixelSize: 24;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindowLine2.bottom;
                    anchors.topMargin: 6;
                    TextInput{
                        id:textInputLine3;
                        width: 100;
                        height: 50;
                        font.pixelSize: 24;
                        anchors.left:inputWindowLine3.right;
                        validator: IntValidator{top:40; bottom: 1;}
                        color: "red";
                    }
                }
            }


            Rectangle{
                id:display;
                width: 590;
                height: 90;
                anchors.bottom: waikuang.bottom;
                anchors.bottomMargin: 5;
                anchors.left: waikuang.left;
                anchors.leftMargin: 5;
                border.width: 1.5;
                border.color: "#888888";
            }

            Rectangle{
                id:plot;
                width: 590;
                height: 300;
                anchors.left: waikuang.left;
                anchors.leftMargin: 5;
                anchors.bottom:display.top;
                anchors.bottomMargin: 5;
                border.width: 1.5;
                border.color: "#888888";
            }

            Rectangle{
                id:rcnumid;
                width:135;
                height: 80;
                border.width: 1.5;
                border.color: "#888888";
                anchors.left:display.left;
                anchors.leftMargin: 15;
                anchors.top:display.top;
                anchors.topMargin: 5;
                Text{
                    id: numid;
                    anchors.left: rcnumid.left;
                    anchors.leftMargin: 5;
                    text: "num:";
                    font.pixelSize: 20;
                }
            }

            Rectangle{
                id:rcavgid;
                width:135;
                height: 80;
                border.width: 1.5;
                border.color: "#888888";
                anchors.left:rcnumid.right;
                anchors.leftMargin: 5;
                anchors.top:display.top;
                anchors.topMargin: 5;
                Text{
                    id: avgid;
                    anchors.left: rcavgid.left;
                    anchors.leftMargin: 5;
                    text:"avg:";
                    font.pixelSize: 20;
                }

            }

            Rectangle{
                id:rcmaxid;
                width:135;
                height: 80;
                border.width: 1.5;
                border.color: "#888888";
                anchors.left:rcavgid.right;
                anchors.leftMargin: 5;
                anchors.top:display.top;
                anchors.topMargin: 5;
                Text{
                    id: maxid;
                    anchors.left: rcmaxid.left;
                    anchors.leftMargin: 5;
                    text: "max:";
                    font.pixelSize: 20;
                }
            }

            Rectangle{
                id:rcminid;
                width:135;
                height: 80;
                border.width: 1.5;
                border.color: "#888888";
                anchors.left:rcmaxid.right;
                anchors.leftMargin: 5;
                anchors.top:display.top;
                anchors.topMargin: 5;
                Text{
                    id: minid;
                    anchors.left: rcminid.left;
                    anchors.leftMargin: 5;
                    text: "min:";
                    font.pixelSize: 20;
                }
            }
        }





















//    Text {
//        id: timeLabel;
//        anchors.right: parent.right;
//        anchors.rightMargin: 4;
//        anchors.top: parent.top;
//        anchors.topMargin: 4;
//        font.pixelSize: 26;
//    }

//    Rectangle {
//        id: colorRect;
//        anchors.centerIn: parent;
//        width: 200;
//        height: 200;
//        color: "red";
//    }

//    Button {
//        id: start;
//        text: "start";
//        anchors.left: parent.left;
//        anchors.leftMargin: 4;
//        anchors.bottom: parent.bottom;
//        anchors.bottomMargin: 4;
//        onClicked: {
//            colorMaker.start();
//        }
//    }
//    Button {
//        id: stop;
//        text: "stop";
//        anchors.left: start.right;
//        anchors.leftMargin: 4;
//        anchors.bottom: start.bottom;
//        onClicked: {
//            colorMaker.stop();
//        }
//    }

//    function changeAlgorithm(button, algorithm){       //give next to use
//        switch(algorithm)
//        {
//        case 0:
//            button.text = "RandomRGB0";
//            break;
//        case 1:
//            button.text = "RandomRed1";
//            break;
//        case 2:
//            button.text = "RandomGreen2";
//            break;
//        case 3:
//            button.text = "RandomBlue3";
//            break;
//        case 4:
//            button.text = "LinearIncrease4";
//            break;
//        }
//    }

//    Button {
//        id: colorAlgorithm;
//        text: "RandomRGB";
//        anchors.left: stop.right;
//        anchors.leftMargin: 4;
//        anchors.bottom: start.bottom;
//        onClicked: {
//            var algorithm = (colorMaker.algorithm() + 1) % 5;
//            changeAlgorithm(colorAlgorithm, algorithm);    //use up function
//            colorMaker.setAlgorithm(algorithm);
//        }
//    }

//    Button {
//        id: quit;
//        text: "quit";
//        anchors.left: colorAlgorithm.right;
//        anchors.leftMargin: 4;
//        anchors.bottom: start.bottom;
//        onClicked: {
//            Qt.quit();
//        }
//    }

//    Component.onCompleted: {
//        colorMaker.color = Qt.rgba(0,180,120, 255);
//        //[3]
//        //colorMaker.setAlgorithm(ColorMaker.LinearIncrease);
//        colorMaker.setAlgorithm(colorMaker.RandomRGB);
//        changeAlgorithm(colorAlgorithm, colorMaker.algorithm());
//    }

//    Connections {
//        target: colorMaker;
//        onCurrentTime:{
//            timeLabel.text = strTime;
//            timeLabel.color = colorMaker.timeColor;
//        }
//    }

//    Connections {
//        target: colorMaker;
//        onColorChanged:{
//            colorRect.color = color;
//        }
//    }
}
