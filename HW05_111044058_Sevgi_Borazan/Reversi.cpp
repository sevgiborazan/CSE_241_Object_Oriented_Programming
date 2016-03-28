
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include "Reversi.h"
#include <sstream>

using namespace std;

//initialization of static data member
int Reversi::numOfAliveCell = 0;

////////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                                  //
////////////////////////////////////////////////////////////////////////////////

//GameCells'leri default olarak 8x8 lik bir reversi oyunu olarak doldurur.

Reversi::Reversi() {

    row = 8;
    col = 8;

    //vector size'i belirleme
    gameCells.resize(row);

    gameCells[row / 2 - 1].push_back(Cell(col / 2 - 1, row / 2 - 1, 'X'));
    gameCells[row / 2 - 1].push_back(Cell(col / 2, row / 2 - 1, 'O'));
    gameCells[row / 2].push_back(Cell(col / 2 - 1, row / 2, 'O'));
    gameCells[row / 2].push_back(Cell(col / 2, row / 2, 'X'));

    numOfAliveCell += 4; //yasayan obje sayisi arttirildi
    
    //playedGames.resize( row *col);
    //playedGames.push_back(*this);
}

////////////////////////////////////////////////////////////////////////////////

//row ve colon sayisi girilen Reversi objesi olusturan constructor

Reversi::Reversi(const int & newY, const int & newX) {

    row = newY;
    col = newX;

    //vector size'i belirleme
    gameCells.resize(row);

    if ((getRow() / 2 - 1) >= 0 && (getCol() / 2 - 1) >= 0) {
        gameCells[getRow() / 2 - 1].push_back(
                Cell(getCol() / 2 - 1, getRow() / 2 - 1, 'X'));
        numOfAliveCell++;
    }

    if ((row / 2 - 1) >= 0 && (col / 2) >= 0) {
        gameCells[getRow() / 2 - 1].push_back(
                Cell(getCol() / 2, getRow() / 2 - 1, 'O'));
        numOfAliveCell++;
    }

    if ((row / 2) >= 0 && (col / 2 - 1) >= 0) {
        gameCells[getRow() / 2].push_back(
                Cell(getCol() / 2 - 1, getRow() / 2, 'O'));
        numOfAliveCell++;
    }

    if ((row / 2) >= 0 && (col / 2) >= 0) {

        gameCells[getRow() / 2].push_back(
                Cell(getCol() / 2, getRow() / 2, 'X'));
        numOfAliveCell++;
    }

   // playedGames.resize(row*col);
    //playedGames.push_back(*this);

}

////////////////////////////////////////////////////////////////////////////////

Reversi::Reversi(const char* fname) {

    readFromFile(fname);
    //playedGames.resize(row*col);
    //playedGames.push_back(*this);

}

////////////////////////////////////////////////////////////////////////////////

int Reversi::getNumOfAliveCell() {
    return numOfAliveCell;
}

////////////////////////////////////////////////////////////////////////////////

//other member functions

void Reversi::write2File(const char * fname) const {

    ofstream out;
    out.open(fname);

    for (int i = 0; i < getRow(); ++i) {
        for (int j = 0; j < getCol(); ++j) {

            bool flag = false;

            for (int k = 0; k < gameCells[i].size(); ++k) {

                if (gameCells[i].at(k).getX() == j
                        && gameCells[i].at(k).getY() == i) {
                    out << gameCells[i].at(k).getFeature();
                    numOfAliveCell--; //eger yazip tekrar okursam 2 kat olacak
                    flag = true;
                }
            }

            if (flag != true)
                out << '.';

        }
        if (i != row - 1)
            out << '\n';
    }

    out.close();
}

////////////////////////////////////////////////////////////////////////////////

void Reversi::readFromFile(const char * fname) {

    ifstream in;

    in.open(fname);
    char ch;

    row = 0;
    col = 0;
    //create current row
    gameCells.push_back(vector<Cell>());

    while ((ch = in.get()) != EOF) {

        if (ch != '\n' && ch != ' ') {
            if (ch != '.') {
                //push the cell into the current row
                gameCells.back().push_back(Cell(col, row, ch));
                numOfAliveCell++;
            }

            col++;
        } else if (ch == '\n') {
            //add new current row
            gameCells.push_back(vector<Cell>());
            row++;
            col = 0;
        }
    }
    row++;

    in.close();
}

////////////////////////////////////////////////////////////////////////////////

