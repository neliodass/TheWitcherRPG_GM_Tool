#include "Team.h"

void Team::addCharacter()
{
	team[playersAmount++] = PlayableCharacter();
}

void Team::addCharacter(PlayableCharacter newPlayer )
{
	team[playersAmount++] = newPlayer;
}

int Team::getTeamSize()
{
	return playersAmount;
}

 PlayableCharacter& Team::getCharacter(int characterId)
{
	//TODO:Dodac obsluge czy jest ID jest w team;
	if (characterId > 0 && characterId <= playersAmount)
	{
		return this->team[characterId - 1];
	}
}
