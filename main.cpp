#include <iostream>
#include <string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

//function signatures, a list of functions which exist that makes placeholders for later defining
char checkWinRow(int checkRow, char board[3][3]);
char checkWinColumn(int checkColumn, char board[3][3]);
char checkWinDiagonals(char board[3][3]);
void printBoard(char board[3][3]);
void printLargeBoard();
void printRow(int selectedBoard, int selectedRow);
void printScreen();
char checkWins(char board[3][3]);
void changeTurn();
void reset();
static char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
static char largeBoard[9][3][3] = {{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}},{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}};
static char pointBoard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int activeBoard;
char winner = ' ';
static char turn = 'X';
int turnsPassed = 0;
int gamemode;
int selection = 0;
char redo;
static int Xpoints = 0;
static int Ypoints = 0;


int main() {
    reset();

    cout << "type 2 for a standard game, 3 for 3d tic tac toe, or 0 for help: ";
    cin >> gamemode;
    if (gamemode == 0){     //help section
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
    else if (gamemode == 2){    //standard game
        while(winner==' '||(winner!='X'&&winner!='O')){
            cout << endl;
            printScreen();
            cout << endl;
            cout << "type a digit 1-9 to select a square: ";
            if (selection==0)
                cout << " (i.e. 2 for the top middle)";
            cin >> selection;
            if(selection==0)
                break;
            board[((selection-1)%3)][((int)((selection-1)/3))] = turn;       //place X or O
        changeTurn();
        winner = checkWins(board);
        }
        cout << "The winner is "+winner+'!'<<endl;
    }else if (gamemode == 3){       //3d game
        //3d version
        printLargeBoard();
        cout << endl << endl;
        cout << "select a board to begin in, using 1-9";
        cin >> activeBoard;
        activeBoard--;  //user-friendly 1-9 to index range 0-8

        while(turnsPassed<81/*&& there is room*/){  //continue with game until completion
            cout << endl;
            printScreen();
            cout << endl;
            selection = -1;
            while(selection==-1){     //take a turn
                cout << "type a digit 1-9 to select a valid square: ";
                cin >> selection;
                if(selection==0)        //exit code, stop game
                    break;
                if(largeBoard[activeBoard][((selection-1)%3)][((int)((selection-1)/3))]!=' '||selection>9)   //retry if invalid
                    selection = -1;     
            }
            if(selection==0)        //stop game early
                break;
            largeBoard[activeBoard][((selection-1)%3)][((int)((selection-1)/3))] = turn; //place X or O
            char result = checkWins(largeBoard[activeBoard]);     //check for a local win
                if(result!=' '&&pointBoard[(activeBoard-1)%3][(activeBoard-1)/3]==' '){      //if a new win is found, record it
                    pointBoard[(activeBoard-1)%3][(activeBoard-1)/3] = result;
                    cout << result << "has earned one point!";
                    }
            activeBoard = selection-1;    //select new board   
            changeTurn();
            turnsPassed++;   
            //Check to see if all spots are filled and end the game earlier
            //if(!(largeBoard[activeBoard][0]==' '||largeBoard[activeBoard][1]==' '||largeBoard[activeBoard][2]==' '||largeBoard[activeBoard][3]==' '||largeBoard[activeBoard][4]==' '||largeBoard[activeBoard][5]==' '||largeBoard[activeBoard][6]==' '||largeBoard[activeBoard][7]==' '||largeBoard[activeBoard][8]==' '))
            //        break;
            }
        //game completion, evaluate points
        
        //count game points
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                //char result = checkWins(largeBoard[3*j+i+1]);     //backup code, wins should already be recorded
                //pointBoard[i][j] = result;
                if (pointBoard[i][j]=='X')  //if manually checked result=='X'
                    Xpoints++;
                else
                    Ypoints++;
            }
        }
        //count 3-game points
        char result = checkWins(pointBoard);
        if (result=='X')
                    Xpoints++;
                else{
                    Ypoints++;
                }

        //proclaim winner
        if (Xpoints>Ypoints){
            winner = 'X';
        }else if (Ypoints>Xpoints){
            winner = 'Y';
        }else{
            cout << "It's a tie!";
            system("pause");
            return 0;
        }
        
    }else if (gamemode==1){     //test 3d point system
            while(turnsPassed<81){  //continue with game until completion
            selection = -1;
            while(selection==-1){     //take a turn
                selection = rand()%9+1;
                cout << "number: " << selection << endl;
                cout << "turns passed: "+turnsPassed << endl;
                if(largeBoard[activeBoard][((selection-1)%3)][((int)((selection-1)/3))]!=' '||selection>9)   //retry if invalid
                    selection = -1;     
            }
            largeBoard[activeBoard][((selection-1)%3)][((int)((selection-1)/3))] = turn; //place X or O
            char result = checkWins(largeBoard[activeBoard]);     //check for a local win
                if(result!=' '&&pointBoard[(activeBoard-1)%3][(activeBoard-1)/3]==' '){      //if a new win is found, record it
                    pointBoard[(activeBoard-1)%3][(activeBoard-1)/3] = result;
                    cout << result << "has earned one point!";
                    }
            activeBoard = selection-1;    //select new board   
            changeTurn();
            turnsPassed++;  
            //Check to see if all spots are filled and end the game earlier
            if(!(largeBoard[activeBoard][0][0]==' '||largeBoard[activeBoard][0][1]==' '||largeBoard[activeBoard][0][2]==' '||largeBoard[activeBoard][1][0]==' '||largeBoard[activeBoard][1][1]==' '||largeBoard[activeBoard][1][2]==' '||largeBoard[activeBoard][2][0]==' '||largeBoard[activeBoard][2][1]==' '||largeBoard[activeBoard][2][2]==' '))
                break; 
            }
        printScreen();
        cout<< "game completed" << endl;
        //game completion, evaluate points
        
        //count single-game points
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (pointBoard[i][j]=='X')
                    Xpoints++;
                else
                    Ypoints++;
            }
        }
        //count 3-game points
        char result = checkWins(pointBoard);
        if (result=='X')
                    Xpoints++;
                else{
                    Ypoints++;
                }

        //proclaim winner
        if (Xpoints>Ypoints){
            winner = 'X';
        }else if (Ypoints>Xpoints){
            winner = 'Y';
        }else{
            cout << "It's a tie!";
            system("pause");
            return 0;
        }
    }
    else{      //selection error
        cout << "please select a valid game mode"<< endl;
        main();
        return 0;
    }

    cout << "would you like to play again? (y/n)";      //restart option
    cin >> redo;
    if (redo == 'y'){
        reset();
        main();
    } 
    return 0;
}

