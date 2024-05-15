#include "Team.h"
#include<fstream>
#include<iostream>
void Team::addCharacter()
{
	team.push_back(PlayableCharacter());
}

void Team::addCharacter(PlayableCharacter newPlayer )
{
	team.push_back(newPlayer);
}

int Team::getTeamSize()
{
	return team.size();
}

 PlayableCharacter& Team::getCharacter(int characterId)
{
	//TODO:Dodac obsluge czy jest ID jest w team;
	if (characterId > 0 && characterId <= team.size())
	{
		return this->team[characterId - 1];
	}
}
 void Team::saveToBinaryFile(const std::string& filename) {
	 std::ofstream file(filename, std::ios::binary);
	 if (file.is_open()) {
		 int length = team.size();
		 file.write(reinterpret_cast<const char*>(&length), sizeof(length));
		 file.close();
		 for (auto character : team) {
			 character.saveToBinaryFile(filename);
		 }
		 std::cout << "Dane zapisane do pliku binarnego.\n";
	 }
	 else {
		 std::cerr << "Nie mo¿na otworzyæ pliku binarnego.\n";
	 }
 }
void Team::readFromBinaryFile(const std::string& filename) {
 std::ifstream file(filename, std::ios::binary);
 if (file.is_open()) {
	 int length = team.size();
	 file.read(reinterpret_cast<char*>(&length), sizeof(length));
	 PlayableCharacter e1;
	 for (int i = 0; i < length;i++) {
		 e1.readFromBinaryFile(file);
		 this->addCharacter(e1);
	 }
	 file.close();
	 //TODO Monit o udanym odczycie pliku
	 //std::cout << "Dane wczytane z pliku binarnego.\n";
 }
 else {
	 std::cerr << "Nie mo¿na otworzyæ pliku binarnego.\n";
 }
 }