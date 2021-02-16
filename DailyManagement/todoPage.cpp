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
    initDetailedBar(ui->left4);

    //connect(ui->new_todo_plainTextEdit, SIGNAL(returnPressed()), this, SLOT(newTodoBar()));
    //第三栏新建待办事项提示
    {
        QLabel *label = new QLabel(ui->new_todo_text);
        label->resize(150,25);
        label->setGeometry(10,5,150,25);
        label->setText("轻点以添加待办事项");
        label->setStyleSheet("QLabel{"
                             "color: rgb(192, 193, 197);"
                             "font: 10pt Microsoft YaHei;"
                            "}"
                    );
        label->setWindowFlags(Qt::WindowTransparentForInput|Qt::ToolTip);
        label->show();
    }


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
                   connect(working_place, SIGNAL(clicked(ClickWidget *)), this, SLOT(clickWorkingPlace(ClickWidget *)));

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
                   text->setGeometry(65,16,100,30);
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
    QString s0 = "";
    int num = findLatestNum("待办事项工作区", "工作区名", "char", "新建工作区");
        qDebug()<<num;
    if(num){s0 = QString::number(num);}
    QString s = QString("新建工作区") + s0;
    QSqlQuery query;  //新建一个查询的实例
    QString insert = QString("insert into 待办事项工作区(工作区名) values('%1')").arg(s);
    query.exec(insert);

    //新增一个工作区
    ClickWidget *working_place = new ClickWidget(ui->inbox_scrollAreaWidgetContents);
    working_place->resize(205,70);
    working_place->move(5,h+5);
    working_place->setStyleSheet("ClickWidget{"
                                 "border-radius:10px;"
                                 "}"
                );
    working_place->show();

    connect(working_place, SIGNAL(clicked(ClickWidget *)), this, SLOT(clickWorkingPlace(ClickWidget *)));


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
    text->setText(s);
    text->resize(100,30);
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

    //第三栏滚动区高度变0
    ui->todo_scrollAreaWidgetContents->setFixedHeight(0);

    initDetailedBar(ui->left4);

}

