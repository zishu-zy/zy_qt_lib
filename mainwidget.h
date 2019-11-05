/*
 * ==============================================================
 *
 *       FileName: mainwidget.h
 *    Description: 测试的主界面
 *
 *         Author: zishu, zishuzy@qq.com
 *        Created: 2019-10-14 14:13:23
 *  Last Modified: 2019-10-17 14:13:36
 *
 * ==============================================================
 */
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QGridLayout>
#include <QWidget>
#include "data_define.h"
#include "tableview/tableview_custom.hpp"
// #include "tableview/tableview_custom_poly.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    void initUI();

private slots:
    void slotBtnClicked(int row, int btn);

private:
    TableViewCustom<TestDataInfo> *m_pTView;
    QGridLayout *m_pGLayoutMain;

    QList<TestDataInfo> m_ListTestDatas;
};

#endif // MAINWIDGET_H
