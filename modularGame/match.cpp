#include "match.h"
#include <string>
using namespace std;

match::match()
{
	player1 = "Player1";
}

void cup::startGame(cup cups[6])
{
	cupRack = cups;
}

bool match::isGameOver()
{
	int i;
	for( i=0;i<6;i++)
	{
		if (cup[i].getState() == 0)
			return False;	
	}
	return True;
}
