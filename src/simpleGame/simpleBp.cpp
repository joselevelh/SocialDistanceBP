#include <iostream>
#include <string>
using namespace std;

void startGame()
{
	string gameUpdate;
	bool cupStates[] = {false,false,false};
	bool isGameOver = false;
	while (!isGameOver)
	{
		isGameOver = true;
//		cout << "Ready for next throw \n";
		cin >> gameUpdate;
		if (gameUpdate == "CUP_1_SCORED")
                       	cupStates[0] = true;
		if (gameUpdate =="CUP_2_SCORED")
			 cupStates[1] = true;
		if (gameUpdate =="CUP_3_SCORED")
                         cupStates[2] = true;
		for(int i = 0; i<3; i++)
		{
			cout <<"Cups state"<<i<<" is: " << cupStates[i] << "\n";
			if (cupStates[i]==false)
			{
				isGameOver = false;
				
			}
		}
	}
	cout << "Nice you Finished the round! \n";
}

int main()
{
	string instruction;
	cout << "Welcome to Simple Beer Pong!" << "\n";
	cout << "Type s to start \n";
	cin >> instruction;
	if (instruction == "s")
	{
		cout << "Eye to Eye! \n";
		startGame();
	}
	else
		cout<<" OK see ya then! \n";
	exit(0);
}
