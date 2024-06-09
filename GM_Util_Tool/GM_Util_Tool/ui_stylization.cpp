#include "ui_stylization.h"
#include <QtWidgets>
#include <QString>

//Buttons

QString buttonAvatar = "QPushButton {"
"margin: 3px 3px;"
"letter-spacing: 2px;"
"border-radius: 8px;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"color: #ffc000;"
"font-size: 14px;"
"font-weight: bold;"
"text-align: center;"
"padding: 5px;"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(139,0,0,255), stop:1 rgba(139,0,0,255));"
"border-top: 4px ridge #ffb000;"
"border-left: 4px groove #ffb000;"
"border-right: 4px ridge #ffb000;"
"border-bottom: 4px groove #ffb000;"
"}"
"QPushButton:hover {"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
"}"
"QPushButton:active {"
"background: radial - gradient(circle, #ec6a6a, #e52b2b);"
"}";

QString buttonCharacter = "QPushButton {"
"margin: 3px 3px;"
"letter-spacing: 2px;"
"border-radius: 8px;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"color: #ffc000;"
"font-size: 14px;"
"font-weight: bold;"
"text-align: center;"
"padding: 4px;"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(139,0,0,255), stop:1 rgba(139,0,0,255));"
"border-top: 4px ridge #ffb000;"
"border-left: 4px groove #ffb000;"
"border-right: 4px ridge #ffb000;"
"border-bottom: 4px groove #ffb000;"
"}"
"QPushButton:hover {"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
"}"
"QPushButton:active {"
"background: radial - gradient(circle, #ec6a6a, #e52b2b);"
"}";

QString buttonTeam = "QPushButton {"
"margin: 1px 1px;"
"letter-spacing: 2px;"
"border-radius: 8px;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"color: #ffc000;"
"font-size: 14px;"
"font-weight: bold;"
"text-align: center;"
"padding: 4px;"
"padding-left: 6px;"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(139,0,0,255), stop:1 rgba(139,0,0,255));"
"border-top: 4px ridge #ffb000;"
"border-left: 4px groove #ffb000;"
"border-right: 4px ridge #ffb000;"
"border-bottom: 4px groove #ffb000;"
"}"
"QPushButton:hover {"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
"}"
"QPushButton:active {"
"background: radial - gradient(circle, #ec6a6a, #e52b2b);"
"}";

QString characterList = "CharacterListWidget{"
"margin: 3px 3px;"
"color: #ffc000;"
"padding: 5px;"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(139,0,0,255), stop:1 rgba(139,0,0,255));"
"border-top: 4px ridge #ffb000;"
"border-left: 4px groove #ffb000;"
"border-right: 4px ridge #ffb000;"
"border-bottom: 4px groove #ffb000;"
"}"
"QLabel{"
"letter-spacing: 2px;"
"border-radius: 8px;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 14px;"
"font-weight: bold;"
"text-align: center;"
"color: #ffc000;"
"}"
"CharacterListWidget:hover {"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
"}";

//Main backgrounds

QString tab =
"QTabWidget::pane {"

"border-top: 6px ridge #604020;"
"border-left: 6px groove #604020;"
"border-right: 6px ridge #604020;"
"border-bottom: 6px groove #604020;"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(210, 166, 121, 255), stop:0.98 rgba(210, 166, 121, 255), stop:1 rgba(128, 87, 48, 255));"
"}"
"QTabBar::tab {"
"color: #000000;"
"border: 5px solid #604020;"
"padding: 8px;"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(210, 166, 121, 255), stop:0.98 rgba(210, 166, 121, 255), stop:1 rgba(128, 87, 48, 255));"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 14px;"
"}"
"QTabBar::tab:selected, QTabBar::tab:hover {"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(230, 191, 148, 255), stop:0.98 rgba(230, 191, 148, 255), stop:1 rgba(180, 147, 104, 255));"
"}"
"QTabBar::tab:!selected {"
"margin-top: 3px;"
"}"
"QTabBar::tab:first {"
"border-top-left-radius: 10px;"
"}"
"QTabBar::tab:last {"
"border-top-right-radius: 10px;"
"}";

