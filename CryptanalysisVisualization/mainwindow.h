#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsTextItem>

#include "state.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    State* state;
    QGraphicsTextItem *graphicsText;
    QGraphicsView *view;
    QGraphicsScene *scene;
    void setFlipCounter(int flipCounter);
    int getFlipCounter();

private slots:
    void on_pushButton_decode_clicked();

    void on_pushButton_encode_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_left_clicked();

private:
    int flipCounter;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
