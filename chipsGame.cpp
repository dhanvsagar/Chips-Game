#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

string FindPlayerName(string names[], bool playerTurn);
void GetUserName(string players[]);
int AskMove(bool player1Turn, int chipsInPile, string names[]);
void WriteWinner(string name, int movesCount);

const int MAX_CHIPS = 100;
const float MAX_TURN = 0.5;
const string OUT_FILE_NAME = "Winners and Moves.txt";

int main()
{

  int chipsInPile = 0;
  int chipsTaken  = 0;
  int maxPerTurn = 0;
  int noOfMoves = 0;
  char nextGame = 'N';
  string winnerName = "";
  string playerName[2] = {"Tim", "Tom"};
  
  //seed the random number generator
  srand(time(0));

  //read usernames
  GetUserName(playerName);

  do
  {
    bool player1Turn = true;
    bool gameOver = false;
    chipsInPile = (rand() % MAX_CHIPS) + 1;
    cout << "Game started with " << chipsInPile << " chips \n" << endl;
    noOfMoves = 0;

    while( gameOver == false)
    {
      chipsTaken = AskMove(player1Turn, chipsInPile, playerName);
      chipsInPile = chipsInPile - chipsTaken;
      cout << "There are " << chipsInPile << " left in the Pile\n" << endl;

      if (chipsInPile == 0)
      {
        gameOver = true;
        winnerName = FindPlayerName(playerName, !player1Turn);
        cout << winnerName << ", You Won..!!! " <<endl;
      }
      else
      {
        player1Turn = !player1Turn;
        noOfMoves++;
      }
    }
    WriteWinner(winnerName, noOfMoves);
    cout << "Do you want to start a new game...? " << endl;
    cout << "Press Y or N :\t";
    cin >> nextGame;
    nextGame = toupper(nextGame);
  } while (nextGame == 'Y');
  

  return 0;
}

string FindPlayerName(string names[], bool playerTurn)
{
  if (playerTurn == true)
    return names[0];
  else
    return names[1];
}

void GetUserName(string players[])
{
  cout << "Player 1, enter your name\t:";
  cin >> players[0];
  cout << "Player 2, enter your name\t:";
  cin >> players[1];
}

int AskMove(bool player1Turn, int chipsInPile, string names[])
{
  int chipsTaken;
  int maxPerTurn = MAX_TURN * chipsInPile;
  do
      {
        cout << FindPlayerName(names, player1Turn) << ", How many chips would you like ..? " <<endl;

       // do 
        //{
          cout << "You can take maximum of ";
          if ( maxPerTurn == 0)
          {
            cout << "1" << endl;
          }
          else
          {
            cout << maxPerTurn << endl;
          }
          cin >> chipsTaken;
          
        //} while (chipsTaken > static_cast<int>(chipsInPile * MAX_TURN));
      } while ( (chipsTaken > maxPerTurn) && (chipsInPile > 1) );
      return chipsTaken;
}

void WriteWinner(string name, int movesCount)
{
  ofstream outFile;
  outFile.open(OUT_FILE_NAME, ios::app);
  if (!outFile.fail())
  {
    outFile << "Winner : "<< name << " Moves : " << movesCount << endl;
  }
  else
  {
    cout << "Error writting the Results " ;
  }
  outFile.close();
}