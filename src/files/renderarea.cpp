#include "renderarea.h"
#include <QPainter>
#include <QColor>
RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{

}


void RenderArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setBrush(Qt::GlobalColor::gray);
    painter.drawRect(QRect(0, 0, width(), height() - 1));
    painter.setBrush(Qt::GlobalColor::white);
    painter.drawRect(QRect(0, 0, width(), height()*0.1));
    painter.setBrush(Qt::GlobalColor::blue);
    painter.drawRect(QRect(0, height()*0.1, width(), height()*0.1));
    painter.setBrush(Qt::GlobalColor::red);
    painter.drawRect(QRect(0, height()*0.2, width(), height()*0.1));
    QColor color(255,165,0);
    painter.setBrush(color);
    painter.drawRect(QRect(0, height()*0.3, width(), height()*0.1));
    painter.setBrush(Qt::GlobalColor::white);
    painter.drawRect(QRect(0, height()*0.4, width(), height()*0.1));
    painter.setBrush(Qt::GlobalColor::blue);
    painter.drawEllipse(width()/3, height()*0.4, width()/3, height()*0.1);
    painter.setBrush(Qt::GlobalColor::green);
    painter.drawRect(QRect(0, height()*0.5, width(), height()*0.1));
    painter.setBrush(Qt::GlobalColor::red);
    painter.drawRect(QRect(0, height()*0.6, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+2*height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+4*height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+6*height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+8*height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+10*height()*0.1/3, width(), height()*0.1/3));
    painter.setBrush(Qt::GlobalColor::white);
    painter.drawRect(QRect(0, height()*0.6+height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+3*height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+5*height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+7*height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+9*height()*0.1/3, width(), height()*0.1/3));
    painter.drawRect(QRect(0, height()*0.6+11*height()*0.1/3, width(), height()*0.1/3));
    painter.setBrush(Qt::GlobalColor::blue);
    painter.drawRect(QRect(0, height()*0.6, width()*0.5, height()*0.2));
}
