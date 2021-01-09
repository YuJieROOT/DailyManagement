#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_user_off_clicked();

    void on_todo_off_clicked();

    void on_calendar_off_clicked();

    void on_count_down_off_clicked();

    void on_dustbin_off_clicked();

    void on_search_off_clicked();

    void on_log_off_clicked();

    void on_setting_off_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
