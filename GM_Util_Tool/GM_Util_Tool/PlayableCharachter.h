#pragma once
#include "Entity.h"
enum CharacterRace{human,elf,dwarf,witcher,halfling,gnome,vran,werebbubb};
enum CharacterClass{bard,craftsman,criminal,doctor,druid,mage,man_at_arms,merchant,priest,witcher};

class PlayableCharachter :
    public Entity
{
    protected:
        CharacterRace characterRace;
        CharacterClass characterClass;
        int age;

};