QString mainBackground = "QMainWindow {"
"color: #000000;"
"background: qlineargradient("
"spread:pad,"
"x1:0, y1:0,"
"x2:1, y2:1,"
"stop:0 rgba(210, 166, 121, 255),"
"stop:0.5 rgba(180, 120, 80, 255),"
"stop:1 rgba(128, 87, 48, 255)"
");"
"}";

QString frameCharacter = "QFrame {"
"border-top: 3px ridge #734d26;"
"border-left: 3px groove #734d26;"
"border-right: 3px ridge #734d26;"
"border-bottom: 3px groove #734d26;"
"}"
"QFrame > * { "
"border: none;"
"}";

//Labels

QString normalLabel = "QLabel {"
"color: #000000;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 14px;"
"}";

QString titleLabel = "QLabel {"
"color: #000000;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 21px;"
"font-weight: bold;"
"}";

QString backstoryLabel = "QLabel {"
"color: #000000;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 15px;"
"font-weight: bold;"
"}";

//Standard inputs boxes

QString checkBox = "QCheckBox::indicator {"
"width: 16px;"
"height: 16px;"
"}"
"QCheckBox::indicator:unchecked {"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(139,0,0,255), stop:1 rgba(139,0,0,255));"
"border-top: 2px ridge #ffb000;"
"border-left: 2px groove #ffb000;"
"border-right: 2px ridge #ffb000;"
"border-bottom: 2px groove #ffb000;"
"}"
"QCheckBox::indicator:hover {"
"border-top: 2px ridge #ffb000;"
"border-left: 2px groove #ffb000;"
"border-right: 2px ridge #ffb000;"
"border-bottom: 2px groove #ffb000;"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
"}"
"QCheckBox::indicator:checked {"
"border-top: 2px ridge #ffb000;"
"border-left: 2px groove #ffb000;"
"border-right: 2px ridge #ffb000;"
"border-bottom: 2px groove #ffb000;"
"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,180,180,255), stop:1 rgba(139,0,0,255));"
"}"
"QCheckBox {"
"color: #000000;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 14px;"
"}";

QString normalInput = "QLineEdit {"
"color: #000000;"
"border-top: 3px ridge #734d26;"
"border-left: 3px groove #734d26;"
"border-right: 3px ridge #734d26;"
"border-bottom: 3px groove #734d26;"
"background-color: rgba(230, 191, 148, 255);"
"}";

QString comboBoxInput = "QComboBox {"
"color: #000000;"
"border-top: 3px ridge #734d26;"
"border-left: 3px groove #734d26;"
"border-right: 3px ridge #734d26;"
"border-bottom: 3px groove #734d26;"
"background-color: rgba(230, 191, 148, 255);"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 14px;"
"padding-left: 2px;"
"}"
"QComboBox QListView {"
"border-top: 3px ridge #734d26;"
"border-left: 3px groove #734d26;"
"border-right: 3px ridge #734d26;"
"border-bottom: 3px groove #734d26;"
"background-color: rgba(230, 191, 148, 255);"
"color: #000000;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 14px;"
"}"
"QScrollBar:vertical {"
"background-color: rgb(210, 166, 121);"
"}"
"QScrollBar::handle:vertical {"
"border-top: 2px ridge #734d26;"
"border-left: 2px groove #734d26;"
"border-right: 2px ridge #734d26;"
"border-bottom: 2px groove #734d26;"
"}"
"QScrollBar::add-line:vertical {"
"height: 0px;"
"subcontrol-position: bottom;"
"subcontrol-origin: margin;"
"background-color: rgba(230, 191, 148, 255);"
"}"
"QScrollBar::sub-line:vertical {"
"height: 0px;"
"subcontrol-position: top;"
"subcontrol-origin: margin;"
"background-color: rgba(230, 191, 148, 255);"
"}"
"QScrollBar::add-page:vertical {"
"background-color:  rgba(180, 147, 104, 255);"
"border-left: 2px groove #734d26;"
"}"
"QScrollBar::sub-page:vertical {"
"background-color:  rgba(180, 147, 104, 255);"
"border-left: 2px groove #734d26;"
"}";

//Avatar related

