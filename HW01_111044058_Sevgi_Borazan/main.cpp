/* 
 * File:   main.cpp
 * Author: sevgiborazan
 *
 * Created on 04 Ekim 2015 Pazar, 13:00
 */

/********************************************************************************/
/* 				 Sevgi BORAZAN 111044058                        */
/*                                                                              */
/*                                  Game of Reversi                             */
/*                                                                              */
/********************************************************************************/

//Libraries
#include <iostream>
#include <iomanip> // for output formating
#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;

// Oyunun oynanacagi board'u temsil eden array
char **realBoard;

//Oyun hakkinda bilgi veren, oyunun nasil oynanacagini anlatan giris fonksiyonu
void usage(void);

///////////////////////////////////////////////////////////////////////////////


//Kullanicidan alinmis olan board size'in 4-20 arasinda olup olmamasinin kontrol
// eder. Eger kosullari sagliyor ise true, saglamiyor ise false return eder   

bool checkBoardSize(int size);

///////////////////////////////////////////////////////////////////////////////


//Kullanicidan board size'i ister ve kullanicidan aldigi degeri return eder    

int getBoardSize(void);


///////////////////////////////////////////////////////////////////////////////


//Arguman olarak gelen size'a gore 2D array icin hafizadan yer alir

void mallocBoard(int);


///////////////////////////////////////////////////////////////////////////////


//Arguman olarak gelen size'a gore 2D array icin alinan yerleri free eder

void freeBoard(int);

///////////////////////////////////////////////////////////////////////////////


//Arguman olarak gelen size'a gore board'u initialize eder. ilk konumlar atanir

void initializeBoard(int size, char **board);


///////////////////////////////////////////////////////////////////////////////


//Kullanidan yapmak istedigi hamleyi alir ve kendi icinde parse eder.
//x ve y koordinatlari belirlenir, yanlis deger girilmis ise hamle tekrar istenir.

void getPlayerMove(int size, int* x, int* y);


///////////////////////////////////////////////////////////////////////////////


//Arguman olarak gelen koordinatlara gore gerekli kontrol yapilarak board
// uzerindeki taslar ters cevrilir. Eger board uzerinde reverse yapildiysa
// true, yapilmadiysa false return eder.

bool reverseButtons(int x, int y, char** board, int size, char player);


///////////////////////////////////////////////////////////////////////////////

// Arguman olarak gelen board'u consolda gosterir.

void showGameonScreen(int size, char **board);


///////////////////////////////////////////////////////////////////////////////

//Oyun tamamlandiktan sonra score'u ekrana basar.

void showResultonScreen(int size, char** board);



///////////////////////////////////////////////////////////////////////////////

//Board uzerinde bos olan hücre var ise false,yoksa true return eder.

bool isBoardFilled(char **board, int size);



///////////////////////////////////////////////////////////////////////////////


bool computerMove(char **board, int size, int*x, int*y);

int main() {

    int currentY = 0;
    int currentX = 0;
    char player = 'O';

    usage();

    int boardSize = getBoardSize();

    mallocBoard(boardSize);

    initializeBoard(boardSize, realBoard);

    showGameonScreen(boardSize, realBoard);
    //showResultonScreen(boardSize ,realBoard);


    while (1) {

        if (player == 'X') {

            if (computerMove(realBoard, boardSize, &currentX, &currentY)) {
                if (reverseButtons(currentY - 1, currentX - 1, realBoard, boardSize, player)) {
                    showGameonScreen(boardSize, realBoard);
                    cout << "Computer played (" << currentY << "," << static_cast<char> ('a' + currentX - 1) << ")" << endl << endl;
                    player = 'O';
                }

            } else {
                if (isBoardFilled(realBoard, boardSize)) {
                    cout << "The board is filled. There is no move." << endl;
                    showResultonScreen(boardSize, realBoard);

                    freeBoard(boardSize);
                    return 0;
                } else{
                    cout << "Computer has no legal move, player turn." << endl;
                    player = 'O';
                }
            }

        } else {

        	if (isBoardFilled(realBoard, boardSize)) {
                    cout << "The board is filled. There is no move." << endl;
                    showResultonScreen(boardSize, realBoard);

                    freeBoard(boardSize);
                    return 0;
            }
            
            do {
                getPlayerMove(boardSize, &currentX, &currentY);

            } while (currentX > boardSize || currentY > boardSize || currentX <= 0 || currentY <= 0);

            if (reverseButtons(currentY - 1, currentX - 1, realBoard, boardSize, player)) {

                showGameonScreen(boardSize, realBoard);

                cout << "Player played " << " (" << currentY << "," << static_cast<char> ('a' + currentX - 1) << ")" << endl << endl;

                player = 'X';

            } else {
                if (isBoardFilled(realBoard, boardSize)) {
                    cout << "The board is filled. There is no move." << endl;
                    showResultonScreen(boardSize, realBoard);

                    freeBoard(boardSize);
                    return 0;
                }
                else
                    player = 'X';          
            }

        }
    }

    freeBoard(boardSize);

    return 0;

}

