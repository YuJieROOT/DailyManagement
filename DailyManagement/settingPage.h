#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include <QMainWindow>

#include "calendarPage.h"
#include "countdownPage.h"
#include "dustbinPage.h"
#include "logPage.h"
#include "searchPage.h"
#include "todoPage.h"
#include "userPage.h"

namespace Ui {
class settingPage;
}

class settingPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit settingPage(QWidget *parent = nullptr);
    ~settingPage();

private:
    Ui::settingPage *ui;
};

#endif // SETTINGPAGE_H
