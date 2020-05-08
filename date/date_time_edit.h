#ifndef DATE_TIME_EDIT_H_
#define DATE_TIME_EDIT_H_

#include <QDateTimeEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "calendar_widget.h"

class CDateTimeEdit : public QWidget
{
    Q_OBJECT
public:
    explicit CDateTimeEdit(QWidget *parent = NULL);
    virtual ~CDateTimeEdit();

    void ClearDateTime();
    void SetDateTime(const QString &str_dt, const QString &str_format = "");
    void SetDateTime(const QDateTime &datetime);
    QVariant GetDateTime();

    void SetDisplayFormat(const QString &str_format);
    void SetPlaceholderText(const QString &str_text);

signals:
    void sigDateTimeChanged(const QDateTime &datetime);

private:
    void initUI();
    void initConnect();
    void updateUI();

    void positionCalendarPopup();

private slots:
    void slotBtnCalenderClicked();
    void slotClickDateTime(const QDateTime &datetime);
    void slotClearDateTime();

private:
    enum { kShowLineEdit = 0, kShowDateTime };

    QLineEdit *m_pLEdit;
    QPushButton *m_pBtnCalendar;
    CCalendarWidget *m_pCalendarWidget;
    QDateTimeEdit *m_pDtEdit;
    int m_nShowFlag;
};

#endif // DATE_TIME_EDIT_H_
