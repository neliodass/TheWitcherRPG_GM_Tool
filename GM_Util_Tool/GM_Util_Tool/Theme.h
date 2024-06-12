#pragma once

class Theme
{
public:
	virtual QString buttonAvatar() = 0;
	virtual QString buttonCharacter() = 0;
	virtual QString buttonTeam() = 0;
	virtual QString characterList() = 0;
	virtual QString tab() = 0;
	virtual QString mainBackground() = 0;
	virtual QString frameCharacter() = 0;
	virtual QString normalLabel() = 0;
	virtual QString titleLabel() = 0;
	virtual QString backstoryLabel() = 0;
	virtual QString checkBox() = 0;
	virtual QString normalInput() = 0;
	virtual QString comboBoxInput() = 0;
	virtual QString avatarBackground() = 0;
	virtual QString frameAvatar() = 0;
	virtual QString backstory() = 0;
	virtual QString scrollArea() = 0;
	virtual QString errorBox() = 0;
};
