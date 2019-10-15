/*
 * ==============================================================
 *
 *       FileName: item_delegate_btn.h
 *    Description:
 *
 *         Author: zhaiyu, zhaiyu@qianxin.com
 *        Created: 2019-10-12 13:48:15
 *  Last Modified: 2019-10-15 10:19:49
 *
 * ==============================================================
 */

#ifndef ITEM_DELEGATE_BTN_H_
#define ITEM_DELEGATE_BTN_H_

#include <QPushButton>
#include <QStyledItemDelegate>

class ItemDelegateBtn : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ItemDelegateBtn(QWidget *parent = NULL);
    virtual ~ItemDelegateBtn();

    void setBtnNames(const QStringList &names);
    void setBtnSize(int w, int h);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index);

private:
    int getBtnFromXY(const QStyleOptionViewItem &option, int x, int y);

signals:
    void sigBtnClicked(int row, int btn);
    void sigBtnDoubleClicked(int row, int btn);

private:
    QStringList m_ListBtnName;
    int m_nBtnWidth;
    int m_nBtnHeight;
};

#endif // ITEM_DELEGATE_BTN_H_
