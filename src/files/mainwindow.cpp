#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QFileDialog>
#include <iostream>

void fillModelWithData(MyModel* myModel, QString path)
{
    QFile inputFile(path);
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);
    QString line = inputStream.readLine();
    myModel->headerList = line.split(",");
    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        
        QList<QString> dataRow;
        for (QString& item : line.split(","))
        {
            dataRow.append(item);
        }
        myModel->appendRow(dataRow);
    }
    inputFile.close();
}

void saveModelAsFile(MyModel* m, QString path)
{
    QFile outFile(path);
    outFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&outFile);
    
    for (int i = 0; i < m->rowCount(); ++i)
    {
        for (int j = 0; j < m->columnCount(); ++j)
        {
            QModelIndex idx = m->index(i, j);
            out << m->data(idx).toString();
            if (j != m->columnCount() - 1)
            {
                out << ",";
            }
        }
        out << "\n";
    }
    outFile.close();
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myModel = new MyModel(this);
    rmodel = new QTransposeProxyModel(this);
    rmodel->setSourceModel(myModel);
    ui->listView->setModel(rmodel);
    ui->tableView->setModel(myModel);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete myModel;
    delete rmodel;
}


void MainWindow::setListViewColumn(int value)
{
    ui->listView->setModelColumn(value-1);
    if (value > myModel->rowCount())
    {
        ui->spinBox->setValue(1);
    }
    if (value < 1)
    {
        ui->spinBox->setValue( myModel->rowCount());
    }
}


void MainWindow::onDeleteButtonClicked()
{
    if (ui->spinBox_2->value() > 0)
    {
        myModel->deleteRow(ui->spinBox_2->value() - 1);
    }
    ui->listView->setModelColumn(0);
    ui->spinBox->setValue(1);
}


void MainWindow::on_actionabout_triggered()
{
    Dialog dialog;
    dialog.exec();
}


void MainWindow::on_actionload_triggered()
{
    QString path = QFileDialog::getOpenFileName(this);
    fillModelWithData(myModel, path);
}


void MainWindow::on_actionsave_as_triggered()
{

    QString path = QFileDialog::getSaveFileName(this);
    saveModelAsFile(myModel,path);
}

void MainWindow::on_pushButton_clicked()
{
    QList<QString> newrow;
    newrow = ui->lineEdit->text().split(",");
    myModel->appendRow(newrow);
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    if (ui->spinBox_2->value() > myModel->rowCount())
    {
        ui->spinBox_2->setValue(1);
    }
    if (ui->spinBox_2->value() < 1)
    {
        ui->spinBox_2->setValue( myModel->rowCount());
    }
}
