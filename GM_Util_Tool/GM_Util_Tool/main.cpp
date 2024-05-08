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
    PlayableCharacter e1;
    e1.setName("Smefevit");
    e1.setMaxHealth(35);
    e1.setCurrentHealth(34);
    e1.setArmor(14);
    e1.setEvadePotential(14);
    e1.setAttackPotential(25);
    e1.setAlive(true);
    e1.setAlive(false);
    e1.setMagical(0);
    e1.setRace(gnome);
    e1.setClass(craftsman);
    e1.setAge(73);
    e1.setDescription("Moja historia zaczyna sie tak");
    Team newTeam;
    newTeam.addCharacter(e1);
    //newTeam.getCharacter(1).getWeapon().setName("Siekiera");
    
    std::cout << e1.getName() << std::endl;
    std::cout << e1.getRace() << std::endl;
    std::cout << newTeam.getCharacter(1).getMaxHealth() << std::endl;
    std::cout << newTeam.getCharacter(1).getName() << std::endl;
    std::cout << newTeam.getCharacter(1).getAge() << std::endl;
    std::cout << newTeam.getCharacter(1).getDescription() << std::endl;
    //std::cout << newTeam.getCharacter(1).getWeapon().getName() << std::endl;
    return a.exec();
}
