#include "MyLabelEdit.h"
#include <QEvent>
#include <QtGui>

/*
MyLabelEdit::MyLabelEdit(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MyLabelEdit)
{
ui.setupUi(this);
ui.label->setStyleSheet("background:yellow");
ui.label->installEventFilter(this);
ui.lineEdit->installEventFilter(this);
}


bool MyLabelEdit::EventFilter(QObject* obj, QEvent* evt)
{

    if (obj == ui.label)
    {
        if (evt->type() == QEvent::MouseButtonDblClick)
        {
            ui.lineEdit->setText(ui.label->text());
            ui.stackedWidget->setCurrentIndex(1);
        }
    }
    else if (obj == ui.lineEdit)
    {
        if (evt->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyevt = static_cast<QKeyEvent*>(evt);
            if ((keyevt->key() == Qt::Key_Return) ||
                (keyevt->key() == Qt::Key_Escape) ||
                (keyevt->key() == Qt::Key_Enter))   // Qt::Key_Return是大键盘的回车键 Qt::Key_Enter是小键盘的回车键
            {
                ui.label->setText(ui.lineEdit->text());
                ui.stackedWidget->setCurrentIndex(0);
            }
        }
        else if (evt->type() == QEvent::FocusOut)
        {
            ui.label->setText(ui.lineEdit->text());
            ui.stackedWidget->setCurrentIndex(0);
        }
    }

    return QMainWindow::eventFilter(obj, evt);
}

*/
