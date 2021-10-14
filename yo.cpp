//Raed K 
#include <iostream>
#include <cstring>
using namespace std; 


int checkWin(char square[3][3]) {
  //instead of having 1 for X and one for ), just check to see if valeus are same
    //row 1
    if (square[0][0] == square[1][0] && square[1][0] == square[2][0])

        return 1;
    //row 2
    else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])

        return 1;
    //row 3
    else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])

        return 1;
    //column 1
    else if (square[0][0] == square[0][1] && square[0][1] == square[0][2])

        return 1; 
    //column 2
    else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])

        return 1;
    //column 3
    else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])

        return 1;

    //diagonals
    else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])

        return 1;
    else if (square[2][0] == square[1][1] && square[1][1] == square[0][2])

        return 1;
    //draw
    else if (square[0][0] != '1' && square[1][0] != '2' && square[2][0] != '3' 
                    && square[0][1] != '4' && square[1][1] != '5' && square[2][1] != '6' 
                  && square[0][2] != '7' && square[1][2] != '8' && square[2][2] != '9')
        return 0;
    else
        return -1;
    //1 means win, 0 means tie, -1 means none
}

void owo(char square[3][3]){ 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			square[i][j] = 'x'; 
		}
	}
}

void print(char square[3][3]) {
	for (int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << square[i][j] << ' '; 
		}
		cout << "a" + 1 << endl; 
	}
}

int main() {  
    // var declarations 
    bool stillplay = true;
    int counter = 0; 
    char move; 
    char input[3]; 
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; 
    //displayBoard(board);
    //owo(board);  
    cout << "1 2 3" << endl;   
    print(board);     

    while(stillplay) {
	cout << "Enter a letter followed by a number: "; 
 	cin >> input; 	
    //keeps track of turns based on even and odd numbers; counter gets iterated up each turn 
    if (counter % 2 == 0) 
        move = 'X';
    else 
	move = 'O'; 

	if (input[0] == 'a' && input[1] == '1' && board[0][0] == ' ') {
		board[0][0] = move; 
		print(board); 
		checkWin(board);
	      	counter++; 	
	}
	else if(input[0] == 'a' && input[1] == '2' && board[0][1] == ' ') {
		board[0][1] = move; 
		print(board); 
		checkWin(board);
	      	counter++; 
	}

	else if(input[0] == 'a' && input[1] == '3' && board[0][2] == ' ') {
		board[0][2] = move; 
		print(board); 
		checkWin(board);
	      	counter++; 
	}

	else if(input[0] == 'b' && input[1] == '1' && board[1][0] == ' ') {
		board[1][0] = move; 
		print(board); 
		checkWin(board);
	      	counter++; 
	}

	else if(input[0] == 'b' && input[1] == '2' && board[1][1] == ' ') {
		board[1][1] = move; 
		print(board); 
		checkWin(board);
	      	counter++; 
	}

	else if(input[0] == 'b' && input[1] == '3' && board[1][2] == ' ') {
		board[1][2] = move; 
		print(board); 
		checkWin(board);
	      	counter++; 
	}

	else if(input[0] == 'c' && input[1] == '1' && board[2][0] == ' ') {
		board[2][0] = move; 
		print(board); 
		checkWin(board);
	      	counter++; 
	}	
    

        if (checkWin(board) == 1) {
            cout << move << " Wins!" << endl;
            char yesno; 
            cout << "Would you like to play again?" << endl;
            cout << "Enter y for yes or n for no: "; 
            cin >> yesno; 
            if (yesno == 'y') {
                main();
            }
            else if(yesno == 'n') {
                stillplay = false; 
            }
            
        }
        else if(checkWin(board) == 0) {
            cout << "It's a Tie!" << endl;
             char yesno; 
            cout << "Would you like to play again?" << endl;
            cout << "Enter y for yes or n for no: "; 
            cin >> yesno; 
             if (yesno == 'y') {
                main();
            }
             else if(yesno == 'n') {
                stillplay = false;  
          }
       }
     }
  }
