#ifndef DECODEDIALOG_H
#define DECODEDIALOG_H

#include <QtWidgets/QDialog>

class DecodeDialog : public QDialog
{
    Q_OBJECT

public:
    DecodeDialog(QWidget *parent = 0);
    ~DecodeDialog();
};

#endif // DECODEDIALOG_H
