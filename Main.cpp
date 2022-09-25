#include "OneLineMemory.hpp"
using namespace std;

int main()
{
	OneLineMemory game;

	while (!game.isGameEnded()) {
	
		game.currentTurn(game.getPlayer(1));
		game.clearScreen();
		
		if (!game.isGameEnded()) {
		
			game.currentTurn(game.getPlayer(2));
			game.clearScreen();
		}
	}
	return 0;
}