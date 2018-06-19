#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QtQml>
#include "colorMaker.h"
#include "dataStore.h"
#include "dataPlot.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQuickView viewer;

#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    viewer.engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                                      QString::fromLatin1("qml")));

    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));//quit_use
    viewer.rootContext()->setContextProperty("colorMaker", new ColorMaker);
    viewer.rootContext()->setContextProperty("dataStore", new DataStore);
    viewer.rootContext()->setContextProperty("dataPlot", new DataPlot);
    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);//default
    viewer.show();

    return app.exec();
}
