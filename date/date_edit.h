#ifndef DATE_EDIT_H_
#define DATE_EDIT_H_

#include <QDateEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "calendar_widget.h"

class CDateEdit : public QWidget
{
    Q_OBJECT
public:
    explicit CDateEdit(QWidget *parent = NULL);
    virtual ~CDateEdit();

    void ClearDate();
    void SetDate(const QString &str_dt, const QString &str_format = "");
    void SetDate(const QDate &date);
    QVariant GetDate();

    void SetDisplayFormat(const QString &str_format);
    void SetPlaceholderText(const QString &str_text);

signals:
    void sigDateChanged(const QDate &date);

private:
    void initUI();
    void initConnect();
    void updateUI();

    void positionCalendarPopup();

private slots:
    void slotBtnCalenderClicked();
    void slotClickDate(const QDate &date);
    void slotClearDate();

private:
    enum { kShowLineEdit = 0, kShowDate };

    QLineEdit *m_pLEdit;
    QPushButton *m_pBtnCalendar;
    CCalendarWidget *m_pCalendarWidget;
    QDateEdit *m_pDateEdit;
    int m_nShowFlag;
};

#endif // DATE_EDIT_H_
