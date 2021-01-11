#ifndef USERPAGE_H
#define USERPAGE_H

#include <QMainWindow>

#include "calendarPage.h"
#include "countdownPage.h"
#include "dustbinPage.h"
#include "logPage.h"
#include "searchPage.h"
#include "settingPage.h"
#include "todoPage.h"

namespace Ui {
class userPage;
}

class userPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit userPage(QWidget *parent = nullptr);
    ~userPage();

private slots:
    void on_todo_button_clicked();

    void on_calendar_button_clicked();

private:
    Ui::userPage *ui;
};

#endif // USERPAGE_H