void usage(void) {

    cout << endl << endl;
    cout << "				The Classical Game Reversi" << endl;
    cout << " 			The Game has two players, computer and you !" << endl;
    cout << "	     The Computer is  represents by 'X'and the Player is represents by 'O' " << endl;
    cout << "	            	      The Game is starting with YOU !!" << endl << endl << endl << endl;
}

bool checkBoardSize(int size) {

    if (size < 4 || size > 20 || (size % 2 == 1))
        return false;
    else
        return true;
}

int getBoardSize(void) {

    int size;

    cout << "Please enter the board size in the range [4 ,20]" << endl;
    cin>> size;

    while (checkBoardSize(size) == false) {

        cerr << "Invalid board size, enter again !" << endl;
        cin>> size;
    }

    return size;
}

void mallocBoard(int size) {


    realBoard = (char **) malloc(sizeof (char*) * size);

    for (int i = 0; i < size; ++i) {

        realBoard[i] = (char *) malloc(sizeof (char) *(size + 1)); // \0 icin size+1 yer aldik
    }

}

void freeBoard(int size) {

    for (int i = 0; i < size; ++i) {

        free(realBoard[i]);
    }

    free(realBoard);

}

void initializeBoard(int size, char **board) {

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            if (i == (size / 2 - 1) && j == (size / 2 - 1))
                board[i][j] = 'X';
            else if (i == (size / 2 - 1) && j == (size / 2))
                board[i][j] = 'O';
            else if (i == (size / 2) && j == (size / 2 - 1))
                board[i][j] = 'O';
            else if (i == (size / 2) && j == (size / 2))
                board[i][j] = 'X';
            else
                board[i][j] = '.';
        }
    }
}

void showGameonScreen(int size, char **board) {

    char ch = 'a';

    cout << "  ";

    for (int i = 0; i < size; ++i)
        cout << " " << ch++;

    cout << endl;

    for (int i = 0; i < size; ++i) {

        cout << setw(2) << i + 1 << " ";

        for (int j = 0; j < size; ++j)
            cout << board[i][j] << " ";


        cout << endl;
    }

    cout << endl << endl;
}

void getPlayerMove(int size, int* x, int* y) {

    char move[4]; // if board size>9 need 4 characters

    char coorY[3];

    char chX;
    //bu kontrol ile koseler oynanamiyor

    do {
        cout << "Enter your move" << endl;
        cin>> move;
        // move stringi parse edilerek x ve y degerleri elde edilir
        if (size < 9) {

            strncpy(coorY, move, 1);

            *y = atoi(coorY);
            chX = move[1];
        } else {

            strncpy(coorY, move, 2);
            *y = atoi(coorY);

            if (*y > 9)
                chX = move[2];
            else
                chX = move[1];

        }


    } while (!(((chX >= 'a' && chX <= 't') || (chX >= 'A' && chX <= 'T')) && (*y <= size || *y >= 4)));

    // elde edilen karakterden koordinat degeri bulunur
    if (chX == 'A' || chX == 'a')
        *x = 1;
    else if (chX == 'B' || chX == 'b')
        *x = 2;
    else if (chX == 'C' || chX == 'c')
        *x = 3;
    else if (chX == 'D' || chX == 'd')
        *x = 4;
    else if (chX == 'E' || chX == 'e')
        *x = 5;
    else if (chX == 'F' || chX == 'f')
        *x = 6;
    else if (chX == 'G' || chX == 'g')
        *x = 7;
    else if (chX == 'H' || chX == 'h')
        *x = 8;
    else if (chX == 'I' || chX == 'i')
        *x = 9;
    else if (chX == 'J' || chX == 'j')
        *x = 10;
    else if (chX == 'K' || chX == 'k')
        *x = 11;
    else if (chX == 'L' || chX == 'l')
        *x = 12;
    else if (chX == 'M' || chX == 'm')
        *x = 13;
    else if (chX == 'N' || chX == 'n')
        *x = 14;
    else if (chX == 'O' || chX == 'o')
        *x = 15;
    else if (chX == 'P' || chX == 'p')
        *x = 16;
    else if (chX == 'Q' || chX == 'q')
        *x = 17;
    else if (chX == 'R' || chX == 'r')
        *x = 18;
    else if (chX == 'S' || chX == 's')
        *x = 19;
    else if (chX == 'T' || chX == 't')
        *x = 20;

}

void showResultonScreen(int size, char** board) {

    int playerScore = 0, computerScore = 0;

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            if (board[i][j] == 'X')
                computerScore += 1;

            else if (board[i][j] == 'O')
                playerScore += 1;

        }
    }

    showGameonScreen(size, board);

    if (computerScore > playerScore) {

        cout << "Computer:" << computerScore << "\tPlayer:" << playerScore << endl << endl;
        cout << "Winner is Computer :)" << endl << endl;
    }
    else if (computerScore < playerScore) {

        cout << "Computer:" << computerScore << "\t\t\tPlayer:" << playerScore << endl << endl;
        cout << "Winner is you Player." << endl << endl;
    }
    else {

        cout << "Computer:" << computerScore << "\t\t\tPlayer:" << playerScore << endl << endl;
        cout << "The score is equal. Thank you for playing." << endl << endl;
    }

}

