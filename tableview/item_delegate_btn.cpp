/*
 * ==============================================================
 *
 *       FileName: item_delegate_btn.cpp
 *    Description: 自定义委托 - btn
 *
 *         Author: zhaiyu, zhaiyu@qianxin.com
 *        Created: 2019-10-12 13:48:15
 *  Last Modified: 2019-10-15 17:49:19
 *
 * ==============================================================
 */

#include "item_delegate_btn.h"
#include <QApplication>
#include <QDebug>
#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QTextOption>
#include <QToolTip>

static inline bool isInside(int xleft, int xright, int ytop, int ybottom, int x,
                            int y)
{
    return (x >= xleft && x <= xright && y >= ytop && y <= ybottom);
}

ItemDelegateBtn::ItemDelegateBtn(QWidget *parent)
    : QStyledItemDelegate(parent), m_nBtnWidth(30), m_nBtnHeight(30),
      m_nBtnInterval(5)
{
}

ItemDelegateBtn::~ItemDelegateBtn() {}

void ItemDelegateBtn::setBtnNames(const QStringList &names)
{
    m_ListBtnName = names;
}

void ItemDelegateBtn::setBtnSize(int w, int h)
{
    m_nBtnWidth = w;
    m_nBtnHeight = h;
}

void ItemDelegateBtn::setBtnInterval(int interval)
{
    m_nBtnInterval = interval;
}

void ItemDelegateBtn::paint(QPainter *painter,
                            const QStyleOptionViewItem &option,
                            const QModelIndex &index) const
{
    (void)index;
    int len = m_ListBtnName.size();
    for (int i = 0; i < len; ++i) {
        QStyleOptionButton *button = new QStyleOptionButton();
        QRect r = option.rect;
        int x, y;
        x = r.left() + (m_nBtnWidth + m_nBtnInterval) * i;
        y = r.top();
        button->rect = QRect(x, y, m_nBtnWidth, m_nBtnHeight);
        button->text = m_ListBtnName.at(i);
        button->state = QStyle::State_Enabled;
        QApplication::style()->drawControl(QStyle::CE_PushButton, button,
                                           painter);
    }
}

bool ItemDelegateBtn::editorEvent(QEvent *event, QAbstractItemModel *model,
                                  const QStyleOptionViewItem &option,
                                  const QModelIndex &index)
{
    static bool pressFlag = false;
    QMouseEvent *e = static_cast<QMouseEvent *>(event);
    if (e->button() != Qt::LeftButton || !index.isValid()) {
        return false;
    }
    int clickX = e->x();
    int clickY = e->y();
    int btn = getBtnFromXY(option, clickX, clickY);
    if (btn == -1) {
        return true;
    }
    if (event->type() == QEvent::MouseButtonDblClick) {
        emit sigBtnDoubleClicked(index.row(), btn);
    } else if (event->type() == QEvent::MouseButtonPress) {
        pressFlag = true;
    } else if (pressFlag && event->type() == QEvent::MouseButtonRelease) {
        pressFlag = false;
        emit sigBtnClicked(index.row(), btn);
    }
    return true;
}

int ItemDelegateBtn::getBtnFromXY(const QStyleOptionViewItem &option, int x,
                                  int y)
{
    int btn = -1;
    int itemX = option.rect.left();
    int itemY = option.rect.top();
    int len = m_ListBtnName.size();
    for (int i = 0; i < len; ++i) {
        if (isInside(itemX + (m_nBtnWidth + m_nBtnInterval) * i,
                     itemX + m_nBtnWidth * (i + 1), itemY, itemY + m_nBtnHeight,
                     x, y)) {
            btn = i;
            break;
        }
    }
    return btn;
}
