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

    //更改所属界面
    QString page = "log";
    QSqlQuery query;
    query.prepare("update 待办事项 set 所属界面 = ? where 编号 = ?");
    query.addBindValue(page);
    query.addBindValue(this->num);

//    query.exec();
//    QSqlDatabase::database().commit();

    //添加完成时间
    qDebug()<<this->num;
    QDate D;
    D = QDate::currentDate();
    query.prepare("update 待办事项 set 完成时间 = ? where 编号 = ?");
    query.addBindValue(D);
    query.addBindValue(this->num);

//    query.exec();
//    QSqlDatabase::database().commit();

    QTime dieTime = QTime::currentTime().addMSecs(800);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    emit update_countdown();
}

void ClickWidget::delete_countdown()
{
    //更改所属界面
    QString page = "dustbin";
    QSqlQuery query;
    query.prepare("update 待办事项 set 所属界面 = ? where 编号 = ?");
    query.addBindValue(page);
    query.addBindValue(this->num);

//    query.exec();
//    QSqlDatabase::database().commit();

    //添加删除时间
    QDate D;
    D = QDate::currentDate();
    query.prepare("update 待办事项 set 删除时间 = ? where 编号 = ?");
    query.addBindValue(D);
    query.addBindValue(this->num);

//    query.exec();
//    QSqlDatabase::database().commit();

    QTime dieTime = QTime::currentTime().addMSecs(800);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    emit update_countdown();

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
