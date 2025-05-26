#ifndef DECODEDIALOG_H
#define DECODEDIALOG_H

#include <QtWidgets/QDialog>

class EncodeDialog : public QDialog
{
    Q_OBJECT

public:
    EncodeDialog(QWidget *parent = 0);
    ~EncodeDialog();
};

#endif // DECODEDIALOG_H
