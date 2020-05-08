#include "date_time_edit.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QTime>

CDateTimeEdit::CDateTimeEdit(QWidget *parent) : QWidget(parent)
{
    m_pLEdit = new QLineEdit(this);
    m_pBtnCalendar = new QPushButton(this);
    m_pDtEdit = new QDateTimeEdit(this);
    m_nShowFlag = kShowLineEdit;
    m_pCalendarWidget = new CCalendarWidget();

    initUI();
    initConnect();
}

CDateTimeEdit::~CDateTimeEdit() {}

void CDateTimeEdit::ClearDateTime()
{
    SetDateTime("");
}

void CDateTimeEdit::SetDateTime(const QString &str_dt,
                                const QString &str_format)
{
    if (str_dt.isEmpty()) {
        m_pLEdit->setText("");
        m_nShowFlag = kShowLineEdit;
    } else {
        QDateTime dateTime = QDateTime::fromString(str_dt, str_format);
        m_pDtEdit->setDateTime(dateTime);
        m_pDtEdit->setDisplayFormat(str_format);
        m_nShowFlag = kShowDateTime;
    }
    updateUI();
}

void CDateTimeEdit::SetDateTime(const QDateTime &datetime)
{
    m_pDtEdit->setDateTime(datetime);
    m_nShowFlag = kShowDateTime;
    updateUI();
}

QVariant CDateTimeEdit::GetDateTime()
{
    QVariant result;
    if (m_nShowFlag == kShowLineEdit) {
        result = m_pLEdit->text();
    } else if (m_nShowFlag == kShowDateTime) {
        result = m_pDtEdit->dateTime();
    }
    return result;
}

void CDateTimeEdit::SetDisplayFormat(const QString &str_format)
{
    m_pDtEdit->setDisplayFormat(str_format);
}

void CDateTimeEdit::SetPlaceholderText(const QString &str_text)
{
    m_pLEdit->setPlaceholderText(str_text);
}

// ---------------- 内部 ----------------------
void CDateTimeEdit::initUI()
{
    this->setFixedSize(200, 50);
    m_pCalendarWidget->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    m_pCalendarWidget->SetShowTime(true);
    m_pLEdit->setFocusPolicy(Qt::NoFocus);
    m_pBtnCalendar->setFixedSize(16, 16);
    m_pBtnCalendar->setObjectName("date_select");

    QHBoxLayout *pHLayoutMain = new QHBoxLayout();
    pHLayoutMain->setContentsMargins(0, 0, 0, 0);
    pHLayoutMain->addWidget(m_pLEdit, Qt::AlignVCenter | Qt::AlignHCenter);
    pHLayoutMain->addWidget(m_pDtEdit, Qt::AlignVCenter | Qt::AlignHCenter);
    pHLayoutMain->addWidget(m_pBtnCalendar,
                            Qt::AlignVCenter | Qt::AlignHCenter);
    pHLayoutMain->addStretch(1);

    this->setLayout(pHLayoutMain);

    updateUI();
}

void CDateTimeEdit::initConnect()
{
    connect(m_pBtnCalendar, SIGNAL(clicked()), this,
            SLOT(slotBtnCalenderClicked()));
    connect(m_pCalendarWidget, SIGNAL(sigClicked(const QDateTime &)), this,
            SLOT(slotClickDateTime(const QDateTime &)));
    connect(m_pCalendarWidget, SIGNAL(sigClear()), this,
            SLOT(slotClearDateTime()));
}

void CDateTimeEdit::updateUI()
{
    if (m_nShowFlag == kShowLineEdit) {
        m_pLEdit->setHidden(false);
        m_pDtEdit->setHidden(true);
    } else if (m_nShowFlag == kShowDateTime) {
        m_pLEdit->setHidden(true);
        m_pDtEdit->setHidden(false);
    }
}

void CDateTimeEdit::positionCalendarPopup()
{
    QPoint pos = (this->layoutDirection() == Qt::RightToLeft)
                     ? this->rect().bottomRight()
                     : this->rect().bottomLeft();
    QPoint pos2 = (this->layoutDirection() == Qt::RightToLeft)
                      ? this->rect().topRight()
                      : this->rect().topLeft();
    pos = this->mapToGlobal(pos);
    pos2 = this->mapToGlobal(pos2);
    QSize size = m_pCalendarWidget->sizeHint();
    QRect screen = QApplication::desktop()->availableGeometry(pos);
    if (this->layoutDirection() == Qt::RightToLeft) {
        pos.setX(pos.x() - size.width());
        pos2.setX(pos2.x() - size.width());
        if (pos.x() < screen.left()) {
            pos.setX(qMax(pos.x(), screen.left()));
        } else if (pos.x() + size.width() > screen.right()) {
            pos.setX(
                qMax(pos.x() - size.width(), screen.right() - size.width()));
        }
    } else {
        if (pos.x() + size.width() > screen.right())
            pos.setX(screen.right() - size.width());
        pos.setX(qMax(pos.x(), screen.left()));
    }
    if (pos.y() + size.height() > screen.bottom()) {
        pos.setY(pos2.y() - size.height());
    } else if (pos.y() < screen.top()) {
        pos.setY(screen.top());
    }
    if (pos.y() < screen.top()) {
        pos.setY(screen.top());
    }
    if (pos.y() + size.height() > screen.bottom()) {
        pos.setY(screen.bottom() - size.height());
    }
    m_pCalendarWidget->move(pos);
}

void CDateTimeEdit::slotBtnCalenderClicked()
{
    positionCalendarPopup();
    m_pCalendarWidget->show();
}

void CDateTimeEdit::slotClickDateTime(const QDateTime &datetime)
{
    SetDateTime(datetime);
    emit this->sigDateTimeChanged(datetime);
}

void CDateTimeEdit::slotClearDateTime()
{
    ClearDateTime();
}
