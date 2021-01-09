#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_user_off_clicked()
{
    ui->user_off->setIcon(QIcon(":/icon/user_on.png"));
    ui->todo_off->setIcon(QIcon(":/icon/todo_off.png"));
    ui->calendar_off->setIcon(QIcon(":/icon/calendar_off .png"));
    ui->count_down_off->setIcon(QIcon(":/icon/count_down_off.png"));
    ui->dustbin_off->setIcon(QIcon(":/icon/dustbin_off.png"));
    ui->search_off->setIcon(QIcon(":/icon/search_off.png"));
    ui->log_off->setIcon(QIcon(":/icon/log_off.png"));
    ui->setting_off->setIcon(QIcon(":/icon/setting_off.png"));
}

void MainWindow::on_todo_off_clicked()
{
    ui->user_off->setIcon(QIcon(":/icon/user_off.png"));
    ui->todo_off->setIcon(QIcon(":/icon/todo_on.png"));
    ui->calendar_off->setIcon(QIcon(":/icon/calendar_off .png"));
    ui->count_down_off->setIcon(QIcon(":/icon/count_down_off.png"));
    ui->dustbin_off->setIcon(QIcon(":/icon/dustbin_off.png"));
    ui->search_off->setIcon(QIcon(":/icon/search_off.png"));
    ui->log_off->setIcon(QIcon(":/icon/log_off.png"));
    ui->setting_off->setIcon(QIcon(":/icon/setting_off.png"));
}

void MainWindow::on_calendar_off_clicked()
{
    ui->user_off->setIcon(QIcon(":/icon/user_off.png"));
    ui->todo_off->setIcon(QIcon(":/icon/todo_off.png"));
    ui->calendar_off->setIcon(QIcon(":/icon/calendar_on.png"));
    ui->count_down_off->setIcon(QIcon(":/icon/count_down_off.png"));
    ui->dustbin_off->setIcon(QIcon(":/icon/dustbin_off.png"));
    ui->search_off->setIcon(QIcon(":/icon/search_off.png"));
    ui->log_off->setIcon(QIcon(":/icon/log_off.png"));
    ui->setting_off->setIcon(QIcon(":/icon/setting_off.png"));
}

void MainWindow::on_count_down_off_clicked()
{
    ui->user_off->setIcon(QIcon(":/icon/user_off.png"));
    ui->todo_off->setIcon(QIcon(":/icon/todo_off.png"));
    ui->calendar_off->setIcon(QIcon(":/icon/calendar_off .png"));
    ui->count_down_off->setIcon(QIcon(":/icon/count_down_on.png"));
    ui->dustbin_off->setIcon(QIcon(":/icon/dustbin_off.png"));
    ui->search_off->setIcon(QIcon(":/icon/search_off.png"));
    ui->log_off->setIcon(QIcon(":/icon/log_off.png"));
    ui->setting_off->setIcon(QIcon(":/icon/setting_off.png"));
}

void MainWindow::on_dustbin_off_clicked()
{
    ui->user_off->setIcon(QIcon(":/icon/user_off.png"));
    ui->todo_off->setIcon(QIcon(":/icon/todo_off.png"));
    ui->calendar_off->setIcon(QIcon(":/icon/calendar_off .png"));
    ui->count_down_off->setIcon(QIcon(":/icon/count_down_off.png"));
    ui->dustbin_off->setIcon(QIcon(":/icon/dustbin_on.png"));
    ui->search_off->setIcon(QIcon(":/icon/search_off.png"));
    ui->log_off->setIcon(QIcon(":/icon/log_off.png"));
    ui->setting_off->setIcon(QIcon(":/icon/setting_off.png"));
}


void MainWindow::on_search_off_clicked()
{
    ui->user_off->setIcon(QIcon(":/icon/user_off.png"));
    ui->todo_off->setIcon(QIcon(":/icon/todo_off.png"));
    ui->calendar_off->setIcon(QIcon(":/icon/calendar_off .png"));
    ui->count_down_off->setIcon(QIcon(":/icon/count_down_off.png"));
    ui->dustbin_off->setIcon(QIcon(":/icon/dustbin_off.png"));
    ui->search_off->setIcon(QIcon(":/icon/search_on.png"));
    ui->log_off->setIcon(QIcon(":/icon/log_off.png"));
    ui->setting_off->setIcon(QIcon(":/icon/setting_off.png"));
}

void MainWindow::on_log_off_clicked()
{
    ui->user_off->setIcon(QIcon(":/icon/user_off.png"));
    ui->todo_off->setIcon(QIcon(":/icon/todo_off.png"));
    ui->calendar_off->setIcon(QIcon(":/icon/calendar_off .png"));
    ui->count_down_off->setIcon(QIcon(":/icon/count_down_off.png"));
    ui->dustbin_off->setIcon(QIcon(":/icon/dustbin_off.png"));
    ui->search_off->setIcon(QIcon(":/icon/search_off.png"));
    ui->log_off->setIcon(QIcon(":/icon/log_on.png"));
    ui->setting_off->setIcon(QIcon(":/icon/setting_off.png"));
}

void MainWindow::on_setting_off_clicked()
{
    ui->user_off->setIcon(QIcon(":/icon/user_off.png"));
    ui->todo_off->setIcon(QIcon(":/icon/todo_off.png"));
    ui->calendar_off->setIcon(QIcon(":/icon/calendar_off .png"));
    ui->count_down_off->setIcon(QIcon(":/icon/count_down_off.png"));
    ui->dustbin_off->setIcon(QIcon(":/icon/dustbin_off.png"));
    ui->search_off->setIcon(QIcon(":/icon/search_off.png"));
    ui->log_off->setIcon(QIcon(":/icon/log_off.png"));
    ui->setting_off->setIcon(QIcon(":/icon/setting_on.png"));
}
