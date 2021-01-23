#include "todoPage.h"
#include "ui_todoPage.h"
#include "myDebug.h"
#include "ClickWidget.h"
#include <QTime>
#include <QScrollArea>
#include <QScrollBar>
#include <QtSql>
#include <QWidget>
#include "ui_logic.h"
//#include "MyLabelEdit.h"

QVBoxLayout *vlayout = new QVBoxLayout;//建立一个横排的规则

todoPage::todoPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::todoPage)
{
    // 安装消息处理程序
        qInstallMessageHandler(myMessageOutput);

    ui->setupUi(this);
    initUI(this);


ClickWidget *working_place;

//第二栏初始读数据库显示
    {

           ui->inbox_scrollAreaWidgetContents->setLayout(vlayout);
           ui->inbox_scrollAreaWidgetContents->setFixedHeight(0);

           QSqlQuery query;  //新建一个查询的实例
           if (query.exec("select * from 待办事项工作区"))   //列出表的所有记录    //本次查询成功
           {
               QString name;
               while(query.next())
               {
                   int h = ui->inbox_scrollAreaWidgetContents->height();
                   ui->inbox_scrollAreaWidgetContents->setFixedHeight(h + 45);
                   name = query.value("工作区名").toString();

                   qDebug()<<name;

                   QHBoxLayout *hlayout = new QHBoxLayout;//建立一个横排的规则
                   working_place=new ClickWidget;
                   working_place->setFixedSize(225,65);
                   vlayout->addWidget(working_place);
                   working_place->setLayout(hlayout);
                   vlayout->setMargin(12);


                   QToolButton *button = new QToolButton;
                   //button->setText(name);
                   button->setIcon(QIcon(":/icon/working_table.png"));
                   button->setFixedSize(30,30);


                   //button->setFlat(true);
                   //button->setPalette(true);
                   button->setStyleSheet("QPushButton{border:none;background-color: rgba(255, 255, 255, 0);}");
                   hlayout->addWidget(button);//把Button放入Layout中
                   QLabel *label = new QLabel;
                   label->setText(name);
                   label->setFixedSize(50,30);
                   hlayout->addWidget(label);//把TextEdit放入Layout中

                   hlayout->setSpacing(0);

               }

           }
           else  //如果查询失败，用下面的方法得到具体数据库返回的原因
           {
               QSqlError error = query.lastError();
               //display.append("From mysql database: " + error.databaseText());
           }
    }

connect(working_place, SIGNAL(clicked()), this, SLOT(clickMyWidget()));
}

todoPage::~todoPage()
{
    delete ui;
}


void todoPage::on_user_button_clicked()
{
    userPage *w = new userPage;
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(300);//延时300毫秒
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    delete this;
}

void todoPage::on_calendar_button_clicked()
{
    calendarPage *w = new calendarPage;
    w->show();
    this->close();
    delete this;
}

void todoPage::on_count_down_button_clicked()
{
    countDownPage *w = new countDownPage;
    w->show();
    this->close();
    delete this;
}

void todoPage::on_dustbin_button_clicked()
{
    dustbinPage *w = new dustbinPage;
    w->show();
    this->close();
    delete this;
}


void todoPage::on_search_button_clicked()
{
    searchPage *w = new searchPage;
    w->show();
    this->close();
    delete this;
}

void todoPage::on_log_button_clicked()
{
    logPage *w = new logPage;
    w->show();
    this->close();
    delete this;
}

void todoPage::on_setting_button_clicked()
{
    settingPage *w = new settingPage;
    w->show();
    this->close();
    delete this;
}

//新建工作区
void todoPage::on_new_workplace_button_clicked()
{
        QString name;
        //while(query.next())
        {
            int h = ui->inbox_scrollAreaWidgetContents->height();
            ui->inbox_scrollAreaWidgetContents->setFixedHeight(h + 45);

            QHBoxLayout *hlayout = new QHBoxLayout;//建立一个横排的规则
            ClickWidget *working_place=new ClickWidget;
            working_place->setFixedSize(225,65);
            vlayout->addWidget(working_place);
            working_place->setLayout(hlayout);

            QToolButton *button = new QToolButton;
            //button->setText(name);
            button->setIcon(QIcon(":/icon/working_table.png"));
            button->setFixedSize(30,30);
            //button->setFlat(true);
            //button->setPalette(true);
            button->setStyleSheet("QPushButton{border:none;background-color: rgba(255, 255, 255, 0);}");
            hlayout->addWidget(button);//把Button放入Layout中
            QTextEdit *textEdit = new QTextEdit;
            //textEdit->setText(name);
            textEdit->setFixedSize(50,30);
            hlayout->addWidget(textEdit);//把TextEdit放入Layout中


            hlayout->setSpacing(0);

        }


}

void todoPage::clickMyWidget()
{
    //第二栏初始读数据库显示
        {

               ui->todo_scrollAreaWidgetContents->setLayout(vlayout);
               ui->todo_scrollAreaWidgetContents->setFixedHeight(0);

               QString working_place_text;

               QSqlQuery query;  //新建一个查询的实例
               //if (query.exec(QString("select * from 待办事项 while 所属界面 is like 'todo%' && 所属工作区 = %1;").arg(working_place_text)))   //列出表的所有记录    //本次查询成功
               if (query.exec("select * from 待办事项 while 所属界面 is like 'todo%' && 所属工作区 = '家庭';"))
               {
                   QString title;
                   while(query.next())
                   {
                       int h = ui->todo_scrollAreaWidgetContents->height();
                       ui->todo_scrollAreaWidgetContents->setFixedHeight(h + 45);
                       title = query.value("待办事项名").toString();

                       qDebug()<<title;

                       QHBoxLayout *hlayout = new QHBoxLayout;//建立一个横排的规则
                       ClickWidget *working_place=new ClickWidget;
                       working_place->setFixedSize(225,65);
                       vlayout->addWidget(working_place);
                       working_place->setLayout(hlayout);

                       QToolButton *button = new QToolButton;
                       //button->setText(name);
                       button->setIcon(QIcon(":/icon/working_table.png"));
                       button->setFixedSize(30,30);
                       //button->setFlat(true);
                       //button->setPalette(true);
                       button->setStyleSheet("QPushButton{border:none;background-color: rgba(255, 255, 255, 0);}");
                       button->setAutoRaise(true);
                       hlayout->addWidget(button);//把Button放入Layout中
                       QLabel *label = new QLabel;
                       label->setText(title);
                       label->setFixedSize(50,30);
                       hlayout->addWidget(label);//把TextEdit放入Layout中

                       hlayout->setSpacing(0);

                   }

               }
               else  //如果查询失败，用下面的方法得到具体数据库返回的原因
               {
                   QSqlError error = query.lastError();
                   //display.append("From mysql database: " + error.databaseText());
               }
        }


}
