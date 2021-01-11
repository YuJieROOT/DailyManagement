#ifndef todoPage_H
#define todoPage_H

#include <QMainWindow>

#include "calendarPage.h"
#include "countdownPage.h"
#include "dustbinPage.h"
#include "logPage.h"
#include "searchPage.h"
#include "settingPage.h"
#include "userPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class todoPage; }
QT_END_NAMESPACE

class todoPage : public QMainWindow
{
    Q_OBJECT

public:
    todoPage(QWidget *parent = nullptr);
    ~todoPage();

private slots:
    void on_user_button_clicked();

    void on_calendar_button_clicked();

    void on_count_down_button_clicked();

    void on_dustbin_button_clicked();

    void on_search_button_clicked();

    void on_log_button_clicked();

    void on_setting_button_clicked();

private:
    Ui::todoPage *ui;
    QWidget *user_page, *todo_page, *calendar_page, *count_down_page, *dustbin_page, *search_page, *log_page, *setting_page;
};
#endif // todoPage_H
