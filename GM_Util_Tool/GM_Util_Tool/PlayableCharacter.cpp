#include "PlayableCharacter.h"
#include<iostream>
#include<fstream>


PlayableCharacter::PlayableCharacter(CharacterRace characterRace, CharacterClass characterClass, const int age, const std::string description)
{
	this->characterRace = characterRace;
	this->characterClass = characterClass;
	this->age = age;
	this->description = description;
}
void PlayableCharacter::saveToBinaryFile(const std::string& filename)
{
	std::ofstream file(filename, std::ios::out |std::ios::binary);
	if (file.is_open()) {
		file.write(name.c_str(), sizeof(name) + 1);
		file.write(reinterpret_cast<const char*>(&maxHealth), sizeof(maxHealth));
		file.write(reinterpret_cast<const char*>(&currentHealth), sizeof(currentHealth));
		file.write(reinterpret_cast<const char*>(&armor), sizeof(armor));
		file.write(reinterpret_cast<const char*>(&evadePotential), sizeof(evadePotential));
		file.write(reinterpret_cast<const char*>(&attackPotential), sizeof(attackPotential));
		file.write(reinterpret_cast<const char*>(&sorceryPotential), sizeof(sorceryPotential));
		file.write(weapon.name.c_str(), sizeof(weapon.name) + 1);
		file.write(reinterpret_cast<const char*>(&weapon.damage), sizeof(weapon.damage));
		file.write(reinterpret_cast<const char*>(&alive), sizeof(alive));
		file.write(reinterpret_cast<const char*>(&magical), sizeof(magical));
		file.write(reinterpret_cast<const char*>(&characterRace), sizeof(characterRace));
		file.write(reinterpret_cast<const char*>(&characterClass), sizeof(characterClass));
		file.write(reinterpret_cast<const char*>(&age), sizeof(age));
		file.write(description.c_str(), sizeof(description) + 1);
		file.close();
		std::cout << "Dane zapisane do pliku binarnego.\n";
	}
	else {
		std::cerr << "Nie mo¿na otworzyæ pliku binarnego.\n";
	}
}
void PlayableCharacter::readFromBinaryFile(const std::string& filename) {
	std::ifstream file(filename, std::ios::binary);
	if (file.is_open()) {
		char* buffer = new char[sizeof(name) + 1]; 
		file.read(buffer, sizeof(name));
		name = std::string(buffer); 
		delete[] buffer;
		file.read(reinterpret_cast< char*>(&maxHealth), sizeof(maxHealth));
		file.read(reinterpret_cast<char*>(&currentHealth), sizeof(currentHealth));
		file.read(reinterpret_cast<char*>(&armor), sizeof(armor));
		file.read(reinterpret_cast<char*>(&evadePotential), sizeof(evadePotential));
		file.read(reinterpret_cast<char*>(&attackPotential), sizeof(attackPotential));
		file.read(reinterpret_cast<char*>(&sorceryPotential), sizeof(sorceryPotential));
		char* buffer = new char[sizeof(weapon.name) + 1];
		file.read(buffer, sizeof(name));
		name = std::string(buffer);
		delete[] buffer;

		file.read(reinterpret_cast<char*>(this), sizeof(*this));
		file.close();
		std::cout << "Dane wczytane z pliku binarnego.\n";
	}
	else {
		std::cerr << "Nie mo¿na otworzyæ pliku binarnego.\n";
	}
}

