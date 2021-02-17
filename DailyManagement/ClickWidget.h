#ifndef CLICKWIDGET_H
#define CLICKWIDGET_H

#include <QWidget>
#include <QGridLayout>

class ClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClickWidget(QWidget *parent = nullptr):
        QWidget(parent)
    {
        //this->setStyleSheet("background: #32CC99;");
        setAttribute(Qt::WA_StyledBackground);
    }

    QString getText();
    int getnum();
    void setText(QString);
    void setNum(int);
    void accomplish();
    void delete_countdown();
    //void initWidget();

signals:
    void clicked(ClickWidget *);
    void update_countdown();

protected:
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent*);
private:
    QString text;
    int num;
};

#endif // CLICKWIDGET_H
