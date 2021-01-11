#ifndef DUSTBINPAGE_H
#define DUSTBINPAGE_H

#include <QMainWindow>

#include "calendarPage.h"
#include "countdownPage.h"
#include "logPage.h"
#include "searchPage.h"
#include "settingPage.h"
#include "todoPage.h"
#include "userPage.h"

namespace Ui {
class dustbinPage;
}

class dustbinPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit dustbinPage(QWidget *parent = nullptr);
    ~dustbinPage();

private:
    Ui::dustbinPage *ui;
};

#endif // DUSTBINPAGE_H
