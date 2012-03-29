#include "historymodel.h"

#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QHash>
#include <QDebug>

HistoryModel::HistoryModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // Set role names to access data from QML
    QHash<int, QByteArray> roles;
    roles[TimeRole] = "time";
    roles[HeartRateRole] = "heartRate";
    setRoleNames(roles);

    // Read info file if is exists
    QFile historyFile("/home/user/MyDocs/heartrate.csv");
    if (historyFile.exists() && historyFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&historyFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = line.split(" ");
            if (values.length() > 1) {
                QDateTime time = QDateTime::fromString(values[0], Qt::ISODate);
                int value = values[1].toInt();
                HeartRateMeasurement measurement(time, value);
                m_data.append(measurement);
            }
        }
        historyFile.close();
    }
}

HistoryModel::~HistoryModel()
{
}

int HistoryModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant HistoryModel::data(const QModelIndex &index, int role) const
{
     if (index.row() < 0 || index.row() > m_data.count()) {
         return QVariant();
     }

     switch (role) {
     case TimeRole:
         return m_data[index.row()].time();
     case HeartRateRole:
         return m_data[index.row()].value();
     default:
         return QVariant();
     }
}

void HistoryModel::setData(QList<HeartRateMeasurement> data)
{
    m_data = data;
}

void HistoryModel::append(const QDateTime &time, int value)
{
    HeartRateMeasurement measurement(time, value);
    append(measurement);
}

void HistoryModel::append(const HeartRateMeasurement &measurement)
{
    qDebug() << __PRETTY_FUNCTION__;

    m_data.append(measurement);

    // Read info file if is exists
    QFile historyFile("/home/user/MyDocs/heartrate.csv");
    if (historyFile.open(QIODevice::Append)) {
        historyFile.write(measurement.time().toString(Qt::ISODate).toUtf8().constData());
        historyFile.write(" ");
        const QString value = QString("%1").arg(measurement.value());
        historyFile.write(value.toUtf8().constData());
        historyFile.write("\n");
        historyFile.close();
    }
}
