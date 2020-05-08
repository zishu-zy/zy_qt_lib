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

#include <QVBoxLayout>
#include <QWidget>
#include "date/test_date_widget.h"
#include "tableview/test_tableview_widget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    void initUI();

private:
    TableViewCustom<TestDataInfo> *m_pTView;
    QVBoxLayout *m_pVLayoutMain;

    CTestDateWidget *m_pTestDateWidget;
    CTestTableViewWidget *m_pTestTableViewWidget;
};

#endif // MAINWIDGET_H
