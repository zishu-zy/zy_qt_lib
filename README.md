# zy_qt_lib

子书Qt相关库函数

## tableview

`./tableview` 目录下有tableview相关的库

### 1. tableview_custom

主要调用方法:

1. `void setHeaders(const QStringList &headerlist)`: 设置表格每列的名称，列的数量也将在这获取
2. `void setDataList(const QList<DataType> &datalist)`: 设置表格需要显示的数据

其中`DataType`是自定义的数据类型,这个数据类型需要自己实现两个方法：`QVariant getData(int i)`和`void setData(int i,const QVariant &data)`,下面给出一个例子

```cpp
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
```

### 2. tablemodel_custom

主要调用方法:

1. `void setHeaders(const QStringList &headerlist)`: 设置表格每列的名称，列的数量也将在这获取
2. `void setDataList(const QList<DataType> &datalist)`: 设置表格需要显示的数据

不过这个类不需要用户关心了，用户只需要调用`tableview_custom`即可。

### 3. item_delegate_btn

只有上面的方法显然是不完整的，很多情况下我们需要在表格中显示按键，这时就需要自定义委托，这个类就是实现在表格中显示`QPushButton`的。  
使用方法：

1. 调用`void setBtnNames(const QStringList &names)`和`void setBtnSize(int w, int h);`设置`btn`的名称和大小，其中大小可以不设置，默认是30x30，名称必须要设置，因为btn的个数就是根据这个进行设置的。
2. 调用`tableView`的`setItemDelegateForColumn`方法绑定本类。
3. 在调用处绑定他的两个信号`void sigBtnClicked(int row, int btn)`和`void sigBtnDoubleClicked(int row, int btn)`即可获取按键的单击和双击事件。

### 4. item_delegate_checkbtn

这个类就是实现在表格中显示`QCheckBox`的。  
使用方法：  
只需要实现好自定义数据结构中`getData`和`setData`，调用`tableView`的`setItemDelegateForColumn`方法绑定本类即可。
