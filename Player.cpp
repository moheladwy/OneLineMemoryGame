#include "Player.hpp"
using namespace std;

void Player::setPlayerName(const string& name) { 
	playerName = name; 
}

void Player::setPlayerScore(unsigned const int& score) { 
	playerScore = score; 
}

unsigned int Player::getPlayerScore() { 
	return playerScore; 
}

string Player::getPlayerName() { 
	return playerName; 
}

void Player::updateScore() {
	playerScore++;
}