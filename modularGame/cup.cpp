#include "cup.h"
#include <string>
using namespace std;

cup::cup()
{
	state = 0;
	count = 0;
}

int cup::getState()
{
	return state;		
} 

int cup::getCount()
{
	return count;
}

void cup:: makeCup()
{
	count++;
	state = 1;
}

void cup::emptyCup()
{
	state = 0;
}
