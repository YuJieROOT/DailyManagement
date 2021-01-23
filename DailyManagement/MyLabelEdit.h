#ifndef MYLABELEDIT_H
#define MYLABELEDIT_H
/*
#include <QWidget>
#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MyLabelEdit; }
QT_END_NAMESPACE

class MyLabelEdit : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyLabelEdit(QWidget *parent);

    //void initWidget();

signals:

protected:
    bool EventFilter(QObject* obj, QEvent* evt);

};

*/
#include <QApplication>
#include <QFormLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QVBoxLayout>

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QFormLayout *lay = new QFormLayout(&w);

    MyEditableLabel el;
    lay->addRow("MyEditableLabel: ", &el);
    lay->addRow("QLineEdit: ", new QLineEdit);
    w.show();

    return a.exec();
}
*/
//#include "main.moc"

#endif // MYLABELEDIT_H
