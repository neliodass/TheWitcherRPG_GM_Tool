#pragma once
#include "GM_Util_Tool.h"
#include "MedivalStyleSheet.h"
#include <iostream>
#include <QEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QString>
#include <string>
#include <vector>
class GM_Util_Tool;

extern int characterSaveExceptions(const GM_Util_Tool& GM_Util_Tool);
class ExceptionMessageBox : public QMessageBox
{
public:
	ExceptionMessageBox(QWidget* parent = nullptr) : QMessageBox(parent)
	{
		this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
		this->setIcon(QMessageBox::Critical);
		this->setWindowTitle("Error");
		this->setStyleSheet(MedivalStyleSheet().errorBox);
	}
protected:
	bool event(QEvent* key_pressed) override
	{
		if (key_pressed->type() == QEvent::KeyPress)
		{
			close();
			return true;
		}
		return QMessageBox::event(key_pressed);
	}
};
