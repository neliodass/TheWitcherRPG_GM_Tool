#pragma once
#include "Entity.h"
#include <string>
#include<QImage>

enum CharacterRace{human,werebbubb,elf,gnome,dwarf,halfling,vran};
enum CharacterClass{bard,mage,druid,priest,merchant,doctor,criminal,craftsman,noble,witcher,man_at_arms};

class PlayableCharacter :
    public Entity
{
    protected:
        CharacterRace characterRace = human;
        CharacterClass characterClass = bard;
        int age = 0;
        std::string description = "";
        QImage characterImage;
    public:
        PlayableCharacter() :characterImage() {};
        PlayableCharacter(CharacterRace characterRace, CharacterClass characterClass, const int age, const std::string description);
        inline void setRace(const CharacterRace characterRace) { this->characterRace = characterRace; }
        inline void setClass(const CharacterClass characterClass) { this->characterClass = characterClass; }
        inline void setAge(const int age) { this->age = age; }
        inline void setDescription(const std::string description) { this->description = description; }
        inline void setCharacterImage(const QImage image) { this->characterImage = image; }
        auto getRace() const -> const CharacterRace { return characterRace; }
        auto getClass() const -> const CharacterClass { return characterClass; }
        auto getClassString()const -> const std::string;
        auto getAge() const -> const int { return age; }
        auto getDescription() const -> const std::string { return description; }
        auto getCharacterImage() const -> const QImage { return characterImage; }
        void saveToBinaryFile(const std::string& filename);
        void readFromBinaryFile(std::ifstream& file);
};

