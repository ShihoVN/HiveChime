#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "userselectmodel.h"
//#include <QMediaPlayer>

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
    bool playSound;

};

#endif // SECONDWINDOW_H
