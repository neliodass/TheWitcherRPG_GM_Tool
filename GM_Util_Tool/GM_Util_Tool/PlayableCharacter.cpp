#include "PlayableCharacter.h"

PlayableCharacter::PlayableCharacter(CharacterRace characterRace, CharacterClass characterClass, const int age)
{
	this->characterRace = characterRace;
	this->characterClass = characterClass;
	this->age = age;
}

PlayableCharacter::PlayableCharacter(const PlayableCharacter&)
{

}