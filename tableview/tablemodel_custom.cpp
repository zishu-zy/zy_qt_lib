/*
 * ==============================================================
 *
 *       FileName: tablemodel_custom.cpp
 *    Description: 配套自定义tableview的自定义model
 *
 *         Author: zhaiyu, zhaiyu@qianxin.com
 *        Created: 2019-10-12 13:48:15
 *  Last Modified: 2019-10-22 13:44:46
 *
 * ==============================================================
 */

#include "tablemodel_custom.hpp"
#include <QToolTip>

template <typename DataType>
TableModelCustom<DataType>::TableModelCustom(QObject *parent)
    : QAbstractTableModel(parent),m_pListDatas(NULL)
{
    m_pListDatas = new QList<DataType>;
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
void TableModelCustom<DataType>::setDataList(QList<DataType> &datalist)
{
    beginResetModel();
    if(m_pListDatas != NULL) {
        delete m_pListDatas;
    }
    m_pListDatas = &datalist;
    endResetModel();
}

template <typename DataType>
int TableModelCustom<DataType>::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    return m_pListDatas->size();
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
    return QVariant();
}

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
    if (m_pListDatas->empty() || nClolumn > m_strHeaders.size() ||
        nRow > m_pListDatas->size() - 1) {
        m_mutex.unlock();
        return QVariant();
    }
    DataType item = m_pListDatas->at(nRow);
    m_mutex.unlock();
    return item.getData(nClolumn);
}

template <typename DataType>
bool TableModelCustom<DataType>::setData(const QModelIndex &index,
                                         const QVariant &value, int role)
{
    (void)role;
    if (!index.isValid())
        return false;
    (*m_pListDatas)[index.row()].setData(index.column(), value);
    return true;
}
