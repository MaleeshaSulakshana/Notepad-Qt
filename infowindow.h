#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDatabase>
#include <QFont>
#include <QIcon>
#include <QStandardPaths>
#include <QDir>
#include <QJsonObject>
#include <QJsonValue>

namespace Ui {
class InfoWindow;
}

class InfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfoWindow(QWidget *parent, const QString & themeText);
    ~InfoWindow();

private:
    Ui::InfoWindow *ui;

};

#endif // INFOWINDOW_H