void Reversi::displayBoardOnScreen() const {

    cout << setw(3) << "  ";
    if (row < 26) {
        for (int i = 0; i < getCol(); ++i) {
            cout << setw(2) << " " << static_cast<char> ('A' + i);
        }
        cout << setw(3) << endl;

    } else {
        for (int i = 0; i < 26; ++i) {
            cout << setw(2) << " " << static_cast<char> ('A' + i);
        }
        for (int i = 0; i < getCol() - 26; ++i) {
            cout << setw(2) << 'A' << static_cast<char> ('A' + i);
        }
        //cout<<setw(3)<<endl;

        cout << setw(3) << endl;
    }

    for (int i = 0; i < getRow(); ++i) {
        //get current row then check cells and print
        vector<Cell> currentRow = gameCells.at(i);
        cout << setw(3) << i + 1 << " ";
        for (int j = 0; j < getCol(); ++j) {
            bool flag = false;

            for (int k = 0; k < currentRow.size(); ++k)
                if (currentRow.at(k).getX() == j
                        && currentRow.at(k).getY() == i) {
                    cout << setw(2) << currentRow.at(k).getFeature() << " ";
                    flag = true;
                }
            if (!flag)
                cout << setw(3) << ". ";
        }
        cout << endl;
    }

}

////////////////////////////////////////////////////////////////////////////////
//play for a single step with no parameter for computer

void Reversi::play() {

    Cell move;
    if (computerMove(&move)){
        reverseButtons(move);
        
        playedGames.push_back(*this);
       
        move.setY(move.getY() + 1);
        cout<<"Computer played to";
        move.output();
        cout<<endl;
        displayBoardOnScreen();
        
    }
    else
        cout << "There is no legal move for computer." << endl << "The turn is yours Player!" << endl;
}

////////////////////////////////////////////////////////////////////////////////

void Reversi::play(Cell & point) {
    reverseButtons(point);
    
    playedGames.push_back(*this);

}

////////////////////////////////////////////////////////////////////////////////

bool Reversi::isFinish() const {
    Cell cell;

    if (!computerMove(&cell) && !canPlayerMove())
        return true;

    return false;
}

////////////////////////////////////////////////////////////////////////////////

void Reversi::playGame() {
    
    if(isFinish()){
        cout << "game over!" << endl;
        return;
    }

    if (canPlayerMove()) {

        Cell point;

        while (1) {

            point.input();
            point.set(point.getY(), point.getX() - 1);

            if (isLegalMove(point)) {
                play(point);
                displayBoardOnScreen();
                break;
            }

        }
    } else {

        cout << "Player has no legal move, the Turn is changed." << endl;
    }
    play();

}

////////////////////////////////////////////////////////////////////////////////

bool Reversi::compare(const Reversi &other) const {
    
    int otherXC=0,otherOC=0, thisXC=0,thisOC=0;
    
    memberCount( &thisXC, &thisOC);
    other.memberCount( &otherXC, &otherOC);
    
    if(thisOC > otherOC)
        return true;
    
    return false;    
    
}
////////////////////////////////////////////////////////////////////////////////

