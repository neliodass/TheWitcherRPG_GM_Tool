#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "ui_GM_Util_Tool.h"
#include "Team.h"

class GM_Util_Tool : public QMainWindow
{
    Q_OBJECT

public:
    GM_Util_Tool(QWidget* parent = nullptr);
    ~GM_Util_Tool();


public slots:
    void on_buttonAvatarChoice_clicked();
    void createCharacterWidgets();
    void on_buttonSave_clicked();
    void loadCharacterForEdit( PlayableCharacter& widgetCharacter);
    void on_saveTeamFileButton_clicked();
    void on_readTeamFileButton_clicked();
    void on_buttonDeleteAvatar_clicked();
    void clearUi();
   

private:
    Ui::GM_Util_ToolClass ui;
    Team newTeam;
    QString avatarPath = "";
    bool isCharacterLoaded = false;
    
    PlayableCharacter* currentlyEditing = nullptr;
};