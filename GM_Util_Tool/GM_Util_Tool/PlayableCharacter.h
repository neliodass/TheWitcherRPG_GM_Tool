#pragma once
#include "Entity.h"
enum CharacterRace{human,elf,dwarf,halfling,gnome,vran,werebbubb};
enum CharacterClass{bard,craftsman,criminal,doctor,druid,mage,man_at_arms,merchant,priest,witcher};

class PlayableCharacter :
    public Entity
{
    protected:
        CharacterRace characterRace;
        CharacterClass characterClass;
        int age;
    public:
        PlayableCharacter();
        PlayableCharacter(CharacterRace characterRace, CharacterClass characterClass, const int age);
        PlayableCharacter(const PlayableCharacter&);

};

