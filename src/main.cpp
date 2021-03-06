#include "heartratemonitor.h"
#include "chartprovider.h"
#include "historymodel.h"
#include "heartratemeasurement.h"

#include <QtDeclarative>
#include <QApplication>
#include "qmlapplicationviewer.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    HeartRateMonitor monitor;
    HistoryModel history;
    QmlApplicationViewer viewer;
    QDeclarativeContext *ctxt = viewer.rootContext();
    ctxt->setContextProperty("monitor", &monitor);
    ctxt->setContextProperty("history", &history);

    qmlRegisterType<HeartRateMeasurement>("HeartRateLibrary", 1, 0, "HeartRateMeasurement");

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
    viewer.engine()->addImageProvider(QLatin1String("chart"),
                                      new ChartProvider(QDeclarativeImageProvider::Image, monitor));
    viewer.setSource(QUrl("qrc:/qml/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
