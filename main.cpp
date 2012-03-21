#include "heartratemonitor.h"

#include <QtDeclarative>
#include <QApplication>
#include "qmlapplicationviewer.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    HeartRateMonitor monitor;
    QmlApplicationViewer viewer;
    QDeclarativeContext *ctxt = viewer.rootContext();
    ctxt->setContextProperty("monitor", &monitor);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/N9heartratemonitor/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
