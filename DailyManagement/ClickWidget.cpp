#include "ClickWidget.h"
//#include "myDebug.h"
#include <QDebug>

ClickWidget::ClickWidget(QWidget *parent):
    QWidget(parent)
{
    //this->setStyleSheet("background: #32CC99;");
}

void ClickWidget::mouseReleaseEvent(QMouseEvent *)
{
   emit clicked();
   qDebug()<<"1";
}
void ClickWidget::mouseDoubleClickEvent(QMouseEvent*)
{
    ;
}
/*
void ClickWidget::initWidget(QStringList &nameList)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    foreach ()
    {
        QWidget *widget = new QWidget;
        //widget->setMinimumSize(widget->size());
        widget->setStyleSheet("background: #32CC99;");
        layout->addWidget(widget);
     }
     this->setLayout(layout);
}
*/
