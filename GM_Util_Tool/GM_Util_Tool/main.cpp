#include "app.h"
#include <QtWidgets/QApplication>
#include <PlayableCharacter.h>
#include <Team.h>
#include<iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    app w;
    w.show();
    
    return a.exec();
}
