#pragma once
#include "Entity.h"
#include <string>
#include<QImage>

enum CharacterRace { dwarf, elf, gnome, halfling, human, werebubb, vran };
enum CharacterClass { bard, craftsman, criminal, doctor, druid, mage, man_at_arms, merchant, noble, priest, witcher };

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
	const CharacterRace getRace() const { return characterRace; }
	const CharacterClass getClass() const { return characterClass; }
	const std::string getClassString() const;
	const int getAge() const { return age; }
	const std::string getDescription() const { return description; }
	const QImage getCharacterImage() const { return characterImage; }
	void saveToBinaryFile(const std::string& filename);
	void readFromBinaryFile(std::ifstream& file);
	const int getTempId() const { return tempId; }
};
