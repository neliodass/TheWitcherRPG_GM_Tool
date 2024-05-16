#pragma once
#include <vector>
#include "PlayableCharacter.h"
class Team
{
	std::vector<PlayableCharacter> team;

public:
	void addCharacter();
	void addCharacter(PlayableCharacter newPlayer);
	int getTeamSize();
	PlayableCharacter& getCharacter(int characterId);
	void saveToBinaryFile(const std::string& filename);
	void readFromBinaryFile(const std::string& filename);
	
};

