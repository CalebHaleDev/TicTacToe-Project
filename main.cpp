#include <iostream>
#include <string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

//function signatures, a list of functions which exist that makes placeholders for later defining
void checkWinRow(int checkRow);
void checkWinColumn(int checkColumn);
void checkWinDiagonals();
void printBoard();
void printScreen();
void checkWins();
void changeTurn();
static char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char winner = ' ';
char turn = 'X';
string selection;

int main() {
    
    while(winner==' '){
        cout << endl;
        printScreen();
        cout << endl;
        cout << "type two digits to select a square. 1-3 column then 1-3 row (i.e. 21 for the top middle): ";
        cin >> selection;
        board[(int)selection[0]-49][(int)selection[1]-49] = turn;       //place X or O
        //cout << "You have selected " << (int)selection[0]-49 << " and " << (int)selection[1]-49 << endl;  //for troubleshooting
        changeTurn();
        checkWins();
    }
    system("pause");   
    return 0;
}


void printScreen(){
    if (winner=='X'|| winner=='O')
        cout << "The winner is " << winner << endl;
    else
        cout << "It is " << turn << "'s turn" << endl;
    
    printBoard();
}

void printBoard(){
    cout << endl;
    cout << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << endl;
    cout << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << endl;
    cout << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << endl;
    cout << endl;
    return;
}

void changeTurn(){
    if(turn=='X')
        turn = 'O';
    else
        turn = 'X';
}

void checkWins(){
    checkWinRow(0);
    checkWinRow(1);
    checkWinRow(2);
    checkWinColumn(0);
    checkWinColumn(1);
    checkWinColumn(2);
    checkWinDiagonals();
}

void checkWinRow(int checkRow){
    if (board[0][checkRow]==board[1][checkRow] && board[1][checkRow]==board[2][checkRow])
        winner = board[0][checkRow];
    return;
}

void checkWinColumn(int checkColumn){
    if (board[checkColumn][0]==board[checkColumn][1] && board[checkColumn][1]==board[checkColumn][2])
        winner = board[checkColumn][0];
    return;
}

void checkWinDiagonals(){
    if ((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[2][0]==board[1][1] && board[1][1]==board[0][2]))
        winner = board[1][1];
    return;
}


