#include "GM_Util_Tool.h"
#include<iostream>
#include <PlayableCharacter.h>
#include<QFontDatabase>
#include <QtWidgets/QApplication>
#include <Team.h>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	GM_Util_Tool w;
	QFontDatabase::addApplicationFont("./resources/Berylium.ttf");
	w.set_style();
	w.show();
	return a.exec();
}