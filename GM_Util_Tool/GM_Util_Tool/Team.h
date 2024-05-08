#pragma once
#include "PlayableCharacter.h"
class Team
{
	PlayableCharacter team[10];
	int playersAmount = 0;
public:
	void addCharacter(PlayableCharacter newPlayer);
	int getTeamSize();
	const PlayableCharacter getCharacter(int characterId);
	
};

