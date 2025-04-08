#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_decode_clicked()
{

}

//goal for today is to just show entered text on screen in Graphics view
void MainWindow::on_pushButton_encode_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QGraphicsView *view = ui->graphicsView;

    QGraphicsScene *scene= new QGraphicsScene();
    view->setScene(scene);

    QGraphicsTextItem *graphicsText = new QGraphicsTextItem(text);
    graphicsText->setFont(QFont("Times", 20, QFont::Bold));
    graphicsText->setTextWidth(view->width());
    scene->addItem(graphicsText);
}

