#ifndef CALENDAR_WIDGET_H_
#define CALENDAR_WIDGET_H_

#include <QCalendarWidget>
#include <QPushButton>
#include <QTimeEdit>
#include <QVBoxLayout>
#include <QWidget>

class CCalendarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CCalendarWidget(QWidget *parent = NULL);
    virtual ~CCalendarWidget();

    void SetShowTime(bool b_show);

signals:
    void sigClear();
    void sigClicked(const QDate &);
    void sigClicked(const QDateTime &);

private slots:
    void slotBtnOkClicked();
    void slotBtnClearClicked();

private:
    void initUI();
    void initConnect();

private:
    QCalendarWidget *m_pCalendarWidget;
    QVBoxLayout *m_pVLayoutMain;
    QPushButton *m_pBtnClear;
    QPushButton *m_pBtnOk;
    QTimeEdit *m_pTimeEdit;
    bool m_bShowTimeEnable;
};

#endif // CALENDAR_WIDGET_H_
