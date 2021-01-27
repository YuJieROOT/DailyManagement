#include "ClickWidget.h"
//#include "myDebug.h"
#include <QDebug>

void ClickWidget::mouseReleaseEvent(QMouseEvent *)
{
   emit clicked(this);
   qDebug()<<"1";
}

void ClickWidget::mouseDoubleClickEvent(QMouseEvent*)
{
    ;
}

QString ClickWidget::getText()
{
    return text;
}

void ClickWidget::setText(QString s)
{
    text = s;
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
