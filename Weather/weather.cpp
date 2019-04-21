#include "weather.h"
#include "ui_weather.h"

Weather::Weather(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
        manager = new QNetworkAccessManager(this);

}



Weather::~Weather()
{
    delete ui;
}


void Weather::get_Temp(){
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://qt.nokia.com")));
}

/**
 *Create a single string from the array that stores the gameboard
 * */
void Weather::createBoard(){
    for(int row = 0; row < bee_test.get_num_rows(); row++) {
        for(int col = 0; col < bee_test.get_num_cols(); col++) {
            temp_board += bee_test.getBrdSpc(row,col);
        }
        temp_board += '\n';
    }
}

/**
 * Loads the QString into the label
 * */
void Weather::loadLabel(){
    ui->label_2->setText(temp_board);
}


/**
 * Clears the board
 * */
void Weather::clearBoard(){
    ui->label_2->clear();
}

/**
 * Clears the board
 * Sets the baord space
 * Creates a new baord and laod it onto the screen
 * */
void Weather::cleanUpForMove(){
    clearBoard();
    temp_board = "";
    createBoard();
    loadLabel();
}
