#include "todoPage.h"
#include "ui_todoPage.h"
#include "myDebug.h"

#include <QTime>
#include <QScrollArea>
#include <QScrollBar>
#include <QtSql>
#include <QWidget>
#include "ui_logic.h"
//#include "MyLabelEdit.h"

//QVBoxLayout *vlayout = new QVBoxLayout;//建立一个横排的规则

todoPage::todoPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::todoPage)
{
    // 安装消息处理程序
        qInstallMessageHandler(myMessageOutput);

    ui->setupUi(this);
    initUI(this);





//第二栏初始读数据库显示
    {
           ui->inbox_scrollAreaWidgetContents->setFixedHeight(0);

           QSqlQuery query;  //新建一个查询的实例

           if (query.exec("select * from 待办事项工作区"))  //列出表的所有记录    //本次查询成功
           {
               QString name;
               while(query.next())
               {
                   int h = ui->inbox_scrollAreaWidgetContents->height();
                   ui->inbox_scrollAreaWidgetContents->setFixedHeight(h + 75);  //每增加一个工作区scroll的高度增加75
                   name = query.value("工作区名").toString();

                   qDebug()<<name;

                   //新增一个工作区
                   ClickWidget *working_place=new ClickWidget(ui->inbox_scrollAreaWidgetContents);
                   working_place->setMinimumSize(205,70);
                   working_place->setGeometry(5,h+5,205,70);
                   working_place->setStyleSheet("ClickWidget{"
                                                "border-radius:10px;"
                                                "}"
                               );

                   //工作区内添加icon
                   QToolButton *icon = new QToolButton(working_place);
                   icon->setIcon(QIcon(":/icon/working_table.png"));
                   icon->setAutoRaise(true);
                   icon->setIconSize(QSize(30, 30));
                   icon->setGeometry(15,16,30,30);
                   icon->setStyleSheet("QToolButton{"
                                            "background:transparent;"
                                       "}"
                               );

                   //工作区内添加文本
                   QLineEdit *text = new QLineEdit(working_place);
                   text->setFrame(false);
                   text->setText(name);
                   text->setGeometry(65,16,60,30);
                   text->setStyleSheet("QLineEdit{"
                                       "background:transparent;"
                                        "font: 12pt 'Microsoft YaHei';"
                                  "}"
                               );

                   //工作区添加右箭头
                   QToolButton *right_arrow = new QToolButton(working_place);
                   right_arrow->setIcon(QIcon(":/icon/right_arrow.png"));
                   right_arrow->setIconSize(QSize(30, 30));
                   right_arrow->setAutoRaise(true);
                   right_arrow->setGeometry(180, 17, 30, 30);
                   right_arrow->setStyleSheet("QToolButton{"
                                            "background:transparent;"
                                       "}"
                               );

                   //工作区添加底线
                   QFrame *line = new QFrame(working_place);
                   line->setGeometry(QRect(10, 68, 205, 3));
                   line->setFrameShape(QFrame::HLine);
                   line->setFrameShadow(QFrame::Sunken);
                   line->setStyleSheet("QFrame{"
                                            "border-top: 2px solid rgb(237, 238, 238);"
                                       "}"
                               );
                   line->raise();

                   //将工作区名存入ClickWidget
                   working_place->setText(name);

                   connect(working_place, SIGNAL(clicked(ClickWidget *)), this, SLOT(clickMyWidget(ClickWidget *)));
               }

           }
           else  //如果查询失败，用下面的方法得到具体数据库返回的原因
           {
               QSqlError error = query.lastError();
               //display.append("From mysql database: " + error.databaseText());
           }
    }



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
    int h = ui->inbox_scrollAreaWidgetContents->height();
    ui->inbox_scrollAreaWidgetContents->setFixedHeight(h + 75);  //每增加一个工作区scroll的高度增加75

    qDebug()<<h;

    //新增一个工作区
    ClickWidget *working_place = new ClickWidget(ui->inbox_scrollAreaWidgetContents);
    working_place->resize(205,70);
    working_place->move(5,h+5);
    working_place->setStyleSheet("ClickWidget{"
                                 "border-radius:10px;"
                                 "}"
                );
    working_place->show();


    //工作区内添加icon
    QToolButton *icon = new QToolButton(working_place);
    icon->resize(30, 30);
    icon->setIcon(QIcon(":/icon/working_table.png"));
    icon->setIconSize(QSize(30, 30));
    icon->setAutoRaise(true);
    icon->setGeometry(15,16,30,30);
    icon->setStyleSheet("QToolButton{"
                             "background:transparent;"
                        "}"
                );
    icon->show();

    //工作区内添加文本
    QLineEdit *text = new QLineEdit(working_place);
    text->resize(60,30);
    text->setGeometry(65,16,100,30);
    text->setFrame(false);
    text->setStyleSheet("QLineEdit{"
                             "background:transparent;"
                              "font: 12pt 'Microsoft YaHei';"
                        "}"
                );
    text->show();

    //工作区添加右箭头
    QToolButton *right_arrow = new QToolButton(working_place);
    right_arrow->resize(30, 30);
    right_arrow->setIcon(QIcon(":/icon/right_arrow.png"));
    right_arrow->setIconSize(QSize(30, 30));
    right_arrow->setAutoRaise(true);
    right_arrow->setGeometry(180, 17, 30, 30);
    right_arrow->setStyleSheet("QToolButton{"
                             "background:transparent;"
                        "}"
                );
    right_arrow->show();

    //工作区添加底线
    QFrame *line = new QFrame(working_place);
    line->resize(205, 3);
    line->setGeometry(QRect(10, 68, 205, 3));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setStyleSheet("QFrame{"
                             "border-top: 2px solid rgb(237, 238, 238);"
                        "}"
                );
    line->raise();
    line->show();

    connect(working_place, SIGNAL(clicked(ClickWidget *)), this, SLOT(clickMyWidget(ClickWidget *)));

    //第二栏选中分组改变颜色
    QList<ClickWidget*> clickw_inbox = ui->inbox_scrollAreaWidgetContents->findChildren<ClickWidget*>();
    foreach (ClickWidget* clickw_inbox, clickw_inbox)
    {
        clickw_inbox->setStyleSheet("ClickWidget{"
                                          "border-radius:10px;"
                                          "background-color: rgba(255, 255, 255, 0);"
                                          "}"
                              );
    }
    working_place->setStyleSheet("ClickWidget{"
                     "border-radius:10px;"
                        "background-color: rgba(246, 246, 246, 125);"
                        "}"
                );


    //第三栏title显示当前工作区名称
    QString working_place_text = working_place->findChild<QLineEdit*>()->text();
    ui->new_todo_workPlace->setText(working_place_text);

    //删除所有ClickWidget
    QList<ClickWidget*> clickw = ui->todo_scrollAreaWidgetContents->findChildren<ClickWidget*>();
    foreach (ClickWidget* clickw, clickw) {   delete clickw;  }
    //删除所有QToolButton
    QList<QToolButton*> btns = ui->todo_scrollAreaWidgetContents->findChildren<QToolButton*>();
    foreach (QToolButton* btn, btns) {   delete btn;  }
    //删除所有QLineEdit
    QList<QLineEdit*> ledit = ui->todo_scrollAreaWidgetContents->findChildren<QLineEdit*>();
    foreach (QLineEdit* ledit, ledit) {   delete ledit;  }
    //删除所有QFrame
    QList<QFrame*> frame = ui->todo_scrollAreaWidgetContents->findChildren<QFrame*>();
    foreach (QFrame* frame, frame) {   delete frame;  }



}

