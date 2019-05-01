#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "userselectmodel.h"

namespace Ui {
class secondWindow;
}

class secondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondWindow(QWidget *parent = nullptr);
    ~secondWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::secondWindow *ui;
    userSelectModel *userSelect;
};

#endif // SECONDWINDOW_H
