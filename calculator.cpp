#include "calculator.h"
#include "ui_calculator.h"

double firstNum;
bool userIsTypingSecondNumber = false;

Calculator::Calculator(QWidget *parent, const QString & themeText) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

//    Set theme
        Calculator::setStyleSheet(themeText);


    connect(ui->pushButton0, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton1, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton2, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton3, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton4, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton5, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton6, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton7, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton8, SIGNAL(clicked()),this, SLOT(digit_pressed()));
    connect(ui->pushButton9, SIGNAL(clicked()),this, SLOT(digit_pressed()));

    connect(ui->pushButtonPlusMinus, SIGNAL(clicked()),this, SLOT(unary_operation_pressed()));
    connect(ui->pushButtonPercentage, SIGNAL(clicked()),this, SLOT(unary_operation_pressed()));

    ui->pushButtonIncrease->setCheckable(true);
    ui->pushButtonDecrease->setCheckable(true);
    ui->pushButtonMultiply->setCheckable(true);
    ui->pushButtonDivide->setCheckable(true);

}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double  labelNumber;
    QString newLabel;

    if((ui->pushButtonIncrease->isChecked() || ui->pushButtonDecrease->isChecked() ||
            ui->pushButtonMultiply->isChecked() || ui->pushButtonDivide->isChecked()) &&
            (!userIsTypingSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;

        newLabel = QString::number(labelNumber, 'g', 15);
    }
    else
    {
        if (ui->labelDisplay->text().contains(".") && button->text() == "0")
        {
            newLabel = ui->labelDisplay->text() + button->text();
        }
        else
        {
            labelNumber = (ui->labelDisplay->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber, 'g', 15);
        }
    }

    ui->labelDisplay->setText(newLabel);
}

void Calculator::on_pushButtonDecimal_clicked()
{
    ui->labelDisplay->setText(ui->labelDisplay->text()+".");
}

void Calculator::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if (button->text() == "+/-")
    {
        labelNumber = ui->labelDisplay->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->labelDisplay->setText(newLabel);
    }

    if (button->text() == "%")
    {
        labelNumber = ui->labelDisplay->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->labelDisplay->setText(newLabel);
    }
}

void Calculator::on_pushButtonClear_clicked()
{
    ui->pushButtonIncrease->setChecked(false);
    ui->pushButtonDecrease->setChecked(false);
    ui->pushButtonMultiply->setChecked(false);
    ui->pushButtonDivide->setChecked(false);

    userIsTypingSecondNumber = false;
    ui->labelDisplay->setText("0");
}

void Calculator::on_pushButtonAnswer_clicked()
{
    double labelNumber, secondNum;
    QString newLabel;
    secondNum = ui->labelDisplay->text().toDouble();

    if (ui->pushButtonIncrease->isCheckable())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->labelDisplay->setText(newLabel);
        ui->pushButtonIncrease->setCheckable(false);
    }

    else if (ui->pushButtonDecrease->isCheckable())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->labelDisplay->setText(newLabel);
        ui->pushButtonDecrease->setCheckable(false);
    }

    else if (ui->pushButtonMultiply->isCheckable())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->labelDisplay->setText(newLabel);
        ui->pushButtonMultiply->setCheckable(false);
    }

    else if (ui->pushButtonDivide->isCheckable())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->labelDisplay->setText(newLabel);
        ui->pushButtonDivide->setCheckable(false);
    }

    userIsTypingSecondNumber = false;
}

void Calculator::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    firstNum = ui->labelDisplay->text().toDouble();

    if (button->text() == "+")
    {
        ui->pushButtonIncrease->setCheckable(true);
    }
    else if (button->text() == "-")
    {
        ui->pushButtonDecrease->setCheckable(true);
    }
    else if (button->text() == "X")
    {
        ui->pushButtonMultiply->setCheckable(true);
    }
    else if (button->text() == "/")
    {
        ui->pushButtonDivide->setCheckable(true);
    }

}

void Calculator::on_pushButtonMultiply_clicked()
{
    firstNum = ui->labelDisplay->text().toDouble();
    ui->pushButtonMultiply->setCheckable(true);
}

void Calculator::on_pushButtonDecrease_clicked()
{
    firstNum = ui->labelDisplay->text().toDouble();
    ui->pushButtonDecrease->setCheckable(true);
}

void Calculator::on_pushButtonIncrease_clicked()
{
    firstNum = ui->labelDisplay->text().toDouble();
    ui->pushButtonIncrease->setCheckable(true);
}

void Calculator::on_pushButtonDivide_clicked()
{
    firstNum = ui->labelDisplay->text().toDouble();
    ui->pushButtonDivide->setCheckable(true);
}
