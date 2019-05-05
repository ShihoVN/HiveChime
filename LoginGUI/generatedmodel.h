#ifndef GENERATEDMODEL_H
#define GENERATEDMODEL_H

#include <QDialog>
#include <iostream>
#include <string>
#include <algorithm>
#include <QMessageBox>
#include "../Data/beegeneration.h"
#include "../Data/datacontainer.h"
#include "../Data/datadecoder.h"
#include "../Database/dbmodeltable.h"

using namespace  std;
namespace Ui {
class GeneratedModel;
}

class GeneratedModel : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratedModel(QWidget *parent = nullptr,QString* hiveid=nullptr,string* modelid=nullptr,string* size=nullptr,string *date=nullptr,string *time=nullptr,string *duration=nullptr,Tool*dbtool=nullptr);
    map<int,std::pair<int,int>> Timetable(string interval);
    map<int,std::pair<int,int>> Timetable_enter(string interval);
    ~GeneratedModel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::GeneratedModel *ui;
    DataContainer *beelog;
    Tool *dbtool;
    string modelids;
    string hiveids;
    string setendDate(string time,string duration);
    vector<string> checkmodel();
};

#endif // GENERATEDMODEL_H
