#include "OneLineMemory.hpp"
#include <Windows.h>
using namespace std;

vector<bool> choicesList(12, false);
vector<char> letters{ 'A','A','B','B','C','C','D','D','E','E','F','F' };

//-------------------------------CONSTRUCTOR------------------------------------
OneLineMemory::OneLineMemory() {
	shuffleLetterVector();
	cout << "Welcome in One Line Memory Game!" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	string name1, name2;
	while (true) {
		name1 = getPlayerName("First");
		name2 = getPlayerName("Second");
		try {
			if (name2 == name1)
				throw invalid_argument("The names must be different, Try again!");
			setPlayerName(name1, "First");
			setPlayerName(name2, "Second");
			break;
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
		}
	}
	cout << "First player will start then second player." << endl;
	cout << "-------------------------------------------------------------------" << endl;
	clearScreen();
}
//-------------------------------DESTRUCTOR------------------------------------
OneLineMemory::~OneLineMemory() {
	printWinner();
	cout << "Thanks for playing one line memory game." << endl;
	cout << "Auther: Mohamed Hussein Eladwy." << endl;
	cout << "-------------------------------------------------------------------" << endl;
}
//---------------------------------------------------------------------------
// change the order of the letters vector to a random order each time.
//---------------------------------------------------------------------------
void OneLineMemory::shuffleLetterVector() {
	random_device rd;
	default_random_engine rng(rd());
	shuffle(letters.begin(), letters.end(), rng);
}
//---------------------------------------------------------------------------
void OneLineMemory::clearScreen() {
	Sleep(3000);
	system("cls");
}
//---------------------------------------------------------------------------
void OneLineMemory::drowBoard(const string &name, unsigned const int&score) {
	cout << name << " turn, your score = " << score << endl;
	for (int i = 0; i < 12; i++) {
		if (choicesList[i])
			cout << letters[i] << " ";
		else
			cout << i + 1 << " ";
	}
	cout << endl;
}
//---------------------------------------------------------------------------
string OneLineMemory::getPlayerName(const string& turn) {
	string name = "";
	cout << turn << " Player Name: ";
	while (name.empty())
		getline(cin, name);
	return name;
}
//---------------------------------------------------------------------------
bool OneLineMemory::isValidName(const string& name) {
	regex isValid("^[a-zA-Z]+([ -]?[A-Za-z]*)+$");
	return regex_match(name, isValid);
}
//---------------------------------------------------------------------------
void OneLineMemory::setPlayerName(const string& name, const string& turn) {
	if (!isValidName(name))
		throw invalid_argument("The name is invalid, Try again!");
	if (turn == "First")
		player1.setPlayerName(name);
	else
		player2.setPlayerName(name);
}
//---------------------------------------------------------------------------
string OneLineMemory::getChoice(const string& turn) {
	string getChoice = "";
	cout << "Enter the "<< turn <<" number: ";
	while (getChoice.empty())
		getline(cin, getChoice);
	return getChoice;
}
//---------------------------------------------------------------------------
bool OneLineMemory::isValidChoice(const string& choice) {
	regex isValid("^[1-9]|1[0-2]$");
	return regex_match(choice, isValid);
}
//---------------------------------------------------------------------------
unsigned int OneLineMemory::setChoice(const string& choice) {
	if (!isValidChoice(choice))
		throw invalid_argument("Invalid Input, Try again!");
	return stoi(choice);
}
//---------------------------------------------------------------------------
bool OneLineMemory::isChoicesTaken(unsigned const int& firstNumber, unsigned const int& secondNumber) {
	if (choicesList[firstNumber - 1] || choicesList[secondNumber - 1])
		return true;
	return false;
}
//---------------------------------------------------------------------------
bool OneLineMemory::isLettersEquals(unsigned const int& firstNumber, unsigned const int& secondNumber) {
	if (letters[firstNumber - 1] == letters[secondNumber - 1])
		return true;
	return false;
}
//---------------------------------------------------------------------------
void OneLineMemory::updateChoicesList(unsigned const int& firstNumber, unsigned const int& secondNumber) {
	if (isLettersEquals(firstNumber, secondNumber)) {
		choicesList[firstNumber - 1] = letters[firstNumber - 1];
		choicesList[secondNumber - 1] = letters[secondNumber - 1];
	}
}
//---------------------------------------------------------------------------
void OneLineMemory::getNumbers(unsigned int& firstNumber, unsigned int& secondNumber) {
	firstNumber = setChoice(getChoice("first"));
	secondNumber = setChoice(getChoice("second"));
	if (firstNumber == secondNumber)
		throw invalid_argument("The second number must be different from the first one, Try again!");
	if (isChoicesTaken(firstNumber, secondNumber))
		throw invalid_argument("The number/s you enterd was taken before, Try again and choice anthor one!");
}
//---------------------------------------------------------------------------------
// Returning the players profiles by reference to use them in currentTurn function.
//---------------------------------------------------------------------------------
Player& OneLineMemory::getPlayer(unsigned const int& number) {
	if (number == 1)
		return player1;
	return player2;
}
//---------------------------------------------------------------------------
void OneLineMemory::currentTurn(Player &player) {
	drowBoard(player.getPlayerName(), player.getPlayerScore());
	unsigned int firstNumber, secondNumber;
	while (true) {
		try {
			getNumbers(firstNumber, secondNumber);
			break;
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
		}
	}
	if (isLettersEquals(firstNumber, secondNumber)) {
		cout << "Letters Match \":)" << endl;
		updateChoicesList(firstNumber, secondNumber);
		player.updateScore();
	}
	else
		cout << "Letters Do Not Match \":(" << endl;
}
//---------------------------------------------------------------------------
bool OneLineMemory::isGameEnded() {
	for (const bool& elem : choicesList)
		if (!elem)
			return false;
	return true;
}
//---------------------------------------------------------------------------
void OneLineMemory::printWinner() {
	cout << "Player 1 {" << player1.getPlayerName() << "} had score = " << player1.getPlayerScore() << endl;
	cout << "Player 2 {" << player2.getPlayerName() << "} had score = " << player2.getPlayerScore() << endl;

	if (player1.getPlayerScore() > player2.getPlayerScore())
		cout << player1.getPlayerName() << " won!" << endl;
	
	else if (player1.getPlayerScore() < player2.getPlayerScore())
		cout << player2.getPlayerName() << " won!" << endl;
	
	else if (player1.getPlayerScore() == player2.getPlayerScore())
		cout << "Drow!" << endl;

	cout << "---------------------------------------------------------------------------" << endl;
}
//---------------------------------------------------------------------------