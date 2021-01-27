#include "countdownPage.h"
#include "ui_countdownPage.h"
#include <QTime>

#include "ClickWidget.h"
#include <QScrollArea>
#include <QScrollBar>
#include <QtSql>
#include <QWidget>
#include "ui_logic.h"

countDownPage::countDownPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::countDownPage)
{
    ui->setupUi(this);
    initUI(this);

    //第二栏读数据库显示
        {

               ui->countdown_scrollAreaWidgetContents->setFixedHeight(0);
               QSqlQuery query;  //新建一个查询的实例

               if (query.exec("select * from 待办事项 where 目标时间 is not null "))  //列出表的所有记录    //本次查询成功
               {
                   QString countdown_title;
                   QString countdown_describe;

                   while(query.next())
                   {
                       int h = ui->countdown_scrollAreaWidgetContents->height();
                       ui->countdown_scrollAreaWidgetContents->setFixedHeight(h + 105);  //每增加一个工作区scroll的高度增加105
                       countdown_title = query.value("待办事项名").toString();
                       countdown_describe = query.value("详细内容").toString();

                       qDebug()<<countdown_title;

                       //新增一个countdown_bar
                       ClickWidget *countdown_bar=new ClickWidget(ui->countdown_scrollAreaWidgetContents);
                       countdown_bar->setMinimumSize(835,100);
                       countdown_bar->setGeometry(10,h+5,835,100);
                       countdown_bar->setStyleSheet("ClickWidget{"
                                                    "border-radius:10px;"
                                                    "}"
                                   );

                       //countdown_bar内添加push_button
                       QToolButton *push_button = new QToolButton(countdown_bar);
                       push_button->setIcon(QIcon(":/icon/push_off.png"));
                       push_button->setAutoRaise(true);
                       push_button->setIconSize(QSize(20,20));
                       push_button->setGeometry(30,20,20,20);
                       push_button->setStyleSheet("QToolButton{"
                                                "background:transparent;"
                                           "}"
                                   );

                       //countdown_bar内添加pane_off
                       QToolButton *pane_off = new QToolButton(countdown_bar);
                       pane_off->setIcon(QIcon(":/icon/pane_off.png"));
                       pane_off->setAutoRaise(true);
                       pane_off->setIconSize(QSize(25,25));
                       pane_off->setGeometry(60,20,25,25);
                       pane_off->setStyleSheet("QToolButton{"
                                                "background:transparent;"
                                           "}"
                                   );

                       //countdown_bar内添加title
                       QLineEdit *title = new QLineEdit(countdown_bar);
                       title->setFocusPolicy(Qt::NoFocus);
                       title->setFrame(false);
                       title->setText(countdown_title);
                       title->setGeometry(100,15,610,30);
                       title->setStyleSheet("QLineEdit{"
                                                "background:transparent;"
                                                "font: 20px 'Microsoft YaHei';"
                                                "}"
                                   );

                       //countdown_bar内添加describe
                       QPlainTextEdit *describe = new QPlainTextEdit(countdown_bar);
                       describe->setFocusPolicy(Qt::NoFocus);
                       describe->setFrameShape(QFrame::NoFrame);
                       describe->setPlainText(countdown_describe);
                       describe->setGeometry(100,45,320,45);
                       describe->setStyleSheet("QPlainTextEdit{"
                                                    "background:transparent;"
                                                    "font: 13px 'Microsoft YaHei';"
                                                    "color: rgb(112, 112, 112);"
                                      "}"
                                   );

                       //countdown_bar内添加countdown
                       QDate D1 = QDate::currentDate();
                       QDate D2 = query.value("目标时间").toDate();
                       QLineEdit *countdown = new QLineEdit(countdown_bar);
                       countdown->setFocusPolicy(Qt::NoFocus);
                       countdown->setFrame(false);
                       if(!D2.isNull())
                       {
                           int t = D1.daysTo(D2);
                           QString time = QString("%1").arg(t);
                           countdown->setText(time);
                       }

                       countdown->setGeometry(760,28,70,44);
                       countdown->setStyleSheet("QLineEdit{"
                                                    "background:transparent;"
                                                    "color: rgb(255, 153, 0);"
                                                    "font: 30px 'STHupo';"
                                      "}"
                                   );

                       //countdown_bar添加底线
                       QFrame *line = new QFrame(countdown_bar);
                       line->setGeometry(QRect(100,95,720,3));
                       line->setFrameShape(QFrame::HLine);
                       line->setFrameShadow(QFrame::Sunken);
                       line->setStyleSheet("QFrame{"
                                                "border-top: 2px solid rgb(237, 238, 238);"
                                           "}"
                                   );
                       line->raise();

                       connect(countdown_bar, SIGNAL(clicked(ClickWidget *)), this, SLOT(clickMyWidget(ClickWidget *)));

                   }

               }
               else  //如果查询失败，用下面的方法得到具体数据库返回的原因
               {
                   QSqlError error = query.lastError();
                   //display.append("From mysql database: " + error.databaseText());
               }
        }
    
    //第三栏初始化
    {
        QLabel *inital_pix = new QLabel(ui->left3);
        inital_pix->setPixmap(QPixmap(":/icon/inital.png"));
        inital_pix->setScaledContents(true);
        inital_pix->setGeometry(0,0,274,675);
    }
}

countDownPage::~countDownPage()
{
    delete ui;
}

void countDownPage::on_user_button_clicked()
{
    userPage *w = new userPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_todo_button_clicked()
{
    todoPage *w = new todoPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_calendar_button_clicked()
{
    calendarPage *w = new calendarPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_dustbin_button_clicked()
{
    dustbinPage *w = new dustbinPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_search_button_clicked()
{
    searchPage *w = new searchPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_log_button_clicked()
{
    logPage *w = new logPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_setting_button_clicked()
{
    settingPage *w = new settingPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::clickMyWidget(ClickWidget *w)
{
    //第二栏选中分组改变颜色
    QList<ClickWidget*> clickw_countdown_bar = ui->countdown_scrollAreaWidgetContents->findChildren<ClickWidget*>();
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
    QList<QLabel*> list = ui->left3->findChildren<QLabel*>();
    for(int i=0;i<list.count();i++)
    {
        QLabel *label = list.at(i);
        if(label->objectName()=="")
            delete label;
    }



    //deadline显示
    QList<QLineEdit *> t = w->findChildren<QLineEdit*>();
    QString countdown = t.at(1)->text();
    QDate D1 = QDate::currentDate();
    qDebug()<<D1.toString();
    double val = countdown.toDouble();
    D1 = D1.addDays(val);
    QString deadline = D1.toString();
    ui->deadline_date->setText(deadline);

    //显示待办栏标题
    QString describe_title = w->findChild<QLineEdit*>()->text();
    ui->title->setText(describe_title);

    //显示待办栏详情
    QString describe_detial = w->findChild<QPlainTextEdit*>()->toPlainText();
    ui->detial->setPlainText(describe_detial);
}
