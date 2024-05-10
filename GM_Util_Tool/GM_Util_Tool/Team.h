#pragma once
#include "PlayableCharacter.h"
class Team
{
	PlayableCharacter team[10];
	int playersAmount = 0;
public:
	void addCharacter();
	void addCharacter(PlayableCharacter newPlayer);
	int getTeamSize();
	PlayableCharacter& getCharacter(int characterId);
	
};

