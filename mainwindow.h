#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Import libraries
#include <QDialogButtonBox>
#include <QLoggingCategory>

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

// Classes
#include "notepad.h"
#include "json.h"
#include "infowindow.h"
#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void setText();

    QString changeBackgroundColorDeactive(QString name);

    QString changeBackgroundColorActive(QString name);

    void on_pushButtonNew_clicked();

    void on_pushButtonOpen_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonSaveAs_clicked();

    void on_pushButtonCopy_clicked();

    void on_pushButtonCut_clicked();

    void on_pushButtonPaste_clicked();

    void on_pushButtonUndo_clicked();

    void on_pushButtonRedo_clicked();

    void on_pushButtonSpeakTab_clicked();

    void on_pushButtonTheamTab_clicked();

    void on_textEdit_textChanged();

    void on_fontList_activated(const QString &argFontFamily);

    void on_fontSizeList_activated(const QString &argFontSize);

    void on_pushButtonBold_clicked();

    void on_pushButtonItalic_clicked();

    void on_pushButtonUnderline_clicked();

    void on_fontColor_activated(const QString &argFontColor);

    void on_pushButtonPlay_clicked();

    void on_pushButtonPause_clicked();

    void on_pushButtonResume_clicked();

    void on_pushButtonStop_clicked();

    void on_voiceSelectList_activated(int argVoiceNumber);

    void on_radioButtonThemeDark_clicked(bool checked);

    void on_radioButtonThemeLite_clicked(bool checked);

    void on_radioButtonFontBlack_clicked(bool checked);

    void on_radioButtonFontGray_clicked(bool checked);

    void on_radioButtonFontWhite_clicked(bool checked);

    void on_radioButtonFontRed_clicked(bool checked);

    void on_radioButtonFontYellow_clicked(bool checked);

    void on_radioButtonFontBlue_clicked(bool checked);

    void on_pushButtonInfo_clicked();

    void on_pushButtonCalc_clicked();

private:
    Ui::MainWindow *ui;
    InfoWindow *infoWindow;
    Calculator *calculator;

    QString filePath;
    QString selectedThemeColor;
    QString selectedFontColor;
    QDialogButtonBox* buttonBox;

    notepad* classNotepad;
    json* classJson;
    QJsonObject jsonObj;

};
#endif // MAINWINDOW_H
