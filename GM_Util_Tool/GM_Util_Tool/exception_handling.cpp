#include "GM_Util_Tool.h"
#include "exception_handling.h"
#include <iostream>
#include <string>
#include <vector>
#include <QString>
#include <QMessageBox>
#include <QEvent>
#include <QKeyEvent>	

class ExceptionMessageBox : public QMessageBox {
protected:
	bool event(QEvent* key_pressed) override {
		if (key_pressed->type() == QEvent::KeyPress) {
			close();
			return true;
		}
		return QMessageBox::event(key_pressed);
	}
};

void showExceptionMessageBox(const std::vector<std::string>& exceptions) {
	ExceptionMessageBox exc_window;
	QString window_text;

	exc_window.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
	exc_window.setIcon(QMessageBox::Critical);
	exc_window.setWindowTitle("Error");
	exc_window.setStyleSheet("QMessageBox {"
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
		"font-family: Goudy Old Style, Goudy Type, serif;"
		"font-size: 14px;"
		"font-weight: bold;"
		"}");

	for (auto i = exceptions.begin(); i != exceptions.end(); i++) {
		window_text.append(*i);
	}
	window_text.append("Press any key or the OK button to exit this window.");
	exc_window.setText(window_text);
	exc_window.exec();
}

int characterSaveExceptions(const GM_Util_Tool &GM_Util_Tool) {
	std::vector<std::string> character_exceptions;
	std::vector<QLineEdit*> int_inputs = {GM_Util_Tool.ui.inputAge, GM_Util_Tool.ui.inputHP, GM_Util_Tool.ui.inputArmor, GM_Util_Tool.ui.inputAttack, GM_Util_Tool.ui.inputEvasion, GM_Util_Tool.ui.inputSorcery, GM_Util_Tool.ui.inputWeaponDamage};
	std::vector<std::string> labels = {"Age", "HP", "Armor", "Attack potential", "Evasion potential", "Sorcery potential", "Weapon damage"};

	//Is name empty
	if (GM_Util_Tool.ui.inputName->text().isEmpty()) {
		character_exceptions.push_back("The character name is empty!\nPlease name your characer.\n\n");
	}

	//Are integer values negative
	auto is_negative = [](QLineEdit* input) {
		return input->text().toInt() < 0;
		};

	if (std::any_of(int_inputs.begin(), int_inputs.end(), is_negative)) {
		character_exceptions.push_back("None of the integer values can be negative!\n");
		for (size_t i = 0; i < int_inputs.size(); ++i) {
			if (is_negative(int_inputs[i])) {
				character_exceptions.push_back(labels[i] + " is negative.\n");
			}
		}
		character_exceptions.push_back("\n");
	}
	
	if (character_exceptions.empty()) {
		return 0;
	}
	showExceptionMessageBox(character_exceptions);
		return -1;
}