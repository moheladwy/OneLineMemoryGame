#include <iostream>
using namespace std;

class Player
{
public:
    void setPlayerName(const string&);
    void setPlayerScore(unsigned const int&);

    unsigned int getPlayerScore();
    string getPlayerName();

    void updateScore();
private:
    unsigned int playerScore = 0;
    string playerName;
};