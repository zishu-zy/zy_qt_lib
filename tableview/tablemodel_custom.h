/*
 * ==============================================================
 *
 *       FileName: tablemodel_custom.h
 *    Description:
 *
 *         Author: zhaiyu, zhaiyu@qianxin.com
 *        Created: 2019-10-12 13:48:15
 *  Last Modified: 2019-10-14 14:21:39
 *
 * ==============================================================
 */

#ifndef TABLEMODEL_CUSTOM_H_
#define TABLEMODEL_CUSTOM_H_

#include <QAbstractTableModel>
#include <QMutex>
#include <QObject>
#include <QStringList>

template <typename DataType>
class TableModelCustom : public QAbstractTableModel
{
public:
    explicit TableModelCustom(QObject *parent = NULL);
    virtual ~TableModelCustom();

    void setHeaders(const QStringList &headerlist);
    void setDataList(const QList<DataType> &datalist);

private:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index,
                          int role = Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role) const;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value,
                         int role);

    QVariant getData(int nRow, int nClolumn) const;
    // QVariant getChecked(int nRow, int nClolumn) const;

private:
    QList<DataType> m_ListDatas;
    QStringList m_strHeaders;
    mutable QMutex m_mutex;
};

#include "tablemodel_custom.cpp"

#endif // TABLEMODEL_CUSTOM_H_
