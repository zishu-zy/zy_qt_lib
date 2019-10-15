/*
 * ==============================================================
 *
 *       FileName: mainwidget.h
 *    Description: 测试的主界面
 *
 *         Author: zhaiyu, zhaiyu@qianxin.com
 *        Created: 2019-10-14 14:13:23
 *  Last Modified: 2019-10-15 14:23:19
 *
 * ==============================================================
 */
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QGridLayout>
#include <QWidget>
#include "data_define.h"
#include "tableview/tableview_custom.h"

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
};

#endif // MAINWIDGET_H
