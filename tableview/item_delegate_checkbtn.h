/*
 * ==============================================================
 *
 *       FileName: item_delegate_checkbtn.h
 *    Description: 自定义委托 - checkbox
 *
 *         Author: zishu, zishuzy@qq.com
 *        Created: 2019-10-15 11:42:33
 *  Last Modified: 2019-10-15 17:49:44
 *
 * ==============================================================
 */
#ifndef ITEM_DELEGATE_CHECKBTN_H_
#define ITEM_DELEGATE_CHECKBTN_H_

#include <QPushButton>
#include <QStyledItemDelegate>

class ItemDelegateCheckBtn : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ItemDelegateCheckBtn(QWidget *parent = NULL);
    virtual ~ItemDelegateCheckBtn();

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index);

private:

signals:

private:
};

#endif //ITEM_DELEGATE_CHECKBTN_H_
