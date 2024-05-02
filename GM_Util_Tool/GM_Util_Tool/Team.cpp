#include "Team.h"

void Team::addCharacter(PlayableCharacter newPlayer)
{
	playersAmount++;
	team[playersAmount - 1] = newPlayer;
}