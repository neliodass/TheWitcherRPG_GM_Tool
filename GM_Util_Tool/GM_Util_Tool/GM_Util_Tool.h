#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "ui_GM_Util_Tool.h"

class GM_Util_Tool : public QMainWindow
{
    Q_OBJECT

public:
    GM_Util_Tool(QWidget *parent = nullptr);
    ~GM_Util_Tool();


public slots:
    void on_buttonAvatarChoice_clicked();
    void on_buttonSave_clicked();

private:
    Ui::GM_Util_ToolClass ui;
    QString avatarPath = "";
};