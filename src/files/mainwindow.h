#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTransposeProxyModel>
#include "mymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void setListViewColumn(int value);
    void onDeleteButtonClicked();
    void on_actionabout_triggered();
    void on_actionload_triggered();
    void on_actionsave_as_triggered();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    MyModel* myModel;
    QTransposeProxyModel *rmodel;
};

#endif // MAINWINDOW_H
