#ifndef ENCODEDIALOG_H
#define ENCODEDIALOG_H

#include <QtWidgets/QDialog>

class EncodeDialog : public QDialog
{
    Q_OBJECT

public:
    EncodeDialog(QWidget *parent = 0);
    ~EncodeDialog();
};

#endif // ENCODEDIALOG_H
