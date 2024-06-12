#pragma once
#include <QString>

class DarkStyleSheet {
public:
	QString commonButtonStyle = "QPushButton {"
		"margin: 3px 3px;"
		"letter-spacing: 2px;"
		"border-radius: 0px;"
		"font-family:Berylium;"
		"color: #d6d6d6;"
		"font-size: 14px;"
		"font-weight: regular;"
		"text-align: center;"
		"padding: 5px;"
		"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 #B80000, stop:1 #450000);"
		"border-top: 3px ridge #d6d6d6;"
		"border-left: 3px groove #d6d6d6;"
		"border-right: 3px ridge #d6d6d6;"
		"border-bottom: 3px groove #d6d6d6;"
		"}"
		"QPushButton:disabled {"
		"background: rgba(100,0,0,255);"
		"}"
		"QPushButton:hover {"
		"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 #450000);"
		"}"
		"QPushButton:active {"
		"background: radial - gradient(circle, #ec6a6a, #e52b2b);"
		"}";

	QString buttonAvatar = commonButtonStyle + "QPushButton { padding: 5px; }";
	QString buttonCharacter = commonButtonStyle;
	QString buttonTeam = commonButtonStyle + "QPushButton { margin: 1px 1px; padding-left: 6px; }";

	QString commonLabelStyle = "QLabel {"
		"letter-spacing: 2px;"
		"border-radius: 8px;"
		"font-family: Berylium;"
		"font-size: 14px;"
		"font-weight: bold;"
		"text-align: center;"
		"color: #d6d6d6;"
		"}";

	QString characterList = "CharacterListWidget {"
		"margin: 3px 3px;"
		"color: #d6d6d6;"
		"padding: 5px;"
		"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 #B80000, stop:1 #450000);"
		"border-top: 3px ridge #d6d6d6;"
		"border-left: 3px groove #d6d6d6;"
		"border-right: 3px ridge #d6d6d6;"
		"border-bottom: 3px groove #d6d6d6;"
		"}"
		+ commonLabelStyle +
		"CharacterListWidget:hover {"
		"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 #450000);"
		"}";

	QString tab =
		"QTabWidget::pane {"
		"border-left: 3px solid qlineargradient(x1: 1,y1: 0,x2: 1,y2: 1,stop: 0 #d6d6d6,stop: 0.6 rgba(255,255,255,0),stop: 1 rgba(255,255,255,0));"
		"border-top: 3px solid #d6d6d6;"
		"border-right: 3px solid qlineargradient(x1: 1,y1: 0,x2: 1,y2: 1,stop: 0 #d6d6d6,stop: 1 rgba(255,255,255,0));"
		"border-bottom: 3px solid rgba(255,255,255,0);"

		"background: transparent;"
		"}"
		"QTabBar::tab {"
		"color: #d6d6d6;"
		"background: rgba(139,0,0,255);"
		"border-top: 3px ridge #d6d6d6;"
		"border-left: 3px groove #d6d6d6;"
		"border-right: 3px ridge #d6d6d6;"
		"padding: 8px;"
		"font-family: Berylium;"
		"font-size: 14px;"
		"font-weight:bold;"
		"}"
		"QTabBar::tab:selected, QTabBar::tab:hover {"
		"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
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
		"color: #ffc000;"
		"border-image:url(./resources/background_main.png) 0 0 0 0 cover ;"
		"}";

	QString frameCharacter = "QFrame {"
		"border-left: 3px solid qlineargradient(x1: 1,y1: 0,x2: 1,y2: 1,stop: 0 #d6d6d6,stop: 0.6 rgba(255,255,255,0),stop: 1 rgba(255,255,255,0));"
		"border-top: 3px solid #d6d6d6;"
		"border-right: 3px solid qlineargradient(x1: 1,y1: 0,x2: 1,y2: 1,stop: 0 #d6d6d6,stop: 1 rgba(255,255,255,0));"
		"border-bottom: 3px solid rgba(255,255,255,0);"
		"}"
		"QFrame > * { border: none; }";

	QString normalLabel = "QLabel {"
		"color: #d6d6d6;"
		"font-family:Berylium;"
		"font-size: 14px;"
		"font-weight:bold;"
		"}";

	QString titleLabel = "QLabel {"
		"color: #d6d6d6;"
		"font-family:Berylium;"
		"font-weight:bold;"
		"font-size: 21px;"
		"}";

