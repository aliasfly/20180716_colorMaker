#include <QApplication>
#include <QQuickView>
#include <QtQml>
#include "dataStore.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQuickView viewer;


    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));//quit_use

    viewer.rootContext()->setContextProperty("dataStore", new DataStore);

    qmlRegisterType<DataStore>("DataStore", 1, 0, "DataStore");

    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);//default
    viewer.show();

    return app.exec();
}
