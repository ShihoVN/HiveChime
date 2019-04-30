#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"
#include "secondwindowresearcher.h"
#include "../Database/dbhivetable.h"
#include "../Database/tool.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    secondWindow *secWindowGen;
    secondWindowResearcher *reseacherWindow;
    Tool * dbtable=new Tool("database");
    DBHiveTable *hives= new DBHiveTable(dbtable,"HiveTable");
    int genChkBox;
};

#endif // MAINWINDOW_H