	QString backstoryLabel = "QLabel {"
		"color: #d6d6d6;"
		"font-family:Berylium;"
		"font-weight:bold;"
		"font-size: 15px;"

		"}";

	QString checkBox = "QCheckBox::indicator {"
		"width: 16px;"
		"height: 16px;"
		"border-top: 2px ridge #d6d6d6;"
		"border-left: 2px groove #d6d6d6;"
		"border-right: 2px ridge #d6d6d6;"
		"border-bottom: 2px groove #d6d6d6;"
		"}"
		"QCheckBox::indicator:unchecked  {"
		"background: rgba(139,0,0,255);"
		"}"
		"QCheckBox::indicator:hover {"
		"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
		"}"
		"QCheckBox::indicator:checked { background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,210,210,255), stop:1 rgba(139,0,0,255));}"
		"QCheckBox {"
		"color: #d6d6d6;"
		"font-family: Berylium;"
		"font-weight: bold;"
		"font-size: 14px;"
		"}";

	QString inputField = "background-color: qlineargradient(x1 : 0, y1 : 1, x2 : 1, y2 : 1, stop : 0 #d6d6d6,stop : 0.8 #d6d6d6, stop: 1 rgba(0, 0, 0, 0)); ";
	QString normalInput = "QLineEdit { color: #000000;font-family: Berylium; font-weight:bold; font-size: 14px; " + inputField + "}";
	QString comboBoxInput = "QComboBox { color: #000000; font-family: Berylium; font-weight:bold; font-size: 14px; padding-left: 2px; " + inputField + "}"
		"QComboBox QListView { color: #000000; font-family: Berylium; font-weight:bold; font-size: 14px; font-size: 14px; " + inputField + "}"
		"QScrollBar:vertical { background-color: #C0C0C0;  }"
		"QScrollBar::handle:vertical { border: 2px solid #7a7979;   }"
		"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; subcontrol-position: top; subcontrol-origin: margin; background-color:#30302d; }"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background-color: #30302d;  }";

	QString avatarBackground = "QLabel { background: transparent; }";
	QString frameAvatar = "QFrame {"
		"border-top: 2px ridge #d6d6d6;"
		"border-left: 2px groove #d6d6d6;"
		"border-right: 2px ridge #d6d6d6;"
		"border-bottom: 2px groove #d6d6d6;}";

	QString backstory = "QTextEdit { color: black; "
		"font-family: Berylium;"
		"font-weight: regular;"
		"font-size: 14px; margin: 1px 1px 1px 3px; " + inputField + " }"
		"QScrollBar:vertical { background-color: #d2a679; }"
		"QScrollBar::handle:vertical { border: 2px solid #734d26; }"
		"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; subcontrol-position: top; subcontrol-origin: margin; background-color: rgba(230, 191, 148, 255); }"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background-color: rgba(180, 147, 104, 255); border-left: 2px groove #734d26; }";

	QString scrollArea = "QScrollArea {"
		"background:transparent;"
		"border-left: 3px solid qlineargradient(x1: 1,y1: 0,x2: 1,y2: 1,stop: 0 #d6d6d6,stop: 0.6 rgba(255,255,255,0),stop: 1 rgba(255,255,255,0));"
		"border-top: 3px solid #d6d6d6;"
		"border-right: 3px solid qlineargradient(x1: 1,y1: 0,x2: 1,y2: 1,stop: 0 #d6d6d6,stop: 1 rgba(255,255,255,0));"
		"border-bottom: 3px solid rgba(255,255,255,0);"
		"}"
		"QScrollArea > QWidget > QWidget {"
		"background: transparent;"
		"}"
		"QScrollBar:vertical {"
		"background-color: rgb(210, 166, 121);"
		"}";

	QString errorBox = "QMessageBox {"
		"border-top: 2px ridge #d6d6d6;"
		"border-left: 2px groove #d6d6d6;"
		"border-right: 2px ridge #d6d6d6;"
		"border-bottom: 2px groove #d6d6d6;"
		"background-color: qlineargradient(x1: 1,y1: 1,x2: 1,y2: 0,stop: 0 #d6d6d6,stop: 0.3 rgba(255,255,255,0),stop: 1 rgba(255,255,255,0));"
		"}"
		+ commonButtonStyle
		+ normalLabel;
};
