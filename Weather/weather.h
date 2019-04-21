#ifndef WEATHER_H
#define WEATHER_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
namespace Ui {
class Weather;
}

class Weather : public QMainWindow
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = nullptr);
    ~Weather();

private:
    void get_Temp();
    QNetworkAccessManager* manager;
    Ui::Weather *ui;
};

#endif // WEATHER_H
