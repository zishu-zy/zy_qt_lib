/*
 * ==============================================================
 *
 *       FileName: tableview_custom.cpp
 *    Description: 自定义tableview
 *
 *         Author: zishu, zishuzy@qq.com
 *        Created: 2019-10-12 13:48:15
 *  Last Modified: 2019-10-22 13:45:04
 *
 * ==============================================================
 */

#include "tableview_custom.hpp"

template <typename DataType>
TableViewCustom<DataType>::TableViewCustom(QWidget *parent) : QTableView(parent)
{

    m_pModel = new TableModelCustom<DataType>(this);
    this->setModel(m_pModel);
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
void TableViewCustom<DataType>::setDataList(QList<DataType> &datalist)
{
    m_pModel->setDataList(datalist);
}

