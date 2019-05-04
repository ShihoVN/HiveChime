#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"
#include "secondwindowresearcher.h"
#include "../Database/dbhivetable.h"
#include "../Database/tool.h"
#include "../Graphics/mainwindowanimate.h"
#include "intro.h"
#include <QMediaPlayer>

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

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString hiveid;
    secondWindow *secWindowGen;
    secondWindowResearcher *reseacherWindow;
    Tool * dbtable=new Tool("database");
    DBHiveTable *hives= new DBHiveTable(dbtable,"HiveTable");
    int genChkBox;
    Intro *introWindow;
};

#endif // MAINWINDOW_H