//第三栏初始读数据库显示
void todoPage::clickMyWidget(ClickWidget *w)
{
    //第二栏选中分组改变颜色
    QList<ClickWidget*> clickw_inbox = ui->inbox_scrollAreaWidgetContents->findChildren<ClickWidget*>();
    foreach (ClickWidget* clickw_inbox, clickw_inbox)
    {
        clickw_inbox->setStyleSheet("ClickWidget{"
                                          "border-radius:10px;"
                                          "background-color: rgba(255, 255, 255, 0);"
                                          "}"
                              );
    }
    w->setStyleSheet("ClickWidget{"
                     "border-radius:10px;"
                        "background-color: rgba(246, 246, 246, 125);"
                        "}"
                );
    //第三栏title显示当前工作区名称
    QString working_place_text = w->findChild<QLineEdit*>()->text();
    ui->new_todo_workPlace->setText(working_place_text);

    //删除所有ClickWidget
    QList<ClickWidget*> clickw = ui->todo_scrollAreaWidgetContents->findChildren<ClickWidget*>();
    foreach (ClickWidget* clickw, clickw) {   delete clickw;  }
    //删除所有QToolButton
    QList<QToolButton*> btns = ui->todo_scrollAreaWidgetContents->findChildren<QToolButton*>();
    foreach (QToolButton* btn, btns) {   delete btn;  }
    //删除所有QLineEdit
    QList<QLineEdit*> ledit = ui->todo_scrollAreaWidgetContents->findChildren<QLineEdit*>();
    foreach (QLineEdit* ledit, ledit) {   delete ledit;  }
    //删除所有QFrame
    QList<QFrame*> frame = ui->todo_scrollAreaWidgetContents->findChildren<QFrame*>();
    foreach (QFrame* frame, frame) {   delete frame;  }

    ui->todo_scrollAreaWidgetContents->setFixedHeight(0);

    QSqlQuery query;  //新建一个查询的实例
    if (query.exec(QString("select * from 待办事项 where 所属界面 like 'todo%' && 所属工作区 = '%1' ").arg(working_place_text)))  //列出表的所有记录    //本次查询成功
    {
        QString name;
        while(query.next())
        {
            int h = ui->todo_scrollAreaWidgetContents->height();
            ui->todo_scrollAreaWidgetContents->setFixedHeight(h + 75);  //每增加一个工作区scroll的高度增加75
            name = query.value("待办事项名").toString();

            qDebug()<<name;

            //新增一个工作区
            ClickWidget *working_place = new ClickWidget(ui->todo_scrollAreaWidgetContents);
            working_place->resize(205,70);
            working_place->move(5,h+5);
            working_place->show();


            //工作区内添加icon
            QToolButton *icon = new QToolButton(working_place);
            icon->resize(30, 30);
            icon->setIcon(QIcon(":/icon/working_table.png"));
            icon->setIconSize(QSize(30, 30));
            icon->setAutoRaise(true);
            icon->setGeometry(15,16,30,30);
            icon->setStyleSheet("QToolButton{"
                                     "background:transparent;"
                                "}"
                        );
            icon->show();

            //工作区内添加文本
            QLineEdit *text = new QLineEdit(working_place);
            text->resize(60,30);
            text->setGeometry(65,16,100,30);
            text->setFrame(false);
            text->setText(name);
            text->setStyleSheet("QLineEdit{"
                                     "background:transparent;"
                                      "font: 12pt 'Microsoft YaHei';"
                                "}"
                        );
            text->show();

            //工作区添加右箭头
            QToolButton *right_arrow = new QToolButton(working_place);
            right_arrow->resize(30, 30);
            right_arrow->setIcon(QIcon(":/icon/right_arrow.png"));
            right_arrow->setIconSize(QSize(30, 30));
            right_arrow->setAutoRaise(true);
            right_arrow->setGeometry(180, 17, 30, 30);
            right_arrow->setStyleSheet("QToolButton{"
                                     "background:transparent;"
                                "}"
                        );
            right_arrow->show();

            //工作区添加底线
            QFrame *line = new QFrame(working_place);
            line->resize(205, 3);
            line->setGeometry(QRect(10, 68, 205, 3));
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            line->setStyleSheet("QFrame{"
                                     "border-top: 2px solid rgb(237, 238, 238);"
                                "}"
                        );
            line->raise();
            line->show();
        }

    }
    else  //如果查询失败，用下面的方法得到具体数据库返回的原因
    {
        QSqlError error = query.lastError();
        //display.append("From mysql database: " + error.databaseText());
    }
}