bool reverseButtons(int x, int y, char** board, int size, char player) {

    int i = 0, j = 0;

    bool flag = false;

    int count = 0;

    if (board[x][y] != '.') {
        return false;
    }


    if (y > 1) {

        for (j = y - 1; j >= 0 && board[x][j] != player; --j) {

            count++;
            if (board[x][j] == '.' || (j-1 == -1) ){
                count = 0;
                break;
            }
        }

        for (j = y - 1; j >= 0 && count > 0; j--, count--) {
            board[x][j] = player;
            flag = true;

        }
    }

    count = 0;

    //south
    if (y < size - 2) {

        for (j = y + 1; j < size && board[x][j] != player; ++j) {

            count++;
            if (board[x][j] == '.' ||(j+1==size) ) {
                count = 0;
                break;
            }
        }

        for (j = y + 1; j < size && count > 0; j++, count--) {
            board[x][j] = player;
            flag = true;
        }
    }

    count = 0;

    //west
    if (x > 1) {

        for (i = x - 1; i >= 0 && board[i][y] != player; --i) {

            count++;
            if (board[i][y] == '.' ||(i-1 == -1)) {
                count = 0;
                break;
            }
        }
        for (i = x - 1; i >= 0 && count > 0; i--, count--) {
            board[i][y] = player;
            flag = true;
        }
    }

    count = 0;
    //east
    if (x < size - 2) {

        for (i = x + 1; i < size && board[i][y] != player; ++i) {
            count++;
            if (board[i][y] == '.' || (i+1 ==size)) {
                count = 0;
                break;
            }
        }

        for (i = x + 1; i < size && count > 0; i++, count--) {
            board[i][y] = player;
            flag = true;
        }
    }

    count = 0;

    //north-west
    if (x > 1 && y > 1) {
        for (i = x - 1, j = y - 1; i >= 0 && j >= 0 && board[i][j] != player; --i, --j) {
            count++;
            if (board[i][j] == '.' ||( i-1 == -1) ||( j-1 == -1)) {
                count = 0;
                break;
            }
        }

        for (i = x - 1, j = y - 1; i >= 0 && j >= 0 && count > 0; --i, --j, count--) {
            board[i][j] = player;
            flag = true;

        }
    }

    count = 0;

    //north-east
    if (x < size - 2 && y > 1) {

        for (i = x + 1, j = y - 1; i < size && j >= 0 && board[i][j] != player; ++i, --j) {

            count++;
            if (board[i][j] == '.' ||( i+1 == size) ||( j-1 == -1)) {
                count = 0;
                break;
            }
        }

        for (i = x + 1, j = y - 1; i < size && j >= 0 && count > 0; ++i, --j, count--) {
            board[i][j] = player;
            flag = true;
        }
    }

    count = 0;

    //south-west
    if (x > 1 && y < size - 2) {

        for (i = x - 1, j = y + 1; i >= 0 && j < size && board[i][j] != player; --i, ++j) {

            count++;
            if (board[i][j] == '.' ||( i-1 == -1) ||( j+1 == size)) {
                count = 0;
                break;
            }
        }
        for (i = x - 1, j = y + 1; i >= 0 && j < size && count > 0; --i, ++j, count--) {
            board[i][j] = player;
            flag = true;
        }

    }

    count = 0;

    //south-east
    if (x < size - 2 && y < size - 2) {

        for (i = x + 1, j = y + 1; i < size && j < size && board[i][j] != player; ++i, ++j) {

            count++;
            if (board[i][j] == '.' ||( i+1 == size) ||( j+1 == size)) {
                count = 0;
                break;
            }
        }
        for (i = x + 1, j = y + 1; i < size && j < size && count > 0; ++i, ++j, count--) {
            board[i][j] = player;
            flag = true;
        }

    }

    if (flag) {
        board[x][y] = player;
        return true;

    } else {
        if (player == 'O')
            cout << "Illegal Move" << endl << endl;
        return false;
    }
}

bool isBoardFilled(char **board, int size) {

    for (int i = 0; i < size; ++i) {

        for (int j = 0; i < size; ++i) {

            if (board[i][j] == '.') {
                return false;
            }
        }
    }

    return true;
}

bool computerMove(char **board, int size, int*x, int*y) {

    char **tempBoard;
    int i, j;
    bool flag = false;

    tempBoard = (char **) malloc((sizeof (char*) * size));
    for (i = 0; i < size; ++i)
        tempBoard[i] = (char*) malloc((sizeof (char) * (size + 1)));

    //copy real board to temporary board
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size + 1; ++j)
            tempBoard[i][j] = board[i][j];
    }


    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j)
            if (reverseButtons(j, i, tempBoard, size, 'X')) {

                *x = i + 1;
                *y = j + 1;
                flag = true;
                //cout<< "Computer played ("<< static_cast<char> ('a'+i)<<","<<j<<")"<<endl;

                for (i = 0; i < size; ++i)
                    free(tempBoard[i]);
                free(tempBoard);

                return flag;
            }
    }


    for (i = 0; i < size; ++i)
        free(tempBoard[i]);
    free(tempBoard);

    return flag;
}
