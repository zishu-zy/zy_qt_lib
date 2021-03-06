/*
 * ==============================================================
 *
 *       FileName: tablemodel_custom.hpp
 *    Description: 配套自定义tableview的自定义model
 *
 *         Author: zishu, zishuzy@qq.com
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
    void setDataList(QList<DataType> &datalist);

private:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index,
                          int role = Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value,
                         int role);

    QVariant getData(int nRow, int nClolumn) const;

private:
    QList<DataType> *m_pListDatas;
    QStringList m_strHeaders;
    mutable QMutex m_mutex;
};

#include "tablemodel_custom.cpp"

#endif // TABLEMODEL_CUSTOM_H_
