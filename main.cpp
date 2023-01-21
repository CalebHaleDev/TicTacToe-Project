#include <iostream>
#include <string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

//function signatures, a list of functions which exist that makes placeholders for later defining
void checkWinRow(int checkRow, char board[3][3]);
void checkWinColumn(int checkColumn, char board[3][3]);
void checkWinDiagonals(char board[3][3]);
void printBoard();
void printLargeBoard();
void printScreen();
void checkWins(char board[3][3]);
void changeTurn();
static char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
//static char largeBoard[9][3][3] = {{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}};
char winner = ' ';
char turn = 'X';
int gamemode;
int selection;
char redo;

//system("pause");    //reminder that I could use this later if I want to

int main() {
    cout << "type 2 for a standard game and 3 for 3d tic tac toe: ";
    cin >> gamemode;
    if (gamemode == 2){
        while(winner==' '){
            cout << endl;
            printScreen();
            cout << endl;
            cout << "type a digit 1-9 to select a square (i.e. 2 for the top middle): ";
            cin >> selection;
            if(selection==0)
                return 0;
            board[((selection-1)%3)][((int)((selection-1)/3))] = turn;       //place X or O
            cout << "You have selected " << (selection%3) << " and " << ((int)((selection-1)/3)) << endl;  //for troubleshooting
        changeTurn();
        checkWins(board);
    }
    }else if (gamemode == 3){
        //3d version
    }else{
        cout << "please select a valid game mode"<< endl;
        main();
        return 0;
    }

    cout << "would you like to play again? (y/n)";
    cin >> redo;
    if (redo == 'y'){
        turn = 'X';
        main();
    } 
    return 0;
}


void printScreen(){
    if (winner=='X'|| winner=='O')
        cout << "The winner is " << winner << endl;
    else
        cout << "It is " << turn << "'s turn" << endl;
    
    if(gamemode==2)
        printBoard();
    else
        printLargeBoard();
}

void printBoard(){
    cout << endl;
    cout << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << endl;
    cout << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << endl;
    cout << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << endl;
    cout << endl;
    return;
}

void printLargeBoard(){
//code here
    return;
}

void changeTurn(){
    if(turn=='X')
        turn = 'O';
    else
        turn = 'X';
}

void checkWins(char board[3][3]){
    checkWinRow(0, board);
    checkWinRow(1, board);
    checkWinRow(2, board);
    checkWinColumn(0, board);
    checkWinColumn(1, board);
    checkWinColumn(2, board);
    checkWinDiagonals(board);
}

void checkWinRow(int checkRow, char board[3][3]){
    if (board[0][checkRow]==board[1][checkRow] && board[1][checkRow]==board[2][checkRow])
        winner = board[0][checkRow];
    return;
}

void checkWinColumn(int checkColumn, char board[3][3]){
    if (board[checkColumn][0]==board[checkColumn][1] && board[checkColumn][1]==board[checkColumn][2])
        winner = board[checkColumn][0];
    return;
}

void checkWinDiagonals(char board[3][3]){
    if ((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[2][0]==board[1][1] && board[1][1]==board[0][2]))
        winner = board[1][1];
    return;
}


