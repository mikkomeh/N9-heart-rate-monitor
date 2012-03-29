#ifndef HISTORYMODEL_H
#define HISTORYMODEL_H

#include "heartratemeasurement.h"

#include <QAbstractListModel>
#include <QList>

/**
 *Contains all stored measurements.
*/
class HistoryModel : public QAbstractListModel
{
    Q_OBJECT

public:
    HistoryModel(QObject *parent = 0);
    virtual ~HistoryModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void setData(QList<HeartRateMeasurement> data);

    enum Roles {
        TimeRole = Qt::UserRole + 1,
        HeartRateRole
    };

public slots:
    void append(const HeartRateMeasurement &measurement);
    void append(const QDateTime &time, int value);

private:
    Q_DISABLE_COPY(HistoryModel)
    QList<HeartRateMeasurement> m_data;
};

#endif // HISTORYMODEL_H
