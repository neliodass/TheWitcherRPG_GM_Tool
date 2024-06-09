#include "GM_Util_Tool.h"
#include "exception_handling.h"


void showExceptionMessageBox(const std::vector<std::string>& exceptions) {
	ExceptionMessageBox exc_window;
	QString window_text;

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

