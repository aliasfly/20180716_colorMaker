#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml>
#include "colorMaker.h"
#include "dataStore.h"
#include "dataPlot.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView viewer;
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);//default
    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));//quit_use
    viewer.rootContext()->setContextProperty("colorMaker", new ColorMaker);
    viewer.rootContext()->setContextProperty("dataStore", new DataStore);
    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.show();

    return app.exec();
}
