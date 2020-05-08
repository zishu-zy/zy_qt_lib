#ifndef TEST_DATE_WIDGET_H_
#define TEST_DATE_WIDGET_H_

#include <QWidget>
#include "date_time_edit.h"
#include "date_edit.h"
#include <QVBoxLayout>

class CTestDateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CTestDateWidget(QWidget *parent = NULL);
    virtual ~CTestDateWidget();

private:
    void initUI();

private:
    CDateTimeEdit *m_pCDTEdit;
    CDateEdit *m_pCDateEdit;
    QVBoxLayout *m_pVLayoutMain;
};

#endif // TEST_DATE_WIDGET_H_
