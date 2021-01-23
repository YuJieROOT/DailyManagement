#ifndef CLICKWIDGET_H
#define CLICKWIDGET_H

#include <QWidget>
#include <QGridLayout>

class ClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClickWidget(QWidget *parent = nullptr);

    //void initWidget();

signals:
    void clicked();

protected:
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent*);
};

#endif // CLICKWIDGET_H
