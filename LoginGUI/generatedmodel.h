#ifndef GENERATEDMODEL_H
#define GENERATEDMODEL_H

#include <QDialog>


namespace Ui {
class GeneratedModel;
}

class GeneratedModel : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratedModel(QWidget *parent = nullptr);
    ~GeneratedModel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GeneratedModel *ui;

};

#endif // GENERATEDMODEL_H
