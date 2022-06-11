#include "notepad.h"

notepad::notepad()
{
    vol = 0;
}

void notepad::setVolume(int volume)
{
    vol = volume;
}

int notepad::getVolume()
{
    return vol;
}

QString notepad::path(QString file)
{
//    Create paths
    QString name;
    QString folderPath = QDir::homePath() + "/Ruvi-Notepad";
    QString jsonName = folderPath + "/Theme.json";

    if (file == "Folder"){
        name = folderPath;
    }
    else if (file == "jsonName"){
        name = jsonName;
    }

    return name;
}

QString notepad::themeColor(QString color, QString fontColor)
{
    QString theme;
//    if (color == "Dark"){
//        theme = "* { background: #222431; color: " + fontColor + ";} "
//                            "QPushButton {border: 1px solid " + fontColor + "; border-radius: 10px;} "
//                                "QComboBox { background-color: #222431;} QPalette { background: #222431;} "
//                                    "#textEdit { border: 1px solid #d1d1d1;}";
//    }
//    else if (color == "Light") {
//        theme = "* { background: #f2f2f2; color: " + fontColor + ";} "
//                            "QPushButton {border: 1px solid " + fontColor + "; border-radius: 10px;} "
//                                "QComboBox { background-color: #f2f2f2;} QPalette { background: #f2f2f2;} "
//                                    "#textEdit { border: 1px solid #222431;}";
//    }

    if (color == "Dark"){

        theme = "* {	color:  " + fontColor + ";	font: bold 15px;}QMainWindow {	background-color: #112031;}"
                "QWidget {	background-color: #112031;}"
                "QWidget#widget_text_tool {	background-color: #112031;}"
                "QPushButton { 	background-color: #152D35;	border-width: 0px;    border-radius: 10px;	color: " + fontColor + ";	font: bold 15px;}"
                "QTextEdit {	color:  " + fontColor + "; border: none;	margin-top:5px;	margin-bottom: 5px;    background-color: #152D35; border-radius: 10px;}"
                "QLabel#label_2,#label_4,#label_17,#labelWordCount {	color: " + fontColor + ";	font: bold 15px;}"
                "QLabel#labelDisplay { background-color: #152D35; border-radius: 10px; }"
                "QComboBox {	background-color: #152D35;	border-width: 0px;    border-radius: 10px;	border-color: #152D35;	color: " + fontColor + ";	font: bold 15px;}"
                "QRadioButton { color:  " + fontColor + "; } "
                "QPushButton#btn_theme_dark { 	background-color: #112031;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_lite { 	background-color: #fff;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_black { 	background-color: black;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_gray { 	background-color: gray;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_red { 	background-color: red;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_green { 	background-color: white;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_orange { 	background-color: orange;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_yello { 	background-color: yellow;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_blue { 	background-color: blue;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}";

    }
    else if (color == "Light") {

        theme = "* {	color:  " + fontColor + ";	font: bold 15px;}"
                "QMainWindow {	background-color: #f2f2f2;}"
                "QWidget {	background-color: #f2f2f2;}"
                "QWidget#widget_text_tool {	background-color: #f2f2f2;}"
                "QPushButton { 	background-color: #fff;	border-width: 0px;    border-radius: 10px;	color: " + fontColor + ";	font: bold 15px;}"
                "QTextEdit {	color:  " + fontColor + "; border: none;	margin-top:5px;	margin-bottom: 5px;    background-color: #fff;    border-radius: 10px;}"
                "QLabel#label_2,#label_4,#label_17,#labelWordCount {	color: " + fontColor + ";	font: bold 15px;}"
                "QLabel#labelDisplay { background-color: #fff; border-radius: 10px; }"
                "QComboBox {	background-color: #fff;	border-width: 0px;    border-radius: 10px;	border-color: #fff;	color: " + fontColor + ";	font: bold 15px;}"
                "QRadioButton { color:  " + fontColor + "; } "
                "QPushButton#btn_theme_dark { 	background-color: #112031;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_lite { 	background-color: #fff;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_black { 	background-color: black;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_gray { 	background-color: gray;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_red { 	background-color: red;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_green { 	background-color: white;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_orange { 	background-color: orange;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_yello { 	background-color: yellow;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}"
                "QPushButton#btn_theme_text_blue { 	background-color: blue;	border-style: outset;    border-width: 2px;	border-radius: 15px;    border-color: red;}";

    }

    return theme;
}
