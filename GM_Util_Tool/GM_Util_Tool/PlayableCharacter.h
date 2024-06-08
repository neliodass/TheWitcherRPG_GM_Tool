#pragma once
#include "Entity.h"
#include <string>
#include<QImage>

enum CharacterRace{dwarf,elf,gnome,halfling,human,werebubb,vran};
enum CharacterClass{bard,craftsman,criminal,doctor,druid,mage,man_at_arms,merchant,noble,priest,witcher};

class PlayableCharacter :
    public Entity
{
    protected:
        CharacterRace characterRace = human;
        CharacterClass characterClass = bard;
        int age = 0;
        std::string description = "";
        QImage characterImage;
        int tempId = -1;
    public:
        PlayableCharacter() :characterImage() {};
        PlayableCharacter(CharacterRace characterRace, CharacterClass characterClass, const int age, const std::string description);
        inline void setRace(const CharacterRace characterRace) { this->characterRace = characterRace; }
        inline void setClass(const CharacterClass characterClass) { this->characterClass = characterClass; }
        inline void setAge(const int age) { this->age = age; }
        inline void setDescription(const std::string description) { this->description = description; }
        inline void setCharacterImage(const QImage image) { this->characterImage = image; }
        inline void setTempId(const int tempId) { this->tempId = tempId; }
        auto getRace() const -> const CharacterRace { return characterRace; }
        auto getClass() const -> const CharacterClass { return characterClass; }
        auto getClassString()const -> const std::string;
        auto getAge() const -> const int { return age; }
        auto getDescription() const -> const std::string { return description; }
        auto getCharacterImage() const -> const QImage { return characterImage; }
        void saveToBinaryFile(const std::string& filename);
        void readFromBinaryFile(std::ifstream& file);
        auto getTempId() const -> const int { return tempId; }
};

