#ifndef CREATEMODEL_H
#define CREATEMODEL_H

#include <QDialog>
#include "generatedmodel.h"
#include <string>
#include <iostream>
using namespace std;

namespace Ui {
class CreateModel;
}

class CreateModel : public QDialog
{
    Q_OBJECT

public:
    explicit CreateModel(QWidget *parent = nullptr,QString *hivename=nullptr);
    ~CreateModel();

private slots:
    void on_pushButton_clicked();



    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    Ui::CreateModel *ui;
    GeneratedModel *genModel;

    string time;
    string duration;
    string date;


};

#endif // CREATEMODEL_H
