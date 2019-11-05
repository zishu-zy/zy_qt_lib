/*
 * ==============================================================
 *
 *       FileName: data_define.h
 *    Description:
 *
 *         Author: zishu, zishuzy@qq.com
 *        Created: 2019-10-14 14:10:02
 *  Last Modified: 2019-10-17 14:17:38
 *
 * ==============================================================
 */
#ifndef DATA_DEFINE_H_
#define DATA_DEFINE_H_

#include <QString>
#include <QVariant>
// #include "tableview/tableview_custom_poly.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)                                                         \
    {                                                                          \
        if (p != NULL) {                                                       \
            delete (p);                                                        \
            (p) = NULL;                                                        \
        }                                                                      \
    }
#endif

struct TestDataInfo {
    QString strID;
    QString strName;
    QString strOther;
    bool bAdmin;
    QVariant getData(int i)
    {
        QVariant result;
        switch (i) {
        case 0:
            result = strID;
            break;
        case 1:
            result = strName;
            break;
        case 2:
            result = strOther;
            break;
        case 3:
            result = bAdmin;
            break;
        default:
            result = "";
        }
        return result;
    }
    void setData(int i, const QVariant &data)
    {
        switch (i) {
        case 0:
            strID = data.toString();
            break;
        case 1:
            strName = data.toString();
            break;
        case 2:
            strOther = data.toString();
            break;
        case 3:
            bAdmin = data.toBool();
            break;
        default:
            break;
        }
    }
};

/*
class TestData : public ITableModelData
{
public:
    TestData() : strID(""), strName(""), strOther(""), bAdmin(false) {}
    ~TestData() {}

    QVariant getData(int i) override
    {
        QVariant result;
        switch (i) {
        case 0:
            result = strID;
            break;
        case 1:
            result = strName;
            break;
        case 2:
            result = strOther;
            break;
        case 3:
            result = bAdmin;
            break;
        default:
            result = "";
        }
        return result;
    }
    void setData(int i, const QVariant &data) override
    {
        switch (i) {
        case 0:
            strID = data.toString();
            break;
        case 1:
            strName = data.toString();
            break;
        case 2:
            strOther = data.toString();
            break;
        case 3:
            bAdmin = data.toBool();
            break;
        default:
            break;
        }
    }

private:
    QString strID;
    QString strName;
    QString strOther;
    bool bAdmin;
};
*/

#endif // DATA_DEFINE_H_
