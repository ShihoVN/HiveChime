#include "intro.h"
#include "ui_intro.h"

Intro::Intro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Intro)
{
    ui->setupUi(this);
}

Intro::~Intro()
{
    delete ui;
}

void Intro::on_pushButton_clicked()
{
    delete this;
}
