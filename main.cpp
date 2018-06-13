#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml>
#include "colorMaker.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView viewer;
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);//default
    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));//quit_use
    viewer.rootContext()->setContextProperty("colorMaker", new ColorMaker);
    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.show();

    return app.exec();
}
