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
	std::ofstream file(filename, std::ios::app |std::ios::binary);
	if (file.is_open()) {
		file.write(reinterpret_cast<const char*>(&maxHealth), sizeof(maxHealth));
		int length = name.size();
		file.write(reinterpret_cast<const char*>(&length), sizeof(length));
		file.write(name.c_str(), length );
		file.write(reinterpret_cast<const char*>(&currentHealth), sizeof(currentHealth));
		file.write(reinterpret_cast<const char*>(&armor), sizeof(armor));
		file.write(reinterpret_cast<const char*>(&evadePotential), sizeof(evadePotential));
		file.write(reinterpret_cast<const char*>(&attackPotential), sizeof(attackPotential));
		file.write(reinterpret_cast<const char*>(&sorceryPotential), sizeof(sorceryPotential));
		length = weapon.name.size();
		file.write(reinterpret_cast<const char*>(&length), sizeof(length));
		file.write(weapon.name.c_str(), length);
		file.write(reinterpret_cast<const char*>(&weapon.damage), sizeof(weapon.damage));
		file.write(reinterpret_cast<const char*>(&alive), sizeof(alive));
		file.write(reinterpret_cast<const char*>(&magical), sizeof(magical));
		file.write(reinterpret_cast<const char*>(&characterRace), sizeof(characterRace));
		file.write(reinterpret_cast<const char*>(&characterClass), sizeof(characterClass));
		file.write(reinterpret_cast<const char*>(&age), sizeof(age));
		length = description.size();
		file.write(reinterpret_cast<const char*>(&length), sizeof(length));
		file.write(description.c_str(), length);
		file.close();
		std::cout << "Dane zapisane do pliku binarnego.\n";
	}
	else {
		std::cerr << "Nie mo¿na otworzyæ pliku binarnego.\n";
	}
}
void PlayableCharacter::readFromBinaryFile(std::ifstream& file) {
	
	if (file.is_open()) {
		file.read(reinterpret_cast<char*>(&maxHealth), sizeof(maxHealth));
		int length;
		file.read(reinterpret_cast< char*>(&length), sizeof(length));
		char* buffer = new char[length + 1]; 
		file.read(buffer, length);
		buffer[length] = '\0';
		name = std::string(buffer); 
		delete[] buffer;
		file.read(reinterpret_cast<char*>(&currentHealth), sizeof(currentHealth));
		file.read(reinterpret_cast<char*>(&armor), sizeof(armor));
		file.read(reinterpret_cast<char*>(&evadePotential), sizeof(evadePotential));
		file.read(reinterpret_cast<char*>(&attackPotential), sizeof(attackPotential));
		file.read(reinterpret_cast<char*>(&sorceryPotential), sizeof(sorceryPotential));
		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		buffer = new char[length + 1];
		file.read(buffer, length);
		buffer[length] = '\0';
		weapon.name = std::string(buffer);
		delete[] buffer;
		file.read(reinterpret_cast< char*>(&weapon.damage), sizeof(weapon.damage));
		file.read(reinterpret_cast<char*>(&alive), sizeof(alive));
		file.read(reinterpret_cast<char*>(&magical), sizeof(magical));
		file.read(reinterpret_cast<char*>(&characterRace), sizeof(characterRace));
		file.read(reinterpret_cast<char*>(&characterClass), sizeof(characterClass));
		file.read(reinterpret_cast<char*>(&age), sizeof(age));
		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		buffer = new char[length + 1];
		file.read(buffer, length);
		buffer[length] = '\0';
		description = std::string(buffer);
		delete[] buffer;
	
		//TODO oblusga bledu
	}
	else {
		std::cerr << "Nie mo¿na otworzyæ pliku binarnego.\n";
	}
}

