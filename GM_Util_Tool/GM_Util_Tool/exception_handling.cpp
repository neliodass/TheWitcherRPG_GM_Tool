#include "GM_Util_Tool.h"
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
	exc_window.setStyleSheet("QMessageBox {"
		"border-top: 5px ridge #734d26;"
		"border-left: 5px groove #734d26;"
		"border-right: 5px ridge #734d26;"
		"border-bottom: 5px groove #734d26;"
		"background-color: rgba(230, 191, 148, 255);"
		"}"
		"QLabel {"
		"font-family: Goudy Old Style, Goudy Type, serif;"
		"font-size: 14px;"
		"font-weight: bold;"
		"}");
	exc_window.setWindowTitle("Error");
	for (auto i = exceptions.begin(); i != exceptions.end(); i++) {
		window_text.append(*i);
	}
	exc_window.setText(window_text);
	exc_window.setIcon(QMessageBox::Critical);
	exc_window.exec();
}

int characterSaveExceptions(QLineEdit* name, QLineEdit* age, QLineEdit*	hp, QLineEdit* armor, QLineEdit* attack_pot, QLineEdit* evasion_pot, QLineEdit* sorcery_pot, QLineEdit* weapon_damage) {
	std::vector<std::string> character_exceptions;
	
	//Is name empty
	if (name->text().isEmpty()) {
		character_exceptions.push_back("The character name is empty!\nPlease name your characer.\n\n");
	}
	/*
	//Are integer values negative
	std::vector<QLineEdit*> int_inputs = { age, hp, armor, attack_pot, evasion_pot, sorcery_pot, weapon_damage };
	std::vector<std::string> labels = { "Age", "HP", "Armor", "Attack Potencial", "Evasion Potencial", "Sorcery Potencial", "Weapon Damage" };
	
	auto is_negative = [](QLineEdit* input) {
		return input->text().toInt() < 0;
	};
	if (std::any_of(int_inputs.begin(), int_inputs.end(), is_negative)) {
		character_exceptions.push_back("None of integer vaules can be negative!\n");
	/*if (age->text().toInt() < 0 || hp->text().toInt() < 0 || armor->text().toInt() < 0 || attack_pot->text().toInt() < 0 || evasion_pot->text().toInt() < 0 || sorcery_pot->text().toInt() < 0 || weapon_damage->text().toInt() < 0) {
		character_exceptions.push_back("They cant bet negative!");
	}*/

	if (character_exceptions.empty()) {
		return 0;

	showExceptionMessageBox(character_exceptions);
	return -1;
}