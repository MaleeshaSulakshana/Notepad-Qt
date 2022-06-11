#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    Set btnStackedWidget index
    ui->btnStackedWidget->setCurrentIndex(2);

//    Check and create folder
    jsonObj =  classJson->checkAndCreateFolder();

//    Set theme colour
    selectedThemeColor = jsonObj["Theme"].toString();
    if (selectedThemeColor == "Dark") {
        ui->radioButtonThemeDark->setChecked(true);
    }
    else {
        ui->radioButtonThemeLite->setChecked(true);
    }

//    Set text colour
    selectedFontColor = jsonObj["TextColor"].toString();
    if (selectedFontColor == "Black") {
        ui->radioButtonFontBlack->setChecked(true);
    }
    else if (selectedFontColor == "Gray") {
        ui->radioButtonFontGray->setChecked(true);
    }
    else if (selectedFontColor == "White") {
        ui->radioButtonFontWhite->setChecked(true);
    }
    else if (selectedFontColor == "Red") {
        ui->radioButtonFontRed->setChecked(true);
    }
    else if (selectedFontColor == "Yellow") {
        ui->radioButtonFontYellow->setChecked(true);
    }
    else if (selectedFontColor == "Blue") {
        ui->radioButtonFontBlue->setChecked(true);
    }

//    Set speaker voice
    ui->voiceSelectList->setCurrentText(jsonObj["Voice"].toString());

    QString theme = classJson->themeSelect(jsonObj);
    MainWindow::setStyleSheet(theme);

//    Set test edit font wheight normal
    ui->textEdit->setFontWeight(QFont::Normal);

//    Add available fonts to font combo box
    QStringList fontFamilies;
    if(fontFamilies.isEmpty())
            fontFamilies = QFontDatabase().families();

    for (int i = 0; i < fontFamilies.count() ; i++ ) {
        ui->fontList->addItem(fontFamilies[i]);
    }

//    Add standed font sizes to list
    QList<int> fontSizes;
    if(fontSizes.isEmpty())
        fontSizes = QFontDatabase().standardSizes();

    for (int i = 0; i < fontSizes.count() ; i++ ) {
        QString fontsize = QString::number(fontSizes[i]);
        ui->fontSizeList->addItem(fontsize);
    }

//    Set font and point settings
    setText();

//    Set forcus cursor in text-edit
    ui->textEdit->setFocus();

}


// Custom methods
void MainWindow::setText()
{
    QString fontsize = jsonObj.find("FontSize").value().toString();
    QString fontfamily = jsonObj.find("FontFamily").value().toString();
    QString fontcolor = jsonObj.find("FontColor").value().toString();

//    Set font settings
    ui->textEdit->setFontPointSize(fontsize.toInt());
    ui->textEdit->setFontFamily(fontfamily);
    ui->textEdit->setTextColor(fontcolor);

//    Set font setting lists current text
    ui->fontList->setCurrentText(fontfamily);
    ui->fontSizeList->setCurrentText(fontsize);
    ui->fontColor->setCurrentText(fontcolor);

//    Set focus
    ui->textEdit->setFocus();
}



QString MainWindow::changeBackgroundColorDeactive(QString name)
{
    QString deactivecolor = ""+name+" {background: "+ jsonObj.find("Theme").value().toString() +"; "
                                        "border-color: "+ jsonObj.find("Theme").value().toString() +";}";
    return deactivecolor;
}

QString MainWindow::changeBackgroundColorActive(QString name)
{
    QString activecolor = ""+name+" {background: #c1c1c1; border-color: #c1c1c1;}";
    return activecolor;
}


MainWindow::~MainWindow()
{
    delete ui;
}


// Ui component methods
void MainWindow::on_pushButtonNew_clicked()
{
//    Create/open new file
    if (ui->textEdit->toPlainText() == "" & filePath == ""){
        QMessageBox::warning(this,"Warning..","Already opened new text sheet!");
    }
    else {
        filePath = "";
        ui->textEdit->clear();
        setText();
    }
}

void MainWindow::on_pushButtonOpen_clicked()
{
//    Open local file
    QString file_name = QFileDialog::getOpenFileName(this, "Open the file!");
    QFile file(file_name);

    filePath = file_name;

    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning..","File not open!");
        return;
    }

    QTextStream inputfile(&file);
    QString text = inputfile.readAll();
    ui->textEdit->setText(text);

    file.close();
}

void MainWindow::on_pushButtonSave_clicked()
{
//    Save latest edits to relevent file
    if (ui->textEdit->toPlainText() == ""){
        QMessageBox::warning(this,"Warning..","Cannot save empty text sheet!");
    }
    else{

        if (filePath == "") {
            filePath = QFileDialog::getSaveFileName(this,
                                                     tr("Open the file"), "*.txt",
                                                     tr("Save file (*.txt);;All Files"));
        }

        QFile file(filePath);

        if (!file.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this, "Warning..","Text sheet not save!");
            return;
        }

        QTextStream outputfile(&file);
        QString text = ui->textEdit->toPlainText();
        outputfile << text;
        file.flush();
        file.close();
    }
}

void MainWindow::on_pushButtonSaveAs_clicked()
{
//    Save latest edits to choosing new file
    if (ui->textEdit->toPlainText() == ""){
        QMessageBox::warning(this,"Waring","Cannot save empty text sheet!");
    }
    else{

        QString file_name = QFileDialog::getSaveFileName(this,
                                                         tr("Open the file"), "*.txt",
                                                         tr("Save file (*.txt);;All Files"));
        QFile file(file_name);
        filePath = file_name;

        if (!file.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this, "Waring..","Text sheet not save!");
            return;
        }

        QTextStream outputfile(&file);
        QString text = ui->textEdit->toPlainText();
        outputfile << text;
        file.flush();
        file.close();
    }
}

void MainWindow::on_pushButtonCopy_clicked()
{
//    For copy option
    ui->textEdit->copy();
    setText();
}

void MainWindow::on_pushButtonCut_clicked()
{
//    For cut option
    ui->textEdit->cut();
    setText();
}

void MainWindow::on_pushButtonPaste_clicked()
{
//    For paste option
    ui->textEdit->paste();
    setText();
}

void MainWindow::on_pushButtonUndo_clicked()
{
//    For undo option
    ui->textEdit->undo();
    setText();
}

void MainWindow::on_pushButtonRedo_clicked()
{
//    For redo option
    ui->textEdit->redo();
    setText();
}

