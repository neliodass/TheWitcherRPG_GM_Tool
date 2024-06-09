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
	if (characterId > 0 && characterId <= team.size())
	{
		return this->team[characterId - 1];
	}
}
 void Team::saveToBinaryFile(const std::string& filename) {
	 std::ofstream file(filename, std::ios::binary);
	 int length = team.size();
	 file.write(reinterpret_cast<const char*>(&length), sizeof(length));
	 file.close();
	 for (auto character : team) {
	  character.saveToBinaryFile(filename);
	 }
	
 }
bool Team::readFromBinaryFile(const std::string& filename) {
	team.clear();
 std::ifstream file(filename, std::ios::binary);
 if (file.is_open()) {
	 try
	 {
	 int length;
	 file.read(reinterpret_cast<char*>(&length), sizeof(length));
	 for (int i = 0; i < length;i++) {
		 PlayableCharacter e1;
		 e1.readFromBinaryFile(file);
		 this->addCharacter(e1);
	 }
	 file.close();
	 return true;
	 }
	 catch (...)
	 {
		 team.clear();
		 return false;
	 }

 }
 else {

	 return false;
 }
 }

void Team::removeCharacter(int toRemove)
{
	int indexToRemove = toRemove - 1;
	if (indexToRemove >= 0 && indexToRemove < team.size())
	{
		team.erase(team.begin() + indexToRemove);
	}
}

void Team::clearTeam()
{
	team.clear();
}
