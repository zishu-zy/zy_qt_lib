/*
 * ==============================================================
 *
 *       FileName: tablemodel_custom.cpp
 *    Description:
 *
 *         Author: zhaiyu, zhaiyu@qianxin.com
 *        Created: 2019-10-12 13:48:15
 *  Last Modified: 2019-10-15 13:34:28
 *
 * ==============================================================
 */

#include "tablemodel_custom.h"
#include <QToolTip>

template <typename DataType>
TableModelCustom<DataType>::TableModelCustom(QObject *parent)
    : QAbstractTableModel(parent)
{
}

template <typename DataType>
TableModelCustom<DataType>::~TableModelCustom()
{
}

template <typename DataType>
void TableModelCustom<DataType>::setHeaders(const QStringList &headerlist)
{
    m_strHeaders = headerlist;
}

template <typename DataType>
void TableModelCustom<DataType>::setDataList(const QList<DataType> &datalist)
{
    beginResetModel();
    m_ListDatas = datalist;
    endResetModel();
}

template <typename DataType>
int TableModelCustom<DataType>::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    return m_ListDatas.size();
}

template <typename DataType>
int TableModelCustom<DataType>::columnCount(const QModelIndex &parent) const
{
    (void)parent;
    return m_strHeaders.size();
}

template <typename DataType>
QVariant TableModelCustom<DataType>::data(const QModelIndex &index,
                                          int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    if (role == Qt::DisplayRole) {
        return getData(index.row(), index.column());
    } else if (Qt::UserRole == role) {
        return getData(index.row(), index.column());
    } else if (role == Qt::ToolTipRole) {
        if (index.column() == 0) {
            QString name = index.data(Qt::DisplayRole).toString();
            QToolTip::showText(QCursor::pos(), name);
            return QVariant();
            ;
        }
    }
    // if (role == Qt::CheckStateRole) {
    //     if (index.column() == 2) {
    //         return getChecked(index.row(), index.column()).toBool()
    //                    ? Qt::Checked
    //                    : Qt::Unchecked;
    //     }
    // }
    return QVariant();
}

// template <typename DataType>
// QVariant TableModelCustom<DataType>::getChecked(int nRow, int nClolumn) const
// {
//     m_mutex.lock();
//     if (nClolumn > m_strHeaders.size() || nRow > m_ListDatas.size() - 1) {
//         m_mutex.unlock();
//         return QVariant();
//     }
//     DataType item = m_ListDatas->at(nRow);
//     m_mutex.unlock();
//     return item.ischecked;
// }

template <typename DataType>
QVariant TableModelCustom<DataType>::headerData(int section,
                                                Qt::Orientation orientation,
                                                int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return m_strHeaders.at(section);
    } else {
        return QAbstractTableModel::headerData(section, orientation, role);
    }
}

template <typename DataType>
QVariant TableModelCustom<DataType>::getData(int nRow, int nClolumn) const
{
    m_mutex.lock();
    if (m_ListDatas.empty() || nClolumn > m_strHeaders.size() ||
        nRow > m_ListDatas.size() - 1) {
        m_mutex.unlock();
        return QVariant();
    }
    DataType item = m_ListDatas.at(nRow);
    m_mutex.unlock();
    return item.getData(nClolumn);
}

template <typename DataType>
Qt::ItemFlags TableModelCustom<DataType>::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    if (index.column() == 2) {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable |
               Qt::ItemIsUserCheckable;
    }

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

template <typename DataType>
bool TableModelCustom<DataType>::setData(const QModelIndex &index,
                                         const QVariant &value, int role)
{
    (void)role;
    if (!index.isValid())
        return false;
    m_ListDatas[index.row()].setData(index.column(), value);
    return true;
}
