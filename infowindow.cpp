#include "infowindow.h"
#include "ui_infowindow.h"

InfoWindow::InfoWindow(QWidget *parent, const QString & themeText) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);

//    Set theme
    InfoWindow::setStyleSheet(themeText);

}

InfoWindow::~InfoWindow()
{
    delete ui;
}
