
#include "date_edit.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>

CDateEdit::CDateEdit(QWidget *parent) : QWidget(parent)
{
    m_pLEdit = new QLineEdit(this);
    m_pBtnCalendar = new QPushButton(this);
    m_pDateEdit = new QDateEdit(this);
    m_nShowFlag = kShowLineEdit;
    m_pCalendarWidget = new CCalendarWidget();

    initUI();
    initConnect();
}

CDateEdit::~CDateEdit() {}

void CDateEdit::ClearDate()
{
    SetDate("");
}

void CDateEdit::SetDate(const QString &str_dt, const QString &str_format)
{
    if (str_dt.isEmpty()) {
        m_pLEdit->setText("");
        m_nShowFlag = kShowLineEdit;
    } else {
        QDate date = QDate::fromString(str_dt, str_format);
        m_pDateEdit->setDate(date);
        m_pDateEdit->setDisplayFormat(str_format);
        m_nShowFlag = kShowDate;
    }
    updateUI();
}

void CDateEdit::SetDate(const QDate &date)
{
    m_pDateEdit->setDate(date);
    m_nShowFlag = kShowDate;
    updateUI();
}

QVariant CDateEdit::GetDate()
{
    QVariant result;
    if (m_nShowFlag == kShowLineEdit) {
        result = m_pLEdit->text();
    } else if (m_nShowFlag == kShowDate) {
        result = m_pDateEdit->date();
    }
    return result;
}

void CDateEdit::SetDisplayFormat(const QString &str_format)
{
    m_pDateEdit->setDisplayFormat(str_format);
}

void CDateEdit::SetPlaceholderText(const QString &str_text)
{
    m_pLEdit->setPlaceholderText(str_text);
}

// ---------------- 内部 ----------------------
void CDateEdit::initUI()
{
    this->setFixedSize(200, 50);
    m_pCalendarWidget->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    m_pCalendarWidget->SetShowTime(false);
    m_pLEdit->setFocusPolicy(Qt::NoFocus);
    m_pBtnCalendar->setFixedSize(16, 16);
    m_pBtnCalendar->setObjectName("date_select");

    QHBoxLayout *pHLayoutMain = new QHBoxLayout();
    pHLayoutMain->setContentsMargins(0, 0, 0, 0);
    pHLayoutMain->addWidget(m_pLEdit, Qt::AlignVCenter | Qt::AlignHCenter);
    pHLayoutMain->addWidget(m_pDateEdit, Qt::AlignVCenter | Qt::AlignHCenter);
    pHLayoutMain->addWidget(m_pBtnCalendar,
                            Qt::AlignVCenter | Qt::AlignHCenter);
    pHLayoutMain->addStretch(1);

    this->setLayout(pHLayoutMain);

    updateUI();
}

void CDateEdit::initConnect()
{
    connect(m_pBtnCalendar, SIGNAL(clicked()), this,
            SLOT(slotBtnCalenderClicked()));
    connect(m_pCalendarWidget, SIGNAL(sigClicked(const QDate&)), this,
            SLOT(slotClickDate(const QDate&)));
    connect(m_pCalendarWidget, SIGNAL(sigClear()), this,
            SLOT(slotClearDate()));
}

void CDateEdit::updateUI()
{
    if (m_nShowFlag == kShowLineEdit) {
        m_pLEdit->setHidden(false);
        m_pDateEdit->setHidden(true);
    } else if (m_nShowFlag == kShowDate) {
        m_pLEdit->setHidden(true);
        m_pDateEdit->setHidden(false);
    }
}

void CDateEdit::positionCalendarPopup()
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

void CDateEdit::slotBtnCalenderClicked()
{
    positionCalendarPopup();
    m_pCalendarWidget->show();
}

void CDateEdit::slotClickDate(const QDate &date)
{
    SetDate(date);
    emit this->sigDateChanged(date);
}

void CDateEdit::slotClearDate()
{
    ClearDate();
}