void MainWindow::on_pushButtonSpeakTab_clicked()
{
//    For tab change option
    if (ui->btnStackedWidget->currentIndex() == 1){
        ui->btnStackedWidget->setCurrentIndex(0);
    }
    else {
        ui->btnStackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButtonTheamTab_clicked()
{
//    For tab change option
    if (ui->btnStackedWidget->currentIndex() == 2){
        ui->btnStackedWidget->setCurrentIndex(0);
    }
    else {
        ui->btnStackedWidget->setCurrentIndex(2);
    }
}

void MainWindow::on_textEdit_textChanged()
{
//    Get word word count and display on text edit
    int wordCount = ui->textEdit->toPlainText()
            .split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count();

    QString count = QString::number(wordCount);
    ui->labelWordCount->setText("Word Count: " + count );
}

void MainWindow::on_fontList_activated(const QString &argFontFamily)
{
//    For change fonts option
    ui->textEdit->setFontFamily(argFontFamily);
    ui->textEdit->setFocus();
    classJson->dataWriteOnJson("FontFamily", argFontFamily);
}

void MainWindow::on_fontSizeList_activated(const QString &argFontSize)
{
//    For change font sizes option
    ui->textEdit->setFontPointSize(argFontSize.toInt());
    ui->textEdit->setFocus();
    classJson->dataWriteOnJson("FontSize", argFontSize);
}

void MainWindow::on_pushButtonBold_clicked()
{
//    For change font to bold font option
    QTextCursor txtCursor = ui->textEdit->textCursor();
    if (!txtCursor.charFormat().font().bold()){
        ui->textEdit->setFontWeight(QFont::Bold);
//        ui->pushButtonBold->setStyleSheet(changeBackgroundColorActive("#btnBold"));
    }
    else{
        ui->textEdit->setFontWeight(QFont::Normal);
//        ui->pushButtonBold->setStyleSheet(changeBackgroundColorDeactive("#btnBold"));
    }

    setText();
}

void MainWindow::on_pushButtonItalic_clicked()
{
//    For change font to italic font option
    QTextCursor txtCursor = ui->textEdit->textCursor();
    if (!txtCursor.charFormat().font().italic()){
        ui->textEdit->setFontItalic(true);
//        ui->pushButtonItalic->setStyleSheet(changeBackgroundColorActive("#btnItelic"));
    }
    else {
        ui->textEdit->setFontItalic(false);
//        ui->pushButtonItalic->setStyleSheet(changeBackgroundColorDeactive("#btnItelic"));
    }

    setText();
}

void MainWindow::on_pushButtonUnderline_clicked()
{
//    For change font to underline font option
    QTextCursor txtCursor = ui->textEdit->textCursor();
    if (!txtCursor.charFormat().font().underline()){
        ui->textEdit->setFontUnderline(true);
//        ui->pushButtonUnderline->setStyleSheet(changeBackgroundColorActive("#btnUnderline"));
    }
    else {
        ui->textEdit->setFontUnderline(false);
//        ui->pushButtonUnderline->setStyleSheet(changeBackgroundColorDeactive("#btnUnderline"));
    }

    setText();
}

void MainWindow::on_fontColor_activated(const QString &argFontColor)
{
//    For change font colour option
    ui->textEdit->setTextColor(argFontColor);
    classJson->dataWriteOnJson("FontColor", argFontColor);
    ui->textEdit->setFocus();
}

void MainWindow::on_pushButtonPlay_clicked()
{

}

void MainWindow::on_pushButtonPause_clicked()
{

}

void MainWindow::on_pushButtonResume_clicked()
{

}

void MainWindow::on_pushButtonStop_clicked()
{

}

void MainWindow::on_voiceSelectList_activated(int argVoiceNumber)
{

}

void MainWindow::on_radioButtonThemeDark_clicked(bool checked)
{
//    Set dark theme option
    if (checked) {
        ui->radioButtonThemeDark->setChecked(true);
        ui->radioButtonThemeLite->setChecked(false);

        selectedThemeColor = "Dark";
        QString theme = classNotepad->themeColor("Dark", selectedFontColor);
        MainWindow::setStyleSheet(theme);
        classJson->dataWriteOnJson("Theme", "Dark");
    }
}

void MainWindow::on_radioButtonThemeLite_clicked(bool checked)
{
//    Set lite theme option
    if (checked) {
        ui->radioButtonThemeDark->setChecked(false);
        ui->radioButtonThemeLite->setChecked(true);

        selectedThemeColor = "Light";
        QString theme = classNotepad->themeColor("Light", selectedFontColor);
        MainWindow::setStyleSheet(theme);
        classJson->dataWriteOnJson("Theme", "Light");
    }
}

void MainWindow::on_radioButtonFontBlack_clicked(bool checked)
{
//    Set black font colour option
    if (checked) {
        selectedFontColor = "Black";
        ui->radioButtonFontBlack->setChecked(true);
        ui->radioButtonFontGray->setChecked(false);
        ui->radioButtonFontWhite->setChecked(false);
        ui->radioButtonFontRed->setChecked(false);
        ui->radioButtonFontYellow->setChecked(false);
        ui->radioButtonFontBlue->setChecked(false);

        QString theme = classNotepad->themeColor(selectedThemeColor, "Black");
        MainWindow::setStyleSheet(theme);

        ui->textEdit->setTextColor("Black");
        ui->fontColor->setCurrentText("Black");

        classJson->dataWriteOnJson("TextColor", "Black");
        classJson->dataWriteOnJson("FontColor", "Black");
    }
}

void MainWindow::on_radioButtonFontGray_clicked(bool checked)
{
//    Set gray font colour option
    if (checked) {
        selectedFontColor = "Gray";
        ui->radioButtonFontBlack->setChecked(false);
        ui->radioButtonFontGray->setChecked(true);
        ui->radioButtonFontWhite->setChecked(false);
        ui->radioButtonFontRed->setChecked(false);
        ui->radioButtonFontYellow->setChecked(false);
        ui->radioButtonFontBlue->setChecked(false);

        QString theme = classNotepad->themeColor(selectedThemeColor, "Gray");
        MainWindow::setStyleSheet(theme);

        ui->textEdit->setTextColor("Gray");
        ui->fontColor->setCurrentText("Gray");

        classJson->dataWriteOnJson("TextColor", "Gray");
        classJson->dataWriteOnJson("FontColor", "Gray");
    }
}

void MainWindow::on_radioButtonFontWhite_clicked(bool checked)
{
//    Set white font colour option
    if (checked) {
        selectedFontColor = "White";
        ui->radioButtonFontBlack->setChecked(false);
        ui->radioButtonFontGray->setChecked(false);
        ui->radioButtonFontWhite->setChecked(true);
        ui->radioButtonFontRed->setChecked(false);
        ui->radioButtonFontYellow->setChecked(false);
        ui->radioButtonFontBlue->setChecked(false);

        QString theme = classNotepad->themeColor(selectedThemeColor, "White");
        MainWindow::setStyleSheet(theme);

        ui->textEdit->setTextColor("White");
        ui->fontColor->setCurrentText("White");

        classJson->dataWriteOnJson("TextColor", "White");
        classJson->dataWriteOnJson("FontColor", "White");
    }
}

void MainWindow::on_radioButtonFontRed_clicked(bool checked)
{
//    Set red font colour option
    if (checked) {
        selectedFontColor = "Red";
        ui->radioButtonFontBlack->setChecked(false);
        ui->radioButtonFontGray->setChecked(false);
        ui->radioButtonFontWhite->setChecked(false);
        ui->radioButtonFontRed->setChecked(true);
        ui->radioButtonFontYellow->setChecked(false);
        ui->radioButtonFontBlue->setChecked(false);

        QString theme = classNotepad->themeColor(selectedThemeColor, "Red");
        MainWindow::setStyleSheet(theme);

        ui->textEdit->setTextColor("Red");
        ui->fontColor->setCurrentText("Red");

        classJson->dataWriteOnJson("TextColor", "Red");
        classJson->dataWriteOnJson("FontColor", "Red");
    }
}

void MainWindow::on_radioButtonFontYellow_clicked(bool checked)
{
//    Set yellow font colour option
    if (checked) {
        selectedFontColor = "Yellow";
        ui->radioButtonFontBlack->setChecked(false);
        ui->radioButtonFontGray->setChecked(false);
        ui->radioButtonFontWhite->setChecked(false);
        ui->radioButtonFontRed->setChecked(false);
        ui->radioButtonFontYellow->setChecked(true);
        ui->radioButtonFontBlue->setChecked(false);

        QString theme = classNotepad->themeColor(selectedThemeColor, "Yellow");
        MainWindow::setStyleSheet(theme);

        ui->textEdit->setTextColor("Yellow");
        ui->fontColor->setCurrentText("Yellow");

        classJson->dataWriteOnJson("TextColor", "Yellow");
        classJson->dataWriteOnJson("FontColor", "Yellow");
    }
}

void MainWindow::on_radioButtonFontBlue_clicked(bool checked)
{
//    Set blue font colour option
    if (checked) {
        selectedFontColor = "Blue";
        ui->radioButtonFontBlack->setChecked(false);
        ui->radioButtonFontGray->setChecked(false);
        ui->radioButtonFontWhite->setChecked(false);
        ui->radioButtonFontRed->setChecked(false);
        ui->radioButtonFontYellow->setChecked(false);
        ui->radioButtonFontBlue->setChecked(true);

        QString theme = classNotepad->themeColor(selectedThemeColor, "Blue");
        MainWindow::setStyleSheet(theme);

        ui->textEdit->setTextColor("Blue");
        ui->fontColor->setCurrentText("Blue");

        classJson->dataWriteOnJson("TextColor", "Blue");
        classJson->dataWriteOnJson("FontColor", "Blue");
    }
}

void MainWindow::on_pushButtonCalc_clicked()
{
//    Open calculator window
        QString themeText = classNotepad->themeColor(selectedThemeColor, selectedFontColor);

        calculator = new Calculator(this, themeText);
        if (!calculator->isVisible()) {
            calculator->show();
        }
}

void MainWindow::on_pushButtonInfo_clicked()
{
//    Open infomation window
    QString themeText = classNotepad->themeColor(selectedThemeColor, selectedFontColor);

    infoWindow = new InfoWindow(this, themeText);
    if (!infoWindow->isVisible()) {
        infoWindow->show();
    }

}
