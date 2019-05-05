#ifndef GENERATEDMODEL_H
#define GENERATEDMODEL_H

#include <QDialog>
#include <iostream>
#include <string>
#include "../Data/beegeneration.h"
#include "../Data/datacontainer.h"
#include "../Data/datadecoder.h"
using namespace  std;
namespace Ui {
class GeneratedModel;
}

class GeneratedModel : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratedModel(QWidget *parent = nullptr,string* modelid=nullptr,string* size=nullptr,string *date=nullptr,string *time=nullptr,string *duration=nullptr,Tool*dbtool=nullptr);
    map<int,std::pair<int,int>> Timetable(string interval);
    map<int,std::pair<int,int>> Timetable_enter(string interval);
    ~GeneratedModel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GeneratedModel *ui;
    DataContainer *beelog;
    string setendDate();
};

#endif // GENERATEDMODEL_H
