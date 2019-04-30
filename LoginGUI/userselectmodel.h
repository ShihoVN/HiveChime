#ifndef USERSELECTMODEL_H
#define USERSELECTMODEL_H

#include <QDialog>

namespace Ui {
class userSelectModel;
}

class userSelectModel : public QDialog
{
    Q_OBJECT

public:
    explicit userSelectModel(QWidget *parent = nullptr);
    ~userSelectModel();

private:
    Ui::userSelectModel *ui;
};

#endif // USERSELECTMODEL_H