//点击第二栏
void todoPage::clickWorkingPlace(ClickWidget *w)
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

    //第四栏初始化
    initDetailedBar(ui->left4);

    //第三栏title显示当前工作区名称
    QString working_place_text = w->findChild<QLineEdit*>()->text();
    ui->new_todo_workPlace->setText(working_place_text);

    //初始化第三栏
    {
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

    ui->todo_scrollAreaWidgetContents->setFixedHeight(0);

    QSqlQuery query;  //新建一个查询的实例
    if (query.exec(QString("select * from 待办事项 where 所属界面 like 'todo%' && 所属工作区 = '%1' ").arg(working_place_text)))  //列出表的所有记录    //本次查询成功
    {
        while(query.next())
        {
            int h = ui->todo_scrollAreaWidgetContents->height();
            ui->todo_scrollAreaWidgetContents->setFixedHeight(h + 55);  //每增加一个工作区scroll的高度增加75


            //新增一个工作区
            ClickWidget *working_place = new ClickWidget(ui->todo_scrollAreaWidgetContents);
            working_place->resize(610,50);
            working_place->move(10,h+5);
            working_place->show();
                               connect(working_place, SIGNAL(clicked(ClickWidget *)), this, SLOT(clickTodoBar(ClickWidget *)));


            //工作区内添加icon
            QToolButton *icon = new QToolButton(working_place);
            icon->resize(15, 20);
            icon->setIcon(QIcon(":/icon/push_off.png"));
            icon->setIconSize(QSize(15, 15));
            icon->setAutoRaise(true);
            icon->setGeometry(10,15,15,20);
            icon->setStyleSheet("QToolButton{"
                                     "background:transparent;"
                                "}"
                        );
            icon->show();

            //工作区内添加待办事项名
            QString name = query.value("待办事项名").toString();
            qDebug()<<name;
            QLineEdit *text = new QLineEdit(working_place);
            text->resize(430,30);
            text->setGeometry(90,10,430,30);
            text->setFrame(false);
            text->setText(name);
            text->setStyleSheet("QLineEdit{"
                                     "background:transparent;"
                                      "font: 12pt 'Microsoft YaHei';"
                                "}"
                        );
            text->show();

            //工作区内添加目标时间
            QString day = query.value("目标时间").toString();
            qDebug()<<day;
            if(day != NULL)
            {
                QLineEdit *date = new QLineEdit(working_place);
                date->resize(430,30);
                date->setGeometry(530,17,68,20);
                date->setFrame(false);
                date->setText(day);
                date->setStyleSheet("QLineEdit{"
                                         "background:transparent;"
                                          "font: 10pt 'Microsoft YaHei';"
                                    "}"
                            );
                date->show();
            }

            //工作区添加完成按钮
            QToolButton *pane_off = new QToolButton(working_place);
            pane_off->resize(20, 20);
            pane_off->setIcon(QIcon(":/icon/pane_off.png"));
            pane_off->setIconSize(QSize(20, 20));
            pane_off->setAutoRaise(true);
            pane_off->setGeometry(45, 15, 20, 20);
            pane_off->setStyleSheet("QToolButton{"
                                     "background:transparent;"
                                "}"
                        );
            pane_off->show();

            //工作区添加底线
            QFrame *line = new QFrame(working_place);
            line->resize(510, 3);
            line->setGeometry(QRect(90, 48, 510, 3));
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            line->setStyleSheet("QFrame{"
                                     "border-top: 2px solid rgb(237, 238, 238);"
                                "}"
                        );
            line->raise();
            line->show();

            //待办事项存储编号
            qDebug()<<query.value("编号").toString();
            working_place->setText(query.value("编号").toString());
        }


    }
    else  //如果查询失败，用下面的方法得到具体数据库返回的原因
    {
        QSqlError error = query.lastError();
        //display.append("From mysql database: " + error.databaseText());
    }

}

