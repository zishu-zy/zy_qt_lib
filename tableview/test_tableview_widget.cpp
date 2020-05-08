
#include "test_tableview_widget.h"
#include <QDebug>
#include <QHeaderView>
#include "tableview/item_delegate_btn.h"
#include "tableview/item_delegate_checkbtn.h"

CTestTableViewWidget::CTestTableViewWidget(QWidget *parent) : QWidget(parent)
{
    m_pTView = new TableViewCustom<TestDataInfo>;
    m_pVLayoutMain = new QVBoxLayout();

    initUI();
    initTestData();
}

CTestTableViewWidget::~CTestTableViewWidget() {}

void CTestTableViewWidget::initUI()
{
    QStringList headers;
    headers << "id"
            << "name"
            << "other"
            << "管理员" << QString::fromLocal8Bit("操作");
    m_pTView->setHeaders(headers);

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

    m_pVLayoutMain->addWidget(m_pTView);
    this->setLayout(m_pVLayoutMain);
}

void CTestTableViewWidget::initTestData()
{

    for (int i = 0; i < 5; ++i) {
        TestDataInfo t;
        t.setData(0, QString::number(i));
        t.setData(1, QString::fromLocal8Bit("小明%1").arg(i));
        t.setData(2, "other");
        t.setData(3, false);
        m_ListTestDatas.append(t);
    }
    m_pTView->setDataList(m_ListTestDatas);
    m_pTView->setColumnWidth(4, 200);
}

void CTestTableViewWidget::slotBtnClicked(int row, int btn)
{
    qDebug() << "第" << row << "行,按键" << btn;
}
