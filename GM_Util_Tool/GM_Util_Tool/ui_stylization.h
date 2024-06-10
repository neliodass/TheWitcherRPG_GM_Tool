#pragma once

#ifndef UI_STYLIZATION_H
#define UI_STYLIZATION_H

#include <QString>

class MedivalStyleSheet {
public:
	QString commonButtonStyle = "QPushButton {"
		"margin: 3px 3px;"
		"letter-spacing: 2px;"
		"border-radius: 8px;"
		"font-family: Goudy Old Style, Goudy Type, serif;"
		"color: #ffc000;"
		"font-size: 14px;"
		"font-weight: bold;"
		"text-align: center;"
		"padding: 5px;"
		"background: rgba(139,0,0,255);"
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

	QString buttonAvatar = commonButtonStyle + "QPushButton { padding: 5px; }";
	QString buttonCharacter = commonButtonStyle;
	QString buttonTeam = commonButtonStyle + "QPushButton { margin: 1px 1px; padding-left: 6px; }";

	QString commonLabelStyle = "QLabel {"
		"letter-spacing: 2px;"
		"border-radius: 8px;"
		"font-family: Goudy Old Style, Goudy Type, serif;"
		"font-size: 14px;"
		"font-weight: bold;"
		"text-align: center;"
		"color: #ffc000;"
		"}";

	QString characterList = "CharacterListWidget {"
		"margin: 3px 3px;"
		"color: #ffc000;"
		"padding: 5px;"
		"background: rgba(139,0,0,255);"
		"border: 4px solid #ffb000;"
		"}"
		+ commonLabelStyle +
		"CharacterListWidget:hover {"
		"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
		"}";

	QString tab =
		"QTabWidget::pane {"
		"border: 6px solid #604020;"
		"background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(210, 166, 121, 255), stop:1 rgba(128, 87, 48, 255));"
		"}"
		"QTabBar::tab {"
		"color: #000000;"
		"border: 5px solid #604020;"
		"padding: 8px;"
		"background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(210, 166, 121, 255), stop:1 rgba(128, 87, 48, 255));"
		"font-family: Goudy Old Style, Goudy Type, serif;"
		"font-size: 14px;"
		"}"
		"QTabBar::tab:selected, QTabBar::tab:hover {"
		"background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(230, 191, 148, 255), stop:1 rgba(180, 147, 104, 255));"
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
		"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(210, 166, 121, 255), stop:0.5 rgba(180, 120, 80, 255), stop:1 rgba(128, 87, 48, 255));"
		"}";

	QString frameCharacter = "QFrame {"
		"border: 3px solid #734d26;"
		"}"
		"QFrame > * { border: none; }";

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

	QString checkBox = "QCheckBox::indicator {"
		"width: 16px;"
		"height: 16px;"
		"border: 2px solid #ffb000;"
		"}"
		"QCheckBox::indicator:unchecked  {"
		"background: rgba(139,0,0,255);"
		"}"
		"QCheckBox::indicator:hover {"
		"background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,43,43,255), stop:1 rgba(139,0,0,255));"
		"}"
		"QCheckBox::indicator:checked { background: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(229,210,210,255), stop:1 rgba(139,0,0,255));}"
		"QCheckBox {"
		"color: #000000;"
		"font-family: Goudy Old Style, Goudy Type, serif;"
		"font-size: 14px;"
		"}";

	QString inputField = "border: 3px solid #734d26; background-color: rgba(230, 191, 148, 255);";
	QString normalInput = "QLineEdit { color: #000000; " + inputField + "}";
	QString comboBoxInput = "QComboBox { color: #000000; font-family: Goudy Old Style, Goudy Type, serif; font-size: 14px; padding-left: 2px; " + inputField + "}"
		"QComboBox QListView { color: #000000; font-family: Goudy Old Style, Goudy Type, serif; font-size: 14px; " + inputField + "}"
		"QScrollBar:vertical { background-color: rgb(210, 166, 121); }"
		"QScrollBar::handle:vertical { border: 2px solid #734d26; }"
		"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; subcontrol-position: top; subcontrol-origin: margin; background-color: rgba(230, 191, 148, 255); }"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background-color: rgba(180, 147, 104, 255); border-left: 2px groove #734d26; }";

	QString avatarBackground = "QLabel { background-color: rgba(230, 191, 148, 255); }";
	QString frameAvatar = "QFrame { border: 3px solid #734d26; }";

	QString backstory = "QTextEdit { color: #000000; margin: 1px 1px 1px 3px; " + inputField + " }"
		"QScrollBar:vertical { background-color: #d2a679; }"
		"QScrollBar::handle:vertical { border: 2px solid #734d26; }"
		"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; subcontrol-position: top; subcontrol-origin: margin; background-color: rgba(230, 191, 148, 255); }"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background-color: rgba(180, 147, 104, 255); border-left: 2px groove #734d26; }";

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
		"}";

	QString errorBox = "QMessageBox {"
		"border-top: 5px ridge #734d26;"
		"border-left: 5px groove #734d26;"
		"border-right: 5px ridge #734d26;"
		"border-bottom: 5px groove #734d26;"
		"background-color: rgba(230, 191, 148, 255);"
		"}"
		+ commonButtonStyle
		+ normalLabel;
};
#endif