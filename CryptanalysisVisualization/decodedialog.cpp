#include "EncodeDialog.h"
#include <QLabel>

EncodeDialog::EncodeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Set Encode ");
    setWindowFlags(Qt::Dialog);
    setWindowModality(Qt::WindowModal);

    resize(300, 100);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setSizePolicy(sizePolicy);
    setMinimumSize(QSize(300, 100));
    setMaximumSize(QSize(300, 100));

    QLabel* myLabel = new QLabel(this);
    myLabel->setText("My Dialog!");
}

EncodeDialog::~EncodeDialog()
{ }
