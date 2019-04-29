#ifndef CREATEMODEL_H
#define CREATEMODEL_H

#include <QDialog>

namespace Ui {
class CreateModel;
}

class CreateModel : public QDialog
{
    Q_OBJECT

public:
    explicit CreateModel(QWidget *parent = nullptr);
    ~CreateModel();

private:
    Ui::CreateModel *ui;
};

#endif // CREATEMODEL_H
