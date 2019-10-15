/*
 * ==============================================================
 *
 *       FileName: tableview_custom.hpp
 *    Description: 自定义tableview
 *
 *         Author: zhaiyu, zhaiyu@qianxin.com
 *        Created: 2019-10-12 13:48:15
 *  Last Modified: 2019-10-14 14:21:24
 *
 * ==============================================================
 */

#ifndef TABLEVIEW_CUSTOM_H_
#define TABLEVIEW_CUSTOM_H_

#include <QTableView>
#include "tablemodel_custom.hpp"

template <typename DataType>
class TableViewCustom : public QTableView
{
public:
    explicit TableViewCustom(QWidget *parent = NULL);
    virtual ~TableViewCustom();

    void setHeaders(const QStringList &headerlist);
    void setDataList(const QList<DataType> &datalist);

private:
    TableModelCustom<DataType> *m_pModel;
};

#include "tableview_custom.cpp"

#endif // TABLEVIEW_CUSTOM_H_