void Reversi::reverseButtons(Cell & cell) {
    const Cell *target;
    gameCells.at(cell.getY()).push_back(cell);
    numOfAliveCell++;

    for (int j = -1; j <= 1; ++j) {
        for (int i = -1; i <= 1; ++i) {
            if (isMember(cell.getY() + j, cell.getX() + i) && !isSamePlayer(cell.getY() + j, cell.getX() + i, cell.getFeature())) {
                if (i != 0 && j != 0) {
                    //cross
                    target = findMatching(cell, i, j);
                    if (target != NULL)
                        reverse(cell, *target);
                } else if (i == 0 && j != 0) {
                    //x axis
                    target = findMatching(cell, i, j);
                    if (target != NULL)
                        reverse(cell, *target);
                } else if (i != 0 && j == 0) {
                    //y axis
                    target = findMatching(cell, i, j);
                    if (target != NULL)
                        reverse(cell, *target);
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

const Cell *Reversi::findMatching(const Cell &cell, int di, int dj) const {
    for (int c = 1;
            (cell.getX() + di * c) >= 0 && (cell.getX() + di * c) != row
            && (cell.getY() + dj * c) >= 0
            && (cell.getY() + dj * c) != row; ++c) {

        if (!isMember(cell.getY() + dj * c,
                cell.getX() + di * c))
            return NULL;
        else if (isSamePlayer(cell.getY() + dj * c,
                cell.getX() + di * c, cell.getFeature()))
            return &returnCell(cell.getY() + dj * c,
                cell.getX() + di * c);
    }

    return NULL;
}

////////////////////////////////////////////////////////////////////////////////

void Reversi::reverse(const Cell &start, const Cell &end) {
    int cX = start.getX() - end.getX(), cY = start.getY() - end.getY();
    int d = start.getX() - end.getX();

    if (d == 0)
        d = start.getY() - end.getY();

    if (d < 0)
        d *= -1;

    if (cX < 0)
        cX = -1;
    else if (cX > 0)
        cX = 1;

    if (cY < 0)
        cY = -1;
    else if (cY > 0)
        cY = 1;

    for (int c = 1; c < d; ++c) {
        reverse(returnCell(end.getY() + c * cY, end.getX() + c * cX));
    }
}

////////////////////////////////////////////////////////////////////////////////
//Kendisine gelen cell player ise computer, computer ise player olarak reverse eder
void Reversi::reverse(Cell &cell) {

    if (cell.getFeature() == COMPUTER)
        cell.set(cell.getX(), cell.getY(), PLAYER);
    else if (cell.getFeature() == PLAYER)
        cell.set(cell.getX(), cell.getY(), COMPUTER);
}

////////////////////////////////////////////////////////////////////////////////
//check the empty cells if there is return true
bool Reversi::isBoardFilled() const {

    int elem_count = 0;

    int size = getRow();

    for (int i = 0; i < size; ++i) {
        elem_count += gameCells[i].size();
    }
    return (getRow() * getCol() == elem_count);
}

////////////////////////////////////////////////////////////////////////////////
//if computer can play return x and y coordinates and true
bool Reversi::computerMove(Cell *cell) const {
    if (!isBoardFilled()) {
        
        for (int i = 0; i < gameCells.size(); ++i) {
            for (int j = 0; j < getCol(); ++j) {
                if (isLegalMove(Cell(j, i, COMPUTER))) {
                    cell->setX(j);
                    cell->setY(i);
                    cell->set(COMPUTER);
                    return true;
                }
            }
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
//player'in hamlesi kaldi mi 
bool Reversi::canPlayerMove()const {

    if ( !isBoardFilled() ) {
        for (int i = 0; i < gameCells.size(); ++i) {
            for (int j = 0; j < getCol(); ++j) {
                if (isLegalMove(Cell(j, i, PLAYER)))
                    return true;
            }
        }
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////
//player'in girdigi hamle legal mi degil mi ?
//cell in feature u hamle yapan kisi
bool Reversi::isLegalMove(const Cell &cell) const {

    if (isMember(cell.getY(), cell.getX()))
        return false;

    for (int j = -1; j <= 1; ++j) {
        for (int i = -1; i <= 1; ++i) {
            if (isMember(cell.getY() + j, cell.getX() + i) && !isSamePlayer(cell.getY() + j, cell.getX() + i, cell.getFeature())) {
                if (i != 0 && j != 0) {
                    //cross
                    if (findMatching(cell, i, j) != NULL)
                        return true;
                } else if (i == 0 && j != 0) {
                    //x axis
                    if (findMatching(cell, i, j) != NULL)
                        return true;
                } else if (i != 0 && j == 0) {
                    //y axis
                    if (findMatching(cell, i, j) != NULL)
                        return true;
                }
            }
        }
    }

    return false;
}

//parametre olarak gelen koordinatlara sahip gameCell de bir cell objesi
//var mi yok mu check eder.
bool Reversi::isMember(const int &r, const int &c) const {

    const Cell &cell = returnCell(r, c);

    if (cell.getX() == -1)
        return false;

    return true;
}

////////////////////////////////////////////////////////////////////////////////

bool Reversi::isSamePlayer(const int &r, const int &c, const char &p) const {

    const Cell &cell = returnCell(r, c);

    if (cell.getX() == -1)
        return false;

    if (cell.getFeature() == p)
        return true;

    return false;
}

////////////////////////////////////////////////////////////////////////////////
//degisiklik yapilacak olan gameCell de ki cell objesini return eder
Cell &Reversi::returnCell(const int &r, const int& c) {
    static Cell cell = Cell(-1);
    int size = gameCells[r].size();
    for (int i = 0; i < size; ++i) {
        if (gameCells[r][i].getX() == c)
            return gameCells[r][i];
    }

    return cell;
}

////////////////////////////////////////////////////////////////////////////////
const Cell &Reversi::returnCell(const int &r, const int& c) const {
    static Cell cell = Cell(-1);
    
    if(r == -1 || c == -1)
        return cell;
    int size = gameCells[r].size();
    for (int i = 0; i < size; ++i) {
        if (gameCells[r][i].getX() == c)
            return gameCells[r][i];
    }

    return cell;
}

////////////////////////////////////////////////////////////////////////////////
void Reversi::memberCount(int *XCount, int *YCount)const{
    
    int xC =0, yC = 0;
    for(int i= 0; i<gameCells.size(); ++i){
        for(int j = 0; j< gameCells.at(i).size() ; ++j){
            if(gameCells.at(i).at(j).getFeature() == COMPUTER)
                ++xC;
            ++yC;
        }
    }
    *XCount = xC;
    *YCount = xC;
}

////////////////////////////////////////////////////////////////////////////////
void Reversi::displayScore()const{
    int XC,OC;
    memberCount(&XC,&OC);
    cout<<"COMPUTER:"<<XC<<"    PLAYER:"<<OC<<endl;
    if(XC > OC)
        cout<<"The winner is COMPUTER."<<endl;
    else if(XC == OC)
        cout<<"The winner is PLAYER."<<endl;
    else
        cout<<"There is a TIE."<<endl;
    
}

////////////////////////////////////////////////////////////////////////////////

int Reversi::char2int(const string &s){
    int sLenght = s.length();
    int returnVal = 0;

    if (sLenght == 1) {
        return s[0] - 97;
    } else {
        for (int i = 0; i < sLenght; ++i) {
            returnVal += ((pow(26, sLenght - 1 - i)*(s[i] - 96)));
        }
    }
    return returnVal - 1;
}

////////////////////////////////////////////////////////////////////////////////

Reversi Reversi::operator ++(void){
    
    this->play();
    return *this;
}

////////////////////////////////////////////////////////////////////////////////
Reversi Reversi::operator ++(const int ignoreMe){
    
    Reversi temp;
    temp = *this;
    this->play();
    
    return temp;
}	

////////////////////////////////////////////////////////////////////////////////

Reversi Reversi::operator --(void){
    
    if(playedGames.size()>=1)
        playedGames.pop_back();
    
    gameCells =  playedGames[playedGames.size() -1].gameCells;
    
    playedGames[playedGames.size() -1].displayBoardOnScreen();
    
    return *this;
}

////////////////////////////////////////////////////////////////////////////////

Reversi Reversi::operator --(const int ignoreMe){

    Reversi temp = *this;
    
    if(playedGames.size()>=1)
        playedGames.pop_back();
    
    gameCells =  playedGames[playedGames.size() -1].gameCells;
    
    playedGames[playedGames.size() -1].displayBoardOnScreen();
    
    return temp;
}

////////////////////////////////////////////////////////////////////////////////

void Reversi::operator +=( Cell &other){

    play(other);
    play();
}

////////////////////////////////////////////////////////////////////////////////
Cell Reversi::operator ()(int r, string c){
    
    if(gameCells.size() == 0)
        return Cell(-1000,-1000);
    
    int column = char2int(c);
    
    for(int i= 0; i< gameCells[r-1].size(); ++i){
        if( gameCells[r-1][i]. getX() == column)
            return gameCells[r-1][i];
    }
    return Cell(-1000,-1000);
}

////////////////////////////////////////////////////////////////////////////////

Cell Reversi::operator [](string s){

    if( gameCells.size() == 0 )
        return Cell(-1000,-1000);
    
    string s1= s.substr(0,1);
    string s2 =s.substr(1);
    cout << char2int(s1.data()) + 'a' - '0' << ", " << char2int(s2.data())+1 <<endl;
    
    for(int i= 0; i<gameCells.size(); ++i){
        for(int j =0; j< gameCells[i].size(); ++j){
            cout << gameCells[i][j]<<endl;
            if(gameCells[i][j].getX() == (char2int(s1.data()) + 'a' - '0' -1) && gameCells[i][j].getY() == (char2int(s2.data())))
                return gameCells[i][j];
        }
    }
    return Cell(-1000,-1000);
}

////////////////////////////////////////////////////////////////////////////////
//                          SEVGI BORAZAN 111044058                           //
////////////////////////////////////////////////////////////////////////////////