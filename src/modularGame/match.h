#include "cup.h"
#include <string>
using namespace std;
class match
{
        private:
                string player1;
//              string player2;
                cup cupRack[6];
        public:
                bool isGameOver();
		void startGame(cup cups[6]);
};
~        
