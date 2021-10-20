//Raed K 
#include <iostream>
#include <cstring>
using namespace std; 

#define X_MOVE 1
#define O_MOVE 2

int checkWin(char board[3][3], int i); 
void print(char board[3][3]); 
void clear(char board[3][3]); 

int main() {  
// var declarations 
bool stillplay = true;
bool owin = false; 
bool xwin = false; 
int counter = 1; 
int x = 0; 
int o = 0;  
int t = 0; 
char str[3]; 
char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; 
const int X_TURN = 0;
const int O_TURN = 1;
int turn = X_TURN; //set first player to turn 
bool clean; 

print(board);       
while(stillplay) {
  cout << "Enter a letter followed by a number: "; 
  cin >> str; 
 if (strlen(str) != 2) //input has to be 2 characters and null
	cout << "Please enter a letter followed by a number: " << endl;
    else {
	if ((str[0] != 'a') && (str[0] != 'b') && (str[0] != 'c'))  //check letter
	  cout << "Row can only be a, b, or c." << endl;
	 else {
	  if (str[1] != '1' && str[1] != '2' && str[1] != '3') //check num
	    cout << "Column can only be 1, 2, or 3." << endl;
	   
    else { //clean 
	    int row = str[0] - 'a';
	    int column = str[1] - '1';
	  
	    //clean x move
	    if ((turn == X_TURN) && (board[row][column] == ' ')){
	      board[row][column] = X_MOVE;
         print(board); 
	      clean = true;
	    }
	    //if there is already a piece there...
	    else if ((turn == X_TURN) && (board[row][column] != ' ')){
	      cout << "There is already a piece there." << endl;
	    }
	    //successful O move!
	    if ((turn == O_TURN) && (board[row][column] == ' ')){
	      board[row][column] = O_MOVE;
         print(board); 
	      clean = true;
	    }
	  
	    //if there is already a piece there...
	    else if ((turn == O_TURN) && (board[row][column] != ' ')) 
	      cout << "There is already a piece there." << endl;

	    //swap turns
	    if (turn == O_TURN && clean == true){
	      cout << "X turn" << endl; 
	      turn = X_TURN;
	    }
	    else if (turn == X_TURN && clean == true){
	      cout << "O turn" << endl;
	      turn = O_TURN;
          }

      if (checkWin(board, 1)) {
            cout << "X won!" << endl;
            x++;
            cout << "X Wins: " << x << endl; 
            cout << "O Wins: " << o << endl; 
            cout << "Ties: " << t << endl; 
            char yesno; 
            cout << "Would you like to play again?" << endl;
            cout << "Enter y for yes or n for no: "; 
            cin >> yesno; 
            if (yesno == 'y') {
                clear(board);
                print(board); 
                turn = X_TURN; 
            }
            else if(yesno == 'n') 
                stillplay = false; 

           }
      else if (checkWin(board, 2)) {
            cout << "O won!" << endl; 
            o++; 
             cout << "X Wins: " << x << endl; 
            cout << "O Wins: " << o << endl; 
            cout << "Ties: " << t << endl; 
            char yesno; 
            cout << "Would you like to play again?" << endl;
            cout << "Enter y for yes or n for no: "; 
            cin >> yesno; 
            if (yesno == 'y') {
                clear(board); 
                print(board);  
                turn = X_TURN; 
            }  
            else if(yesno == 'n') 
                stillplay = false; 
          }
           else {
            cout << "It's a Tie!" << endl; 
            t++; 
            cout << "X Wins: " << x << endl; 
            cout << "O Wins: " << o << endl; 
            cout << "Ties: " << t << endl; 
            char yesno; 
            cout << "Would you like to play again?" << endl;
            cout << "Enter y for yes or n for no: "; 
            cin >> yesno; 
            if (yesno == 'y') {
                clear(board); 
                print(board);  
                turn = X_TURN; 
            }  
            else if(yesno == 'n') 
                stillplay = false; 
          }
        }
	    }
    }
  }
}

void print(char board[3][3]){
  cout << "  1 2 3" << endl;
  char output[4]; // "a, b, c...
   
  for (int i = 0; i < 3; i++){ //print out letters in column
    int counter = 0;
    output[0] = ('a'+i); //increment the letter each iteration (a->b->c)
    counter++;
    
    for (int j = 0; j < 3; j++){
      if (board[i][j] == X_MOVE){
	      output[counter] = 'X'; //display an X
	      counter++;
      } 
      else if (board[i][j] == O_MOVE){
	      output[counter] = 'O'; //display an O
	      counter++; 
      } 
      else if (board[i][j] == ' '){
	    output[counter] = ' '; //display a space
	    counter++;
      }
    }
    //print out line with proper spacing 
    cout << output[0] << " " << output[1] << " " << output[2] << " " << output[3] << endl;
  }
}

int checkWin(char board[3][3], int i){
    if(board[0][0] == i && board[0][1] == i && board[0][2] == i){ //top row across
      return 1;
    }
    else if(board[0][0] == i && board[1][1] == i && board[2][2] == i){ //diagonal top L to bottom R
      return 1;
    }
    else if(board[0][2] == i && board[1][1] == i && board[2][0] == i){ //diagonal top R to bottom L
      return 1;
    }
    else if(board[0][2] == i && board[1][2] == i && board[2][2] == i){ //right column down
      return 1;
    }
    else if(board[1][0] == i && board[1][1] == i && board[1][2] == i){ //middle row across
      return 1;
    }
    else if(board[2][0] == i && board[2][1] == i && board[2][2] == i){ //bottom row across
      return 1;
    }
    else if(board[0][0] == i && board[1][0] == i && board[2][0] == i){ //left column down
      return 1;
    }
    else if(board[0][1] == i && board[1][1] == i && board[2][1] == i){ //middle row down
      return 1;
    }
 return 0; //nobody won
}

void clear(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' '; 
    }
  }
}
