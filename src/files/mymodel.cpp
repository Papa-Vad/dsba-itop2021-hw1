#include "mymodel.h"
#include <QBrush>

MyModel::MyModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int MyModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }
    return Data.size();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }
    if (Data.empty())
    {
        return 0;
    }
    return Data[0].size();
}



QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }
    int row = index.row();
    int column = index.column();
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return Data.at(row).at(column);
    }
    else if (role == Qt::BackgroundRole)
    {
        QColor color(224,188,188);
        return QBrush(color);
    }
    return QVariant();
}



bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value)
    {
        Data[index.row()][index.column()] = value.toString();
        return true;
    }
    return false;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}


void MyModel::appendRow(QList<QString> newRow)
{
    bool columnFlag = false;
    if (Data.isEmpty())
    {
        columnFlag = true;
        beginInsertColumns(QModelIndex(), 0, newRow.size() - 1);
    }
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    Data.append(newRow);
    endInsertRows();
    if (columnFlag)
    {
        endInsertColumns();
    }
}


void MyModel::deleteRow(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    Data.removeAt(idx);
    endRemoveRows();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && !headerList.empty())
    {
        if (orientation == Qt::Orientation::Horizontal)
        {
            return headerList.at(section);
        }
        else
        {
            return section + 1;
        }
    }
    return QVariant();
}

