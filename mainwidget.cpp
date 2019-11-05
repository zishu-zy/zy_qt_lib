/*
 * ==============================================================
 *
 *       FileName: mainwidget.cpp
 *    Description: 测试的主界面
 *
 *         Author: zishu, zishuzy@qq.com
 *        Created: 2019-10-14 14:13:23
 *  Last Modified: 2019-10-17 14:19:53
 *
 * ==============================================================
 */
#include "mainwidget.h"
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QHeaderView>
#include "tableview/item_delegate_btn.h"
#include "tableview/item_delegate_checkbtn.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    m_pTView = new TableViewCustom<TestDataInfo>(this);
    m_pGLayoutMain = new QGridLayout();

    initUI();
}

MainWidget::~MainWidget()
{
    SAFE_DELETE(m_pTView);
    SAFE_DELETE(m_pGLayoutMain);
}

void MainWidget::initUI()
{
    this->setMinimumSize(700, 450);
    this->setWindowTitle("测试界面");
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry(); //获取设备屏幕大小
    this->move(screenRect.size().width() / 2 - 250,
               screenRect.size().height() / 2 - 150);

    for (int i = 0; i < 2; ++i) {
        TestDataInfo t;
        t.setData(0, QString::number(i));
        t.setData(1, QString::fromLocal8Bit("小明%1").arg(i));
        t.setData(2, "other");
        t.setData(3,false);
        m_ListTestDatas.append(t);
    }
    QStringList headers;
    headers << "id"
            << "name"
            << "other"
            << "管理员" << QString::fromLocal8Bit("操作");
    m_pTView->setHeaders(headers);
    m_pTView->setDataList(m_ListTestDatas);

    ItemDelegateCheckBtn *checkBtn = new ItemDelegateCheckBtn(this);
    m_pTView->setItemDelegateForColumn(3, checkBtn);

    ItemDelegateBtn *t = new ItemDelegateBtn(this);
    connect(t, SIGNAL(sigBtnClicked(int, int)), this,
            SLOT(slotBtnClicked(int, int)));
    t->setBtnNames(QStringList() << "修改"
                                 << "删除"
                                 << "恢复");
    t->setBtnSize(40, 30);
    t->setBtnInterval(10);
    m_pTView->setItemDelegateForColumn(4, t);
    m_pTView->setColumnWidth(4, 200);

    m_pGLayoutMain->addWidget(m_pTView);
    this->setLayout(m_pGLayoutMain);
}

void MainWidget::slotBtnClicked(int row, int btn)
{
    qDebug() << "第" << row << "行,按键" << btn;
}
