#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);


    ui->pushButton_right->setEnabled(false);
    ui->pushButton_left->setEnabled(false);

    view = ui->graphicsView;
    scene= new QGraphicsScene();


    view->setScene(scene);
    graphicsText = new QGraphicsTextItem();

    scene->addItem(graphicsText);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setFlipCounter(int flipCounter){
    this->flipCounter=0;
    if(flipCounter>0)
        this->ui->pushButton_right->setEnabled(true);
}

void MainWindow::on_pushButton_decode_clicked(){
    QString text = ui->textEdit->toPlainText();
    this->state = new State(text.toStdString(), false);
//open a dialog window
    graphicsText->setPlainText(text);
    graphicsText->setFont(QFont("Times", 20, QFont::Bold));
    graphicsText->setTextWidth(view->width());
}

void MainWindow::on_pushButton_encode_clicked(){
    QString text = ui->textEdit->toPlainText();
    this->state = new State(text.toStdString(), true);
    this->setFlipCounter(this->state->distinctChars.size());
//open a dialog window
    graphicsText->setPlainText(text);
    graphicsText->setFont(QFont("Times", 20, QFont::Bold));
    graphicsText->setTextWidth(view->width());
}


void MainWindow::on_pushButton_right_clicked()
{
    this->flipCounter++;
    if(this->flipCounter >= this->state->distinctChars.size()) this->ui->pushButton_right->setEnabled(false);
    if(this->flipCounter > 0) this->ui->pushButton_left->setEnabled(true);
}


void MainWindow::on_pushButton_left_clicked()
{
    this->flipCounter--;
    if(this->flipCounter==0) this->ui->pushButton_left->setEnabled(false);
    if(this->flipCounter < this->state->distinctChars.size()) this->ui->pushButton_right->setEnabled(true);
}