//点击第三栏
void todoPage::clickTodoBar(ClickWidget *w)
{
    //删除第三栏所有deadline_pane_off
    QList<QToolButton*> deadline_pane_off_old = w->parent()->parent()->parent()->parent()->parent()->findChildren<QToolButton *>("deadline_pane_off");
    qDebug()<<w->parent()->parent()->parent()->parent()->parent()->findChildren<QToolButton *>("deadline_pane_off");
    foreach (QToolButton* btn, deadline_pane_off_old) {   delete btn;  }


    //第二栏选中分组改变颜色
    QList<ClickWidget*> clickw_countdown_bar = ui->todo_scrollAreaWidgetContents->findChildren<ClickWidget*>();
    foreach (ClickWidget* clickw_countdown_bar, clickw_countdown_bar)
    {
        clickw_countdown_bar->setStyleSheet("ClickWidget{"
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

    //第三栏显示

    //初始化页面消失
    QLabel *pix = ui->left4->findChild<QLabel*>("inital_pix");
    if(pix!=NULL)
    {
        delete pix;
    }

    QString working_place_text = w->getText();
qDebug()<<working_place_text;
    QSqlQuery query;  //新建一个查询的实例
    if (query.exec(QString("select * from 待办事项 where 编号 = '%1' ").arg(working_place_text)))  //列出表的所有记录    //本次查询成功
    {
        QString name;
        while(query.next())
        {
            ui->left4->setText(w->getText());
            ui->left4->setNum(w->getnum());
            //deadline_pane_off显示
            QToolButton *deadline_pane_off = new QToolButton(ui->deadline_in);
            deadline_pane_off->setProperty("objectName","deadline_pane_off");
            deadline_pane_off->setIcon(QIcon(":/icon/pane_off.png"));
            deadline_pane_off->setAutoRaise(true);
            deadline_pane_off->setIconSize(QSize(25,25));
            deadline_pane_off->setGeometry(10,12,25,25);
            deadline_pane_off->setStyleSheet("QToolButton{"
                                                "background:transparent;"
                                             "}"
                        );
            deadline_pane_off->show();
            connect(deadline_pane_off, &QToolButton::clicked, w, &ClickWidget::accomplish);
            connect(deadline_pane_off,&QToolButton::clicked,deadline_pane_off,[=](){
                deadline_pane_off->setIcon(QIcon(":/icon/pane_on.png"));
            });
            qDebug()<<w->parent()->parent()->parent()->parent()->parent()->findChildren<QToolButton *>("deadline_pane_off");

            //deadline显示
            QString deadline = query.value("目标时间").toString();
            ui->deadline_date->setText(deadline);
            qDebug()<<deadline;

            //显示待办栏标题
            QString describe_title = w->findChild<QLineEdit*>()->text();
            ui->title->setText(describe_title);
            qDebug()<<describe_title;
            //显示待办栏详情
            QString describe_detial = query.value("详细内容").toString();
            ui->detial->setPlainText(describe_detial);
            qDebug()<<describe_detial;
            //delete显示
            QToolButton *delete_icon = new QToolButton(ui->describe);
            delete_icon->setProperty("objectName","delete_icon");
            delete_icon->setIcon(QIcon(":/icon/delete.png"));
            delete_icon->setAutoRaise(true);
            delete_icon->setIconSize(QSize(35,35));
            delete_icon->setGeometry(230,550,35,35);
            delete_icon->setStyleSheet("QToolButton{"
                                                "background:transparent;"
                                             "}"
                        );
            delete_icon->show();

        }
    }
    else  //如果查询失败，用下面的方法得到具体数据库返回的原因
    {
        QSqlError error = query.lastError();
        //display.append("From mysql database: " + error.databaseText());
    }

}

//新建待办事项
void todoPage::on_new_todo_lineEdit_editingFinished()
{
    if(ui->new_todo_lineEdit->hasFocus())
    {
        QString s = ui->new_todo_lineEdit->text();
        if(s != "")
        {
            qDebug() << s;

            int num = findLatestNum("待办事项", "编号", "int");
            qDebug() <<  num;
            QSqlQuery query;  //新建一个查询的实例
            QString insert = QString("insert into 待办事项(编号, 待办事项名, 所属工作区, 所属界面) values(%1, '%2', '%3', 'todo')").arg(num).arg(s).arg(ui->new_todo_workPlace->text());
            query.exec(insert);

            int h = ui->todo_scrollAreaWidgetContents->height();
            ui->todo_scrollAreaWidgetContents->setFixedHeight(h + 55);  //每增加一个工作区scroll的高度增加75


            //新增一个工作区
            ClickWidget *working_place = new ClickWidget(ui->todo_scrollAreaWidgetContents);
            working_place->resize(610,50);
            working_place->move(10,h+5);
            working_place->show();
                               connect(working_place, SIGNAL(clicked(ClickWidget *)), this, SLOT(clickTodoBar(ClickWidget *)));


            //工作区内添加icon
            QToolButton *icon = new QToolButton(working_place);
            icon->resize(15, 20);
            icon->setIcon(QIcon(":/icon/push_off.png"));
            icon->setIconSize(QSize(15, 15));
            icon->setAutoRaise(true);
            icon->setGeometry(10,15,15,20);
            icon->setStyleSheet("QToolButton{"
                                     "background:transparent;"
                                "}"
                        );
            icon->show();

            //工作区内添加待办事项名
            QString name = s;
            qDebug()<<name;
            QLineEdit *text = new QLineEdit(working_place);
            text->resize(430,30);
            text->setGeometry(90,10,430,30);
            text->setFrame(false);
            text->setText(name);
            text->setStyleSheet("QLineEdit{"
                                     "background:transparent;"
                                      "font: 12pt 'Microsoft YaHei';"
                                "}"
                        );
            text->show();
/*
            //工作区内添加目标时间
            QString day = query.value("目标时间").toString();
            qDebug()<<day;
            if(day != NULL)
            {
                QLineEdit *date = new QLineEdit(working_place);
                date->resize(430,30);
                date->setGeometry(530,17,68,20);
                date->setFrame(false);
                date->setText(day);
                date->setStyleSheet("QLineEdit{"
                                         "background:transparent;"
                                          "font: 10pt 'Microsoft YaHei';"
                                    "}"
                            );
                date->show();
            }
*/
            //工作区添加完成按钮
            QToolButton *pane_off = new QToolButton(working_place);
            pane_off->resize(20, 20);
            pane_off->setIcon(QIcon(":/icon/pane_off.png"));
            pane_off->setIconSize(QSize(20, 20));
            pane_off->setAutoRaise(true);
            pane_off->setGeometry(45, 15, 20, 20);
            pane_off->setStyleSheet("QToolButton{"
                                     "background:transparent;"
                                "}"
                        );
            pane_off->show();

            //工作区添加底线
            QFrame *line = new QFrame(working_place);
            line->resize(510, 3);
            line->setGeometry(QRect(90, 48, 510, 3));
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            line->setStyleSheet("QFrame{"
                                     "border-top: 2px solid rgb(237, 238, 238);"
                                "}"
                        );
            line->raise();
            line->show();

            //待办事项存储编号
            qDebug()<<QString::number(num);
            working_place->setText(QString::number(num));
            working_place->setNum(num);
        }



        ui->new_todo_lineEdit->setText("轻点以添加待办事项");
        /*
        QLabel *label = new QLabel(ui->new_todo_text);
        label->resize(150,25);
        label->setGeometry(10,5,150,25);
        label->setText("轻点以添加待办事项");
        label->setStyleSheet("QLabel{"
                             "color: rgb(192, 193, 197);"
                             "font: 10pt Microsoft YaHei;"
                            "}"
                    );
        label->window()->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->show();
        */
        ui->new_todo_lineEdit->setText("");
        ui->centralwidget->setFocus();
    }
}

void todoPage::on_new_todo_lineEdit_textChanged(const QString &arg1)
{
    //ui->add_todo_label->setText("");
    //删除所有QLabel
    QList<QLabel*> label = ui->new_todo_text->findChildren<QLabel*>();
    foreach (QLabel* label, label) {   delete label;  }
}
//找到table表field字段下like s%的没有记录的最小数字
int todoPage::findLatestNum(QString table, QString field, QString type, QString s)
{
    QSqlQuery query;  //新建一个查询的实例
    int num = 0;
    QString select;
    if(type == "int"){select = QString("select * from %1 order by %2 asc").arg(table).arg(field);}
    else if(type == "char"){select = QString("select * from %1 where %2 like '3%' order by %2 asc").arg(table).arg(field).arg(s);}
    if (query.exec(select))  //列出表的所有记录    //本次查询成功
    {
        while(query.next())
        {
            QString n = query.value(field).toString().mid(s.length());
            int num_now = 0;
            if(n != "")num_now = n.toInt();
            //qDebug()<<num<<"  "<<num_now<<endl;
            if(num == num_now)
            {
                num++;
            }
            else
            {
                break;
            }
        }
    }
    else  //如果查询失败，用下面的方法得到具体数据库返回的原因
    {
        QSqlError error = query.lastError();
        //display.append("From mysql database: " + error.databaseText());
    }
    return num;
}

void todoPage::on_subtask_lineEdit_2_editingFinished()
{
    if(ui->subtask_lineEdit_2->hasFocus())
    {
        QString s = ui->subtask_lineEdit_2->text();
        if(s != "")
        {
            qDebug() << s;

            int num = findLatestNum("待办事项", "编号", "int");
            qDebug() <<  num;

            int fatherNum = ui->left4->getnum();
            QSqlQuery query;  //新建一个查询的实例
            QString insert = QString("insert into 待办事项(编号, 待办事项名, 所属工作区, 所属界面, 父事项编号) values(%1, '%2', '%3', 'todo', %4)").arg(num).arg(s).arg(ui->new_todo_workPlace->text()).arg(fatherNum);
            qDebug()<<insert;
            qDebug()<<query.exec(insert);
            QString select = QString("select 子事项数目 in 待办事项 where 编号 = %1").arg(fatherNum);
            int sum = query.exec(select)+1;
            QString update = QString("update 待办事项 set 子事项数目 = %1 where 编号 = %2" ).arg(sum).arg(fatherNum);

            int h = ui->todo_scrollAreaWidgetContents->height();
            ui->todo_scrollAreaWidgetContents->setFixedHeight(h + 55);  //每增加一个工作区scroll的高度增加75


            //新增一个工作区
            ClickWidget *working_place = new ClickWidget(ui->todo_scrollAreaWidgetContents);
            working_place->resize(610,50);
            working_place->move(10,h+5);
            working_place->show();
                               connect(working_place, SIGNAL(clicked(ClickWidget *)), this, SLOT(clickTodoBar(ClickWidget *)));


            //工作区内添加icon
            QToolButton *icon = new QToolButton(working_place);
            icon->resize(15, 20);
            icon->setIcon(QIcon(":/icon/push_off.png"));
            icon->setIconSize(QSize(15, 15));
            icon->setAutoRaise(true);
            icon->setGeometry(10,15,15,20);
            icon->setStyleSheet("QToolButton{"
                                     "background:transparent;"
                                "}"
                        );
            icon->show();

            //工作区内添加待办事项名
            QString name = s;
            qDebug()<<name;
            QLineEdit *text = new QLineEdit(working_place);
            text->resize(430,30);
            text->setGeometry(90,10,430,30);
            text->setFrame(false);
            text->setText(name);
            text->setStyleSheet("QLineEdit{"
                                     "background:transparent;"
                                      "font: 12pt 'Microsoft YaHei';"
                                "}"
                        );
            text->show();
/*
            //工作区内添加目标时间
            QString day = query.value("目标时间").toString();
            qDebug()<<day;
            if(day != NULL)
            {
                QLineEdit *date = new QLineEdit(working_place);
                date->resize(430,30);
                date->setGeometry(530,17,68,20);
                date->setFrame(false);
                date->setText(day);
                date->setStyleSheet("QLineEdit{"
                                         "background:transparent;"
                                          "font: 10pt 'Microsoft YaHei';"
                                    "}"
                            );
                date->show();
            }
*/
            //工作区添加完成按钮
            QToolButton *pane_off = new QToolButton(working_place);
            pane_off->resize(20, 20);
            pane_off->setIcon(QIcon(":/icon/pane_off.png"));
            pane_off->setIconSize(QSize(20, 20));
            pane_off->setAutoRaise(true);
            pane_off->setGeometry(45, 15, 20, 20);
            pane_off->setStyleSheet("QToolButton{"
                                     "background:transparent;"
                                "}"
                        );
            pane_off->show();

            //工作区添加底线
            QFrame *line = new QFrame(working_place);
            line->resize(510, 3);
            line->setGeometry(QRect(90, 48, 510, 3));
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            line->setStyleSheet("QFrame{"
                                     "border-top: 2px solid rgb(237, 238, 238);"
                                "}"
                        );
            line->raise();
            line->show();

            //待办事项存储编号
            qDebug()<<QString::number(num);
            working_place->setText(QString::number(num));
            working_place->setNum(num);
        }


        ui->subtask_lineEdit_2->setText("");
        ui->centralwidget->setFocus();
    }
}
