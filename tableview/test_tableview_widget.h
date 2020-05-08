#ifndef TEST_TABLEVIEW_WIDGET_H_
#define TEST_TABLEVIEW_WIDGET_H_

#include <QVBoxLayout>
#include <QWidget>
#include "data_define.h"
#include "tableview/tableview_custom.hpp"

class CTestTableViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CTestTableViewWidget(QWidget *parent = NULL);
    virtual ~CTestTableViewWidget();

private:
    void initUI();
    void initTestData();

private slots:
    void slotBtnClicked(int row, int btn);

private:
    TableViewCustom<TestDataInfo> *m_pTView;
    QVBoxLayout *m_pVLayoutMain;

    QList<TestDataInfo> m_ListTestDatas;
};

#endif // TEST_TABLEVIEW_WIDGET_H_
