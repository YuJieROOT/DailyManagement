#include "ClickWidget.h"
//#include "myDebug.h"
#include <QDebug>
#include <QtSql>
#include <QTime>
#include <QWidget>
#include <QToolButton>
void ClickWidget::mouseReleaseEvent(QMouseEvent *)
{
   emit clicked(this);
}

void ClickWidget::mouseDoubleClickEvent(QMouseEvent*)
{
    ;
}

QString ClickWidget::getText()
{
    return text;
}

int ClickWidget::getnum()
{
    return num;
}

void ClickWidget::setText(QString s)
{
    text = s;
}

void ClickWidget::setNum(int Num)
{
    num = Num;
}

void ClickWidget::accomplish()
{ 
    // icon切换
    QToolButton * button = this->findChild<QToolButton *>("pane_off");
    button->setIcon(QIcon(":/icon/pane_on.png"));

    QToolButton *button2 = this->parent()->parent()->parent()->parent()->parent()->findChild<QToolButton *>("deadline_pane_off");
    button2->setIcon(QIcon(":/icon/pane_on.png"));

    //数据库中标记为已完成
    qDebug()<<this->num;
    QDate D;
    D = QDate::currentDate();
    QSqlQuery query;
    query.prepare("update 待办事项 set 完成时间 = ? where 编号 = ?");
    query.addBindValue(D);
    query.addBindValue(this->num);
//    query.exec();
//    QSqlDatabase::database().commit();
    QTime dieTime = QTime::currentTime().addMSecs(900);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    delete this;
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