QString avatarBackground = "QLabel {"
"background-color: rgba(230, 191, 148, 255);"
"}";

QString frameAvatar = "QFrame {"
"border-top: 3px ridge #734d26;"
"border-left: 3px groove #734d26;"
"border-right: 3px ridge #734d26;"
"border-bottom: 3px groove #734d26;"
"}";

//Bacsktory input

QString backstory = "QTextEdit {"
"color: #000000;"
"border-top: 3px ridge #734d26;"
"border-left: 3px groove #734d26;"
"border-right: 3px ridge #734d26;"
"border-bottom: 3px groove #734d26;"
"background-color: rgba(230, 191, 148, 255);"
"margin: 1px 1px 1px 3px;"
"}"
"QScrollBar:vertical {"
"background-color: #d2a679;"
"}"
"QScrollBar::handle:vertical {"
"border-top: 2px ridge #734d26;"
"border-left: 2px groove #734d26;"
"border-right: 2px ridge #734d26;"
"border-bottom: 2px groove #734d26;"
"}"
"QScrollBar::add-line:vertical {"
"height: 0px;"
"subcontrol-position: bottom;"
"subcontrol-origin: margin;"
"background-color: rgba(230, 191, 148, 255);"
"}"
"QScrollBar::sub-line:vertical {"
"height: 0px;"
"subcontrol-position: top;"
"subcontrol-origin: margin;"
"background-color: rgba(230, 191, 148, 255);"
"}"
"QScrollBar::add-page:vertical {"
"background-color:  rgba(180, 147, 104, 255);"
"border-left: 2px groove #734d26;"
"}"
"QScrollBar::sub-page:vertical {"
"background-color:  rgba(180, 147, 104, 255);"
"border-left: 2px groove #734d26;"
"}";

//Team scroll area

QString scrollArea = "QScrollArea {"
"border-top: 3px ridge #734d26;"
"border-left: 3px groove #734d26;"
"border-right: 3px ridge #734d26;"
"border-bottom: 3px groove #734d26;"
"}"
"QScrollArea > QWidget > QWidget {"
"background-color: rgba(230, 191, 148, 255);"
"}"
"QScrollBar:vertical {"
"background-color: rgb(210, 166, 121);"
"}"
"QScrollBar::handle:vertical {"
"border-top: 2px ridge #734d26;"
"border-left: 2px groove #734d26;"
"border-right: 2px ridge #734d26;"
"border-bottom: 2px groove #734d26;"
"}"
"QScrollBar::add-line:vertical {"
"height: 0px;"
"subcontrol-position: bottom;"
"subcontrol-origin: margin;"
"background-color: rgba(230, 191, 148, 255);"
"}"
"QScrollBar::sub-line:vertical {"
"height: 0px;"
"subcontrol-position: top;"
"subcontrol-origin: margin;"
"background-color: rgba(230, 191, 148, 255);"
"}"
"QScrollBar::add-page:vertical {"
"background-color:  rgba(180, 147, 104, 255);"
"border-left: 2px groove #734d26;"
"}"
"QScrollBar::sub-page:vertical {"
"background-color:  rgba(180, 147, 104, 255);"
"border-left: 2px groove #734d26;"
"}";
QString errorBox = "QMessageBox {"
"border-top: 5px ridge #734d26;"
"border-left: 5px groove #734d26;"
"border-right: 5px ridge #734d26;"
"border-bottom: 5px groove #734d26;"
"background-color: rgba(230, 191, 148, 255);"
"}"
"QMessageBox QPushButton {"
"background-color: rgba(230, 191, 148, 255);"
"border-top: 5px ridge #734d26;"
"border-left: 5px groove #734d26;"
"border-right: 5px ridge #734d26;"
"border-bottom: 5px groove #734d26;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 14px;"
"font-weight: bold;"
"padding-left: 5px;"
"padding-right: 5px;"
"padding-top: 2px;"
"padding-bottom: 2px;"
"margin: 0px 4px 2px;"
"}"
"QLabel {"
"color: #000000;"
"font-family: Goudy Old Style, Goudy Type, serif;"
"font-size: 14px;"
"font-weight: bold;"
"}";