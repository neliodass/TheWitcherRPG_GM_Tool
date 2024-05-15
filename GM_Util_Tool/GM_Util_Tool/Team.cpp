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
 void Team::saveToBinaryFile(const std::string& filename){
	 std::ofstream file(filename, std::ios::binary);
	 if (file.is_open()) {
		 file.write(reinterpret_cast<const char*>(this), sizeof(*this));
		 file.close();
		 std::cout << "Dane zapisane do pliku binarnego.\n";
	 }
	 else {
		 std::cerr << "Nie mo¿na otworzyæ pliku binarnego.\n";
	 }
 }
 void Team::readFromBinaryFile(const std::string& filename) {
	 std::ifstream file(filename, std::ios::binary);
	 if (file.is_open()) {
		 file.read(reinterpret_cast<char*>(this), sizeof(*this));
		 file.close();
		 std::cout << "Dane wczytane z pliku binarnego.\n";
	 }
	 else {
		 std::cerr << "Nie mo¿na otworzyæ pliku binarnego.\n";
	 }
 }