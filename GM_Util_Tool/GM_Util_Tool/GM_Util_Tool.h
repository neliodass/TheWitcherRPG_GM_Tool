#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GM_Util_Tool.h"

class GM_Util_Tool : public QMainWindow
{
    Q_OBJECT

public:
    GM_Util_Tool(QWidget *parent = nullptr);
    ~GM_Util_Tool();

private:
    Ui::GM_Util_ToolClass ui;
};
