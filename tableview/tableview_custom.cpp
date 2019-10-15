/*
 * ==============================================================
 *
 *       FileName: tableview_custom.cpp
 *    Description: 
 *
 *         Author: zhaiyu, zhaiyu@qianxin.com
 *        Created: 2019-10-12 13:48:15
 *  Last Modified: 2019-10-14 14:22:12
 *
 * ==============================================================
 */

#include "tableview_custom.h"
#include "item_delegate_btn.h"
#include <QDebug>

template <typename DataType>
TableViewCustom<DataType>::TableViewCustom(QWidget *parent) : QTableView(parent)
{

    m_pModel = new TableModelCustom<DataType>(this);
    this->setModel(m_pModel);

    // MyItemDelegate *pDelegate = new MyItemDelegate(this);
    // setItemDelegateForColumn(3,pDelegate);
}

template <typename DataType>
TableViewCustom<DataType>::~TableViewCustom()
{
    delete m_pModel;
    m_pModel = NULL;
}

template<typename DataType>
void TableViewCustom<DataType>::setHeaders(const QStringList &headerlist)
{
    m_pModel->setHeaders(headerlist);
}

template <typename DataType>
void TableViewCustom<DataType>::setDataList(const QList<DataType> &datalist)
{
    m_pModel->setDataList(datalist);
}

