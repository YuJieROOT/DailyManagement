#ifndef LOGPAGE_H
#define LOGPAGE_H

#include <QMainWindow>

#include "calendarPage.h"
#include "countdownPage.h"
#include "dustbinPage.h"
#include "searchPage.h"
#include "settingPage.h"
#include "todoPage.h"
#include "userPage.h"

namespace Ui {
class logPage;
}

class logPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit logPage(QWidget *parent = nullptr);
    ~logPage();

private:
    Ui::logPage *ui;
};

#endif // LOGPAGE_H
