#ifndef CALCULATOR_H
#define CALCULATOR_H

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
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent, const QString & themeText);
    ~Calculator();

private:
    Ui::Calculator *ui;


private slots:
    void digit_pressed();


    void on_pushButtonDecimal_clicked();
    void unary_operation_pressed();
    void on_pushButtonClear_clicked();
    void on_pushButtonAnswer_clicked();

    void binary_operation_pressed();
    void on_pushButtonMultiply_clicked();
    void on_pushButtonDecrease_clicked();
    void on_pushButtonIncrease_clicked();
    void on_pushButtonDivide_clicked();
};

#endif // CALCULATOR_H
