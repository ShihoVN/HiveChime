#ifndef WEATHER_H
#define WEATHER_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include "../Bee_Visual/bees.h"
#include "../Bee_Visual/engine.h"

namespace Ui {
class Weather;
}

class Weather : public QMainWindow
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = nullptr);
    ~Weather();
    Bees bee_test;

private slots:
    void on_pushButton_clicked();

private:
    void get_Temp();
    QString temp_board;

    QNetworkAccessManager* manager;
    Ui::Weather *ui;
    void draw_board();

    void createBoard();
    void loadLabel();
    void clearBoard();
    void cleanUpForMove();
};

#endif // WEATHER_H
