#include "mainwindow.h"
#include "decodedialog.h"
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
    DecodeDialog dialog = new DecodeDialog();
    dialog.exec();
//     QString text = ui->textEdit->toPlainText();
//     this->state = new State(text.toStdString(), true);
//     this->setFlipCounter(this->state->distinctChars.size());
// //open a dialog window
//     graphicsText->setPlainText(text);
//     graphicsText->setFont(QFont("Times", 20, QFont::Bold));
//     graphicsText->setTextWidth(view->width());
}

void MainWindow::on_pushButton_right_clicked()
{
    this->flipCounter++;
    QString text = ui->textEdit->toPlainText();
    QString coloredText;
    char current = this->state->pointerToChar[flipCounter-1];

    for(int i = 0; i< text.length(); i++){
        QString letter = text[i];
        char currentLetter = letter.toLower().toStdString().c_str()[0];
        QString color = "red";
        QString color1 = "green";
        if(letter.toLower() == current)
            coloredText += QString("<span style='color:%1;'>%2</span>").arg(color, letter);
        else if(this->state->distinctChars[currentLetter] < this->flipCounter)
            coloredText += QString("<span style='color:%1;'>%2</span>").arg(color1, letter);
        else
            coloredText += QString("<span>%1</span>").arg(letter);
    }

    graphicsText->setHtml(coloredText);
    if(this->flipCounter >= this->state->distinctChars.size()+1) this->ui->pushButton_right->setEnabled(false);
    if(this->flipCounter > 0) this->ui->pushButton_left->setEnabled(true);
}

void MainWindow::on_pushButton_left_clicked()//make this be in same function
{
    this->flipCounter--;
    QString text = ui->textEdit->toPlainText();
    QString coloredText;
    char current = this->state->pointerToChar[flipCounter-1];

    for(int i = 0; i< text.length(); i++){
        QString letter = text[i];
        char currentLetter = letter.toLower().toStdString().c_str()[0];
        QString color = "red";
        QString color1 = "green";
        if(letter.toLower() == current)
            coloredText += QString("<span style='color:%1;'>%2</span>").arg(color, letter);
        else if(this->state->distinctChars[currentLetter] < this->flipCounter)
            coloredText += QString("<span style='color:%1;'>%2</span>").arg(color1, letter);
        else
            coloredText += QString("<span>%1</span>").arg(letter);
    }

    graphicsText->setHtml(coloredText);
    if(this->flipCounter==0) this->ui->pushButton_left->setEnabled(false);
    if(this->flipCounter < this->state->distinctChars.size()) this->ui->pushButton_right->setEnabled(true);
}
