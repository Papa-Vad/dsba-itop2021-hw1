#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include "renderarea.h"
namespace Ui
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    RenderArea* renderArea;
};

#endif // ABOUTDIALOG_H
