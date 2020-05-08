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

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    m_pTestDateWidget = new CTestDateWidget(this);
    m_pTestTableViewWidget = new CTestTableViewWidget();
    m_pVLayoutMain = new QVBoxLayout();

    initUI();
}

MainWidget::~MainWidget() {}

void MainWidget::initUI()
{
    this->setMinimumSize(700, 450);
    this->setWindowTitle("测试界面");
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry(); //获取设备屏幕大小
    this->move(screenRect.size().width() / 2 - 250,
               screenRect.size().height() / 2 - 150);

    m_pVLayoutMain->addWidget(m_pTestDateWidget);
    m_pVLayoutMain->addWidget(m_pTestTableViewWidget);
    this->setLayout(m_pVLayoutMain);
}
