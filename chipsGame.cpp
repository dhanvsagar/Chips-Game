#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_CHIPS = 100;
const float MAX_TURN = 0.5;

int main()
{

  int chipsInPile = 0;
  int chipsTaken  = 0;
  int maxPerTurn = 0;
  char nextGame = 'N';
  string playerName[2] = {"Tim", "Tom"};

  /*
  cout << "Player 1, enter your name\t:";
  cin >> playerName[0];
  cout << "Player 2, enter your name\t:";
  cin >> playerName[1];
  */

  srand(time(0));

  do
  {
    bool player1Turn = true;
    bool gameOver = false;
    chipsInPile = (rand() % MAX_CHIPS) + 1;
    maxPerTurn = (chipsInPile * MAX_TURN);
    cout << "Game started with " << chipsInPile << " chips" << endl;
    
    while( gameOver == false)
    {

      do
      {
        if(player1Turn)
        {
          cout << playerName[0] << ", How many chips would you like ..? " <<endl;
        }
        else
        {
          cout << playerName[1] << ", How many chips would you like ..? " <<endl;
        }
       // do 
        //{
          cout << "You can take maximum of ";
          if ( static_cast<int>(chipsInPile * MAX_TURN) == 0)
          {
            cout << "1" << endl;
          }
          else
          {
            cout << static_cast<int>(chipsInPile * MAX_TURN) << endl;
          }
          cin >> chipsTaken;
          
        //} while (chipsTaken > static_cast<int>(chipsInPile * MAX_TURN));
      } while ( (chipsTaken > maxPerTurn) && chipsInPile > 1);
      
      chipsInPile = chipsInPile - chipsTaken;
      cout << "There are " << chipsInPile << " left in the Pile" << endl;

      if (chipsInPile == 0)
      {
        gameOver = true;
        if(player1Turn)
        {
          cout << playerName[1] << ", You Won..!!! " <<endl;
        }
        else
        {
          cout << playerName[0] << ", You Won..!!! " <<endl;
        }
      }
      else
      {
        player1Turn = !player1Turn;
      }
    }
    cout << "Do you want to start a new game...? " << endl;
    cout << "Press Y or N :\t";
    cin >> nextGame;
  } while( (nextGame == 'Y') || (nextGame == 'y') );
  

  return 0;
}