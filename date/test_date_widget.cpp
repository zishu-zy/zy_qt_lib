
#include "test_date_widget.h"

CTestDateWidget::CTestDateWidget(QWidget *parent) : QWidget(parent)
{
    m_pCDTEdit = new CDateTimeEdit(this);
    m_pCDateEdit = new CDateEdit(this);
    m_pVLayoutMain = new QVBoxLayout();
    initUI();
}

CTestDateWidget::~CTestDateWidget() {}

void CTestDateWidget::initUI()
{
    m_pCDTEdit->SetDisplayFormat("yyyy-MM-dd hh:mm:ss");
    m_pCDateEdit->SetDisplayFormat("yyyy-MM-dd");

    m_pVLayoutMain->addWidget(m_pCDTEdit);
    m_pVLayoutMain->addWidget(m_pCDateEdit);
    this->setLayout(m_pVLayoutMain);
}