void reset(){   //resets variables
    winner = ' ';
    turn = 'X';
    turnsPassed = 0;
    Xpoints = 0;
    Ypoints = 0;
    for(int i=1;i<10;i++){      //reset boards
        board[((i-1)%3)][((int)((i-1)/3))] = ' ';
        pointBoard[((i-1)%3)][((int)((i-1)/3))] = ' ';
        for(int j=1;j<10;j++)
            largeBoard[j][((i-1)%3)][((int)((i-1)/3))] = ' ';
    }
    return;
}; 

void printScreen(){     //prints the display each turn
    if(gamemode==2){
        if (winner=='X'|| winner=='O')
            cout << "The winner is " << winner << endl;
        else
            cout << "It is " << turn << "'s turn" << endl;

        printBoard(board);
    }else{
        printLargeBoard();
        cout << endl;
        if (winner=='X'|| winner=='O')
            cout << "The winner is " << winner << endl;
        else
            cout << "It is " << turn << "'s turn" << endl;

        cout << endl << "Active board: " << activeBoard+1 << endl;
        printBoard(largeBoard[activeBoard]);
    }   
}

void printBoard(char board[3][3]){      //prints the standard board
    cout << endl;
    cout << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << endl;
    cout << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << endl;
    cout << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << endl;
    cout << endl;
    return;
}

void printLargeBoard(){     //prints the large board
    for(int i=0;i<9;i++){
        if (i%3==0&&i!=0){
            cout << "           |           |           " << endl;
            cout << "------------------------------------" << endl;
            cout << "           |           |           " << endl;
        }
        cout << " "; printRow(3*(i/3), i%3); cout << " | "; printRow(3*(i/3)+1, i%3); cout << " | "; printRow(3*(i/3)+2, i%3); cout << endl;
        //cout << "printed from boards: " << 3*(i/3) << 3*(i/3)+1 << 3*(i/3)+2 << " and relative row " << i%3;  //for troubleshooting
    }
    return;
}

void printRow(int selectedBoard, int selectedRow){
    cout << largeBoard[selectedBoard][0][selectedRow] << " | " << largeBoard[selectedBoard][1][selectedRow] << " | " << largeBoard[selectedBoard][2][selectedRow];
    return;
}

void changeTurn(){      //changes... the turn... duh
    if(turn=='X')
        turn = 'O';
    else
        turn = 'X';
}

char checkWins(char board[3][3]){       //checks for a win condition
    char results[7] = {checkWinRow(0, board),checkWinRow(1, board),checkWinRow(2, board),checkWinColumn(0, board),checkWinColumn(1, board),checkWinColumn(2, board),checkWinDiagonals(board)};
    for(int i=0;i<8;i++)
        if (results[i]!=' ')        //found a win
            return results[i];
    return ' ';     //if no win found, return nothing
}

char checkWinRow(int checkRow, char board[3][3]){
    if (board[0][checkRow]==board[1][checkRow] && board[1][checkRow]==board[2][checkRow])
        return board[0][checkRow];
    return ' ';
}

char checkWinColumn(int checkColumn, char board[3][3]){
    if (board[checkColumn][0]==board[checkColumn][1] && board[checkColumn][1]==board[checkColumn][2])
        return board[checkColumn][0];
    return ' ';
}

char checkWinDiagonals(char board[3][3]){
    if ((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[2][0]==board[1][1] && board[1][1]==board[0][2]))
        return board[1][1];
    return ' ';
}
