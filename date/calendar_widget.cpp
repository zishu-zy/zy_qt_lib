
#include "calendar_widget.h"
#include <QHBoxLayout>

CCalendarWidget::CCalendarWidget(QWidget *parent)
    : QWidget(parent), m_bShowTimeEnable(false)
{
    m_pCalendarWidget = new QCalendarWidget(this);
    m_pTimeEdit = new QTimeEdit(this);
    m_pBtnClear = new QPushButton(this);
    m_pBtnOk = new QPushButton(this);
    m_pVLayoutMain = new QVBoxLayout();

    initUI();
    initConnect();
}

CCalendarWidget::~CCalendarWidget() {}

void CCalendarWidget::SetShowTime(bool b_show)
{
    m_bShowTimeEnable = b_show;
    m_pTimeEdit->setHidden(!b_show);
}

void CCalendarWidget::initUI()
{
    m_pCalendarWidget->setVerticalHeaderFormat(
        QCalendarWidget::NoVerticalHeader);
    m_pTimeEdit->setTime(QTime::currentTime());
    m_pTimeEdit->setDisplayFormat("hh:mm:ss");
    m_pTimeEdit->setMinimumSize(80, 30);
    m_pBtnClear->setText(QString::fromLocal8Bit("清空"));
    m_pBtnOk->setText(QString::fromLocal8Bit("确定"));
    QHBoxLayout *pHLayout = new QHBoxLayout();
    pHLayout->addWidget(m_pTimeEdit);
    pHLayout->addWidget(m_pBtnClear);
    pHLayout->addWidget(m_pBtnOk);
    pHLayout->addStretch(1);

    m_pVLayoutMain->addWidget(m_pCalendarWidget);
    m_pVLayoutMain->addLayout(pHLayout);
    this->setLayout(m_pVLayoutMain);

    SetShowTime(m_bShowTimeEnable);
}

void CCalendarWidget::initConnect()
{
    connect(m_pBtnClear, SIGNAL(clicked()), this, SLOT(slotBtnClearClicked()));
    connect(m_pBtnOk, SIGNAL(clicked()), this, SLOT(slotBtnOkClicked()));
}

void CCalendarWidget::slotBtnOkClicked()
{
    QDate selectedDate;
    selectedDate = m_pCalendarWidget->selectedDate();
    if (m_bShowTimeEnable) {
        QDateTime selectedDatetime;
        selectedDatetime.setDate(selectedDate);
        selectedDatetime.setTime(m_pTimeEdit->time());
        emit this->sigClicked(selectedDatetime);
    } else {
        emit this->sigClicked(selectedDate);
    }
    this->close();
}

void CCalendarWidget::slotBtnClearClicked()
{
    emit this->sigClear();
    this->close();
}
