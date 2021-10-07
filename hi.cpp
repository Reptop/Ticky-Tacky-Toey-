#include <iostream>
#include <cstring>
using namespace std; 

//print board function 
void displayBoard(char square[3][3]) {
    cout << "\nPlayer 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[0][0] << "  |  " << square[1][0] << "  |  " << square[2][0] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[0][1] << "  |  " << square[1][1] << "  |  " << square[2][1] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[0][2] << "  |  " << square[1][2] << "  |  " << square[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}   

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

int main() {  
    // var declarations 
    bool stillplay = true;
    int counter;
    char move; 
    char board[3][3] = {'1','4','7','2','5','8','3','6','9'};
    displayBoard(board); 
    cout << "Enter the number corresponding to the cell you want to place your piece on" << endl; 

    while (stillplay) {
    int a;  
    cout << "Input: ";
    cin >> a;

    //keeps track of turns based on even and odd numbers; counter gets iterated up each turn 
    if (counter % 2 == 0) 
        move = 'X';
    else 
        move = 'O'; 

    //switch statement; more efficient 
    switch(a) {
        case 1 :
        if (board[0][0] == '1') {
            counter++;
            board[0][0] = move;
            displayBoard(board);
            checkWin(board);
        }
        else {
            cout << "That spot is taken" << endl;
        }
        break; 
        
         case 2 :
        if (board[1][0] == '2') {
            counter++;
            board[1][0] = move;
            displayBoard(board);
            checkWin(board);

        }
        else {
            cout << "That spot is taken" << endl; 
        }
        break;

         case 3 :
        if (board[2][0] == '3') {
            counter++;
            board[2][0] = move;
            displayBoard(board);
            checkWin(board);
            
        }
        else {
            cout << "That spot is taken" << endl; 
        }
        break;

         case 4 :
        if (board[0][1] == '4') {
            counter++;
            board[0][1] = move;
            displayBoard(board);
            checkWin(board);

        }
        else {
            cout << "That spot is taken" << endl; 
        }
        break;

         case 5 :
        if (board[1][1] == '5') {
            counter++; 
            board[1][1] = move;
            displayBoard(board);
            checkWin(board);

        }
        else {
            cout << "That spot is taken" << endl; 
        }
        break;

         case 6 :
        if (board[2][1] == '6') {
            counter++; 
            board[2][1] = move;
            displayBoard(board);
            checkWin(board);
        }
        else {
            cout << "That spot is taken" << endl; 
        }
        break;

         case 7 :
        if (board[0][2] == '7') {
            counter++;
            board[0][2] = move;
            displayBoard(board);
            checkWin(board);
        }
        else {
            cout << "That spot is taken" << endl; 
        }
        break;

         case 8 :
        if (board[1][2] == '8') {
        counter++;
        board[1][2] = move;
        displayBoard(board);
        checkWin(board);
        }
        else {
            cout << "That spot is taken" << endl; 
        }
        break;

         case 9 :
        if (board[2][2] == '9') {
        counter++; 
        board[2][2] = move;
        displayBoard(board);
        checkWin(board);
        }
        else {
            cout << "That spot is taken" << endl; 
        }
        break;
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
