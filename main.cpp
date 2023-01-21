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
void reset();
static char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
static char largeBoard[9][3][3] = {{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}};
static char pointBoard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char winner = ' ';
static char turn = 'X';
int gamemode;
int selection = 0;
char redo;



int main() {
    reset();

    cout << "type 2 for a standard game, 3 for 3d tic tac toe, or 0 for help: ";
    cin >> gamemode;
    if (gamemode == 0){
        cout << endl << endl;
        cout << "This is the standard board, spots labelled with their input numbers:"<< endl;
        cout << endl;
        cout << 1 << " | " << 2 << " | " << 3 << endl;
        cout << 4 << " | " << 5 << " | " << 6 << endl;
        cout << 7 << " | " << 8 << " | " << 9 << endl;
        cout << endl;
        cout << "To play, type the number of the square you want to play in." << endl;
        cout << "You can quit at any time by entering 0" << endl;
        cout << "In the 3d version the spot where each player goes determines which board the next player plays in." << endl;
        cout << "So... you're playing nine games at the same time and you win by a point system." << endl;
        cout << "Each game you win is a point and each three-in-a-row win is a point." << endl << endl;
        cout << "When you're ready to head back to the menu, press a key." << endl;
        system("pause");
        main();
        return 0;
    }
    else if (gamemode == 2){
        while(winner==' '){
            cout << endl;
            printScreen();
            cout << endl;
            cout << "type a digit 1-9 to select a square: ";
            if (selection==0)
                cout << " (i.e. 2 for the top middle)";
            cin >> selection;
            if(selection==0)
                return 0;
            board[((selection-1)%3)][((int)((selection-1)/3))] = turn;       //place X or O
            //cout << "You have selected " << (selection%3) << " and " << ((int)((selection-1)/3)) << endl;  //for troubleshooting
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

void reset(){
    winner = ' ';
    turn = 'X';
    for(int i=1;i<10;i++){
        board[((i-1)%3)][((int)((i-1)/3))] = ' ';
        pointBoard[((i-1)%3)][((int)((i-1)/3))] = ' ';
        for(int j=1;j<10;j++)
            largeBoard[j][((i-1)%3)][((int)((i-1)/3))] = ' ';
    }
    return;
}; 


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


