#include <vector>
#include <random>
#include <algorithm>
#include <regex>
#include "Player.hpp"
using namespace std;

extern vector<bool> choicesList;
extern vector<char> letters;

class OneLineMemory
{
public:
    OneLineMemory();
    ~OneLineMemory();

    void currentTurn(Player&);
    void clearScreen();
    bool isGameEnded();
    
private:
    Player player1, player2;
    
    void shuffleLetterVector();
    void setPlayerName(const string&, const string&);
    void drowBoard(const string&, unsigned const int&);
    void getNumbers(unsigned int&, unsigned int&);
    void updateChoicesList(unsigned const int&, unsigned const int&);
    void printWinner();

    string getPlayerName(const string&);
    string getChoice(const string&);

    unsigned int setChoice(const string&);
    Player& getPlayer(unsigned const int&);

    bool isValidName(const string&);
    bool isValidChoice(const string&);
    bool isChoicesTaken(unsigned const int&, unsigned const int&);
    bool isLettersEquals(unsigned const int&, unsigned const int&);
};