#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QList>


class MyModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    QList<QString> headerList;
    explicit MyModel(QObject *parent = nullptr);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void appendRow(QList<QString> newRow);
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    
    void deleteRow(int idx);
private:
    QList<QList<QString> > Data;
signals:
    void editCompleted(const QString &);
};

#endif
