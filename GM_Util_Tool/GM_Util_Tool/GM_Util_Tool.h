#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "ui_GM_Util_Tool.h"
#include "Team.h"
#include "exception_handling.h"

class GM_Util_Tool : public QMainWindow
{
	Q_OBJECT

public:
	GM_Util_Tool(QWidget* parent = nullptr);
	~GM_Util_Tool();
	void set_style();
	friend int characterSaveExceptions(const GM_Util_Tool& GM_Util_Tool);
	void setValidation();

public slots:
	void on_buttonAvatarChoice_clicked();
	void createCharacterWidgets();
	void on_buttonSave_clicked();
	void loadCharacterForEdit(PlayableCharacter& widgetCharacter);
	void on_saveTeamFileButton_clicked();
	void on_readTeamFileButton_clicked();
	void on_buttonDeleteAvatar_clicked();
	void clearUi();
	void on_buttonDelete_clicked();

private:
	Ui::GM_Util_ToolClass ui;
	Team newTeam;
	QString avatarPath = "";
	bool isCharacterLoaded = false;
	const QIntValidator* ageValidator = new QIntValidator(-999, 999);
	const QIntValidator* statValidator = new QIntValidator(-99, 99);
	PlayableCharacter* currentlyEditing = nullptr;
};