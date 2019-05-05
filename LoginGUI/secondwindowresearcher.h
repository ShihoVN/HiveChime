
#ifndef SECONDWINDOWRESEARCHER_H
#define SECONDWINDOWRESEARCHER_H

#include <QDialog>
#include "createmodel.h"
#include "../RealTimeStream/mainwindowrt.h"

namespace Ui {
class secondWindowResearcher;
}

class secondWindowResearcher : public QDialog
{
    Q_OBJECT

public:
    explicit secondWindowResearcher(QWidget *parent = nullptr,QString *hivename=nullptr);
    ~secondWindowResearcher();
    bool viewModel;
    bool realTime;
    bool playSound;
    bool rawData;
    bool createModel;
    bool getPlaySound();

private slots:
    void on_pushButton_clicked();

private:
    Ui::secondWindowResearcher *ui;
    CreateModel *modelWindow;
    MainWindowRT *realTimeData;
};

#endif // SECONDWINDOWRESEARCHER_H
