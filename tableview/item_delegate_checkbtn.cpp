/*
 * ==============================================================
 *
 *       FileName: item_delegate_checkbtn.cpp
 *    Description: 自定义委托 - checkbox
 *
 *         Author: zishu, zishuzy@qq.com
 *        Created: 2019-10-15 11:42:29
 *  Last Modified: 2019-10-15 17:49:39
 *
 * ==============================================================
 */

#include "item_delegate_checkbtn.h"
#include <QApplication>
#include <QMouseEvent>

ItemDelegateCheckBtn::ItemDelegateCheckBtn(QWidget *parent)
    : QStyledItemDelegate(parent)
{
}

ItemDelegateCheckBtn::~ItemDelegateCheckBtn() {}

void ItemDelegateCheckBtn::paint(QPainter *painter,
                                 const QStyleOptionViewItem &option,
                                 const QModelIndex &index) const
{
    QStyleOptionButton cbOpt;
    cbOpt.rect = option.rect;

    bool isChecked = index.model()->data(index).toBool();
    if (isChecked) {
        cbOpt.state |= QStyle::State_On;
    } else {
        cbOpt.state |= QStyle::State_Off;
    }

    QApplication::style()->drawControl(QStyle::CE_CheckBox, &cbOpt, painter);
}

bool ItemDelegateCheckBtn::editorEvent(QEvent *event, QAbstractItemModel *model,
                                       const QStyleOptionViewItem &option,
                                       const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonRelease) {
        bool isChecked = index.model()->data(index).toBool() ? true:false;
        model->setData(index, !isChecked);
        return true;
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
