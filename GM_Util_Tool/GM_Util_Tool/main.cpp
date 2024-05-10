#include "GM_Util_Tool.h"
#include <QtWidgets/QApplication>
#include <PlayableCharacter.h>
#include <Team.h>
#include<iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GM_Util_Tool w;
    w.show();
    
    return a.exec();
}
