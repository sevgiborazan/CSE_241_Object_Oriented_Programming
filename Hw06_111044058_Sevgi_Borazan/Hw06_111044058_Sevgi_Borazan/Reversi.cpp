//This is the implementation file Reversi.cpp of the class Reversi.
//The interface for the class Reversi is in the header file Reversi.h.

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <sstream>
#include "Reversi.h"

using std::cout;
using std::cin;
using std::ostream;

namespace sevgiborazan{
    
    
    
    void testCallByValue( Reversi obj1, Reversi obj2){
        
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"----------------TESTING FOR CALL BY VALUE FUNCTION ----------------"<<endl;
        cout<<"-------------------------------------------------------------------"<<endl<<endl;

        cout<<"Test first parameter Reversi game object with a single playGame function."<<endl;
        obj1.displayBoardOnScreen();
        obj1.playGame();
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Test second parameter Reversi game object with a single playGame function."<<endl;
        obj2.displayBoardOnScreen();
        obj2.playGame();
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Testing for copy constructor using first game object."<<endl;
        Reversi game(obj1);
        game.displayBoardOnScreen();
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Testing for stream insertion operator for new game object."<<endl;
        cout<<game<<endl<<"Testing for stream insertion operator for fisrt parameter"<<endl<<obj1<<endl;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Current alive Reversi game object number is:"<< Reversi::getNumOfAliveCell()<<endl<<endl;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Testing for prefix and postfix operators with first parameter."<<endl;
        obj1++;
        ++obj1;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"First game continues"<<endl<<obj1;
        while( !obj1.isFinish() ){
            obj1.playGame();
        }
        obj1.displayScore();
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Testing for compare function using with parameters."<<endl;
        if(obj1.compare(obj2) )
            cout<<"First Reversi paramater player cell count is more than second parameter. "<<endl;
        else
            cout<<"First Reversi parameter player cell count is less than second parameter. "<<endl;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Play with second parameter for 3 steps."<<endl;
        const int stepCount = 3;
        cout<<obj2;
        for(int i= 0; i< stepCount ; ++i){
            if( ! obj2.isFinish()){
                obj2.playGame();
            }
            else{
                obj2.displayScore();
                break;
            }
        }
        
        obj2++;
        ++obj2;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Compares local game and second parameter."<<endl;
        if(game.compare(obj2))
            cout<<"Local Reversi object player cell count is more than second parameter. "<<endl;
        else
            cout<<"Local Reversi object player cell count is less than second parameter. "<<endl;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Test for resize function"<<endl;
        int rowNum= 4;
        int colNum = 6;
        obj2.resize(rowNum,colNum);
        cout<<obj2;


    }


    void testCallVyReferance( Reversi &obj1, Reversi &obj2 ){

        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"----------------TESTING FOR CALL BY REFERENCE FUNCTION -------------"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl<<endl;

        cout<<"Test first parameter Reversi game object with a single playGame function."<<endl;
        obj1.displayBoardOnScreen();
        obj1.playGame();
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Test second parameter Reversi game object with a single playGame function."<<endl;
        obj2.displayBoardOnScreen();
        obj2.playGame();
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Testing for copy constructor using first game object."<<endl;
        Reversi game(obj1);
        game.displayBoardOnScreen();
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Testing for stream insertion operator for new game object."<<endl;
        cout<<game<<endl<<"Testing for stream insertion operator for fisrt parameter"<<endl<<obj1<<endl;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Current alive Reversi game object number is:"<< Reversi::getNumOfAliveCell()<<endl<<endl;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Testing for prefix and postfix operators with first parameter."<<endl;
        obj1++;
        ++obj1;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"First game continues"<<endl<<obj1;
        while( !obj1.isFinish() ){
            obj1.playGame();
        }
        obj1.displayScore();
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Testing for compare function using with parameters."<<endl;
        if(obj1.compare(obj2) )
            cout<<"First Reversi paramater player cell count is more than second parameter. "<<endl;
        else
            cout<<"First Reversi parameter player cell count is less than second parameter. "<<endl;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Play with second parameter for 3 steps."<<endl;
        const int stepCount = 3;
        cout<<obj2;
        for(int i= 0; i< stepCount ; ++i){
            if( ! obj2.isFinish()){
                obj2.playGame();
            }
            else{
                obj2.displayScore();
                break;
            }
        }
        
        obj2++;
        ++obj2;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Compares local game and second parameter."<<endl;
        if(game.compare(obj2))
            cout<<"Local Reversi object player cell count is more than second parameter. "<<endl;
        else
            cout<<"Local Reversi object player cell count is less than second parameter. "<<endl;
        
        cout<<"-------------------------------------------------------------------"<<endl<<endl;
        cout<<"Test for resize function"<<endl;
        int rowNum= 4;
        int colNum = 6;
        obj2.resize(rowNum,colNum);
        cout<<obj2;

    }
    
    //initialization of static data member
    int Reversi::numRversiObj = 0;
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Overloading stream insertion operator
    ostream & operator << ( ostream & out, const Reversi & other){
    
        int size = 0;
        
        out<< setw(3) << "  ";
        if ( other.getRow() < 26 ) {
            for (int i = 0; i < other.getCol(); ++i) {
                out << setw(2) << " " << static_cast<char> ('A' + i);
            }
            out << setw(3) << endl;
        
        }else {
	    for (int i = 0; i < 26; ++i) {
	        out << setw(2) << " " << static_cast<char> ('A' + i);
	    }
	    for (int i = 0; i < other.getCol() - 26; ++i) {
	        out << setw(2) << 'A' << static_cast<char> ('A' + i);
	    }
	    out << setw(3) << endl;
	}
        
        for(int i= 0; i< other.getRow(); ++i){
	    out << setw(3) << i + 1 ;
	    
	    for(int j =0; j< other.getCol(); ++j){
	        out << setw(3) <<other.gameCells[size].getFeature();
	        size ++;
	    }
	    out << endl;
	}
        
        return out;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Constructor with no parameter
    Reversi::Reversi(){
        
        row = 8;
        col = 8;
        
        int size = 0;   
        
        //cout<<"Allocated default"<<endl;
        gameCells = new Cell [row*col];
      
        for (int i = 0; i < row; ++i) {

            for (int j = 0; j < col; ++j) {

                if (i == (row / 2 - 1) && j == (col / 2 - 1))
                    gameCells[size] = Cell(j,i,COMPUTER);
                else if (i == (row / 2 - 1) && j == (col / 2))
                    gameCells[size] = Cell(j,i,PLAYER);
                else if (i == (row / 2) && j == (col / 2 - 1))
                    gameCells[size] = Cell(j,i,PLAYER);
                else if (i == (row / 2) && j == (col / 2))
                    gameCells[size] = Cell(j,i,COMPUTER);
                else
                    gameCells[size] = Cell(j,i,EMPTY);
                size ++;
            }
            
        }
        setUsed(size);
        //numOfAliveCell +=4;
        numRversiObj += 1;
    }
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Constructor with row and col values
    Reversi::Reversi(const int & newX, const int & newY): row(newX),col(newY){
        
        int size = 0;   
        
        //cout<< "Allocated n*m"<<endl;
        gameCells = new Cell [row*col];
      
        for (int i = 0; i < row; ++i) {

            for (int j = 0; j < col; ++j) {

                if (i == (row / 2 - 1) && j == (col / 2 - 1)){
                    gameCells[size] = Cell(j,i,COMPUTER);
                    //numOfAliveCell++;
                }                    
                else if (i == (row / 2 - 1) && j == (col / 2)){
                    gameCells[size] = Cell(j,i,PLAYER);
                   // numOfAliveCell++;
                }                    
                else if (i == (row / 2) && j == (col / 2 - 1)){
                    gameCells[size] = Cell(j,i,PLAYER);
                    //numOfAliveCell++;
                }
                   
                else if (i == (row / 2) && j == (col / 2)){
                    gameCells[size] = Cell(j,i,COMPUTER);
                    //numOfAliveCell++;
                }                    
                else
                    gameCells[size] = Cell(j,i,EMPTY);
                size ++;
            }  
        }
        setUsed(size);
        numRversiObj += 1;
    }
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Constructor using a file
    Reversi::Reversi(const char* fname){
        readFromFile(fname);
        numRversiObj += 1;
    }
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Copy constructor
    Reversi::Reversi(const Reversi &other){
        
        this->used = other.getUsed();
        this->col = other.getCol();
        this->row = other.getRow();
        
        //cout<<"allocated copy const"<<endl;
        gameCells = new Cell [other.getUsed()];

        for(int i = 0; i< getUsed();++i){
            this->gameCells[i] = other.gameCells[i];
            
            /*if(other.gameCells[i].getFeature() != EMPTY)
                numOfAliveCell++;*/
        }
        
        numRversiObj += 1;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Destructor
    Reversi::~Reversi(){
       
        numRversiObj -= 1 ;
        delete [] gameCells;
        //cout<<"Mem deallocated"<<endl;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Overloading operator assignment
    Reversi & Reversi::operator=(const Reversi& other){

        int willBeDiedCellCount = currentAlive();
        
        //numOfAliveCell -= willBeDiedCellCount;
        if( getUsed() != other.getUsed()){
            delete [] this->gameCells;
            setUsed(other.getUsed());
            this->row= other.getRow();
            this->col= other.getCol();
            this->gameCells = new Cell[this->getUsed()];
        }
    
        for( int i=0; i< getUsed(); ++i){
            gameCells[i] = other.gameCells[i];
            /*if(gameCells[i].getFeature() != EMPTY)
                    numOfAliveCell++;*/
        }
        
        return *this;
        
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Overloading operator ++ prefix
    Reversi Reversi::operator ++(void){

        Cell c;
        if( computerMove(&c) ){            
            this->play();
        }
        return *this;
    }

    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Overloading the operator ++ postfix
    Reversi Reversi::operator ++(const int ignoreMe){
        
        Reversi temp;
        temp = *this;
        Cell c;
        if( computerMove(&c) ){            
            this->play();
        }
        return temp;
    }	
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    // displays the current Reversi game object on screen
    void Reversi::displayBoardOnScreen() const {
        
        int size = 0;
        
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
        
        for(int i= 0; i< getRow(); ++i){
            cout << setw(3) << i + 1 ;
            
            for(int j =0; j< getCol(); ++j){
                cout << setw(3) <<gameCells[size].getFeature();
                size ++;
            }
            cout << endl;
        }
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //A function reads a file as input to initialize the Reversi game object
    void Reversi::readFromFile(const char * fname) {

        ifstream in;

        in.open(fname);
        char ch;

        int currentRow = 0;
        int currentCol = 0;
        //create current row
        while ((ch = in.get()) != EOF) {

            if (ch != '\n' && ch != ' ') {
                currentCol++;
            }
            else{
                currentRow++;
                currentCol =0;
            }
        }
        currentRow++;
        in.close();

        row = currentRow;
        col = currentCol;
        used = row * col;

        gameCells = new Cell [row*col];
        in.open(fname);
        
        currentRow = 0;
        currentCol = 0;
        int size=0;
        while ((ch = in.get()) != EOF) {

            if (ch != '\n' && ch != ' ') {
                if (ch != '.') {
                    gameCells[size] = Cell(currentCol,currentRow,ch);
                    //numOfAliveCell++;
                    size++;
                }
                else if(ch == '.'){
                    gameCells[size] = Cell(currentCol,currentRow,ch);
                    size ++;
                }
                
                currentCol++;
            } else if (ch == '\n') {
                currentRow++;
                currentCol=0;
            }
        }
        in.close();
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //returns all Reversi Objects alive Cell
    int Reversi::getNumOfAliveCell(){
        return numRversiObj;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Bir objenin kac tane canli hucresi oldugunu return eder.
    //numOfAliveCell'i copy constructor'da update etmek amacli kullanildi
    int Reversi::currentAlive()const{
        int count =0;
        for(int i=0; i< getUsed() ; ++i){
            
            if(gameCells[i].getFeature() != EMPTY)
                count++;
        }
        return count;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Kendisine gelen cell player ise computer, computer ise player olarak reverse eder
    void Reversi::reverse(Cell &cell) {

        if (cell.getFeature() == COMPUTER)
            cell.set(cell.getX(), cell.getY(), PLAYER);
        else if (cell.getFeature() == PLAYER)
            cell.set(cell.getX(), cell.getY(), COMPUTER);
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Parameter olarak gonderilen i ve j nin dogrultusundaki dondurelecek olan hücreyi
    //return eder.
    const Cell * Reversi::findMatching(const Cell &cell, int di, int dj) const{
        for (int c = 1;
               (cell.getX() + di * c) >= 0 
            && (cell.getX() + di * c) != col
            && (cell.getY() + dj * c) >= 0
            && (cell.getY() + dj * c) != row; ++c){
            int c_x = cell.getX() + di * c;
            int c_y = cell.getY() + dj * c;
            int index = (c_x+di) + (c_y+dj)*col;
            if ( !(index >=0 && index< getUsed()) )
                return NULL;
            else if ( gameCells[ index ].getFeature() == EMPTY )
                return NULL;
            else if ( gameCells[index ].getFeature() == cell.getFeature())
                return &gameCells[ index ];
        }
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Parametre olarak gelen baslangic ve bitis cell'leri arasindaki cevirilebilen cell'eri reverse eder.
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
            
            int c_x = end.getX() + cX * c;
            int c_y = end.getY() + cY * c;
            int index = c_x + c_y * col ;
            
            if(index >= 0 && index < getUsed())
                reverse( gameCells[ index ] );
            
        }
    }
   
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Move olarak gelen Cell'e gore oyunu oynar.
    void Reversi::reverseButtons(Cell & cell) {
        const Cell *target;
        
        int c_x = cell.getX();
        int c_y = cell.getY();
        int index = 0;
        
        gameCells[ c_x +c_y*col ] = cell;
        //numOfAliveCell++;
           
        for (int j = -1; j <= 1; ++j) {
            for (int i = -1; i <= 1; ++i) {
                index = (c_x+i) + (c_y+j)*col;
                //first check boundries then game rules
                if( (c_x+i) >= 0 && (c_y+j) >= 0 && c_x+i < getCol() && c_y+j < getRow()){
                    if ( gameCells[ index ].getFeature() != EMPTY && gameCells[ index ].getFeature() != cell.getFeature()) {
                        if (!(i == 0 && j == 0)) {
                            //cross
                            target = findMatching(cell, i, j);
                            if (target != NULL)
                                reverse(cell, *target);
                        }
                    }
                }
            }
        }
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Play function for user move 
    void Reversi::play(Cell & point) {
        reverseButtons(point);
    }
        
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //gameCells'deki canli hucre sayisi used'a esit ise board dolmustur.
    bool Reversi::isBoardFilled() const{
    
        return ( currentAlive() == getUsed() );
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //player'in girdigi hamle legal mi degil mi ?
    //cell in feature u hamle yapan kisi
    bool Reversi::isLegalMove(const Cell &cell) const {
       
        int c_x = cell.getX();
        int c_y = cell.getY();
        int index = 0;
        
        if( gameCells[ cell.getX() + cell.getY()*col].getFeature() != EMPTY )
            return false;
        
        for (int j = -1; j <= 1; ++j) {
            for (int i = -1; i <= 1; ++i) {
                index = (c_x+i) + (c_y+j)*col;
                //first check boundries then game rules
                if( (c_x+i) >= 0 && (c_y+j) >= 0 && c_x+i < getCol() && c_y+j < getRow()){
                    if (index >= 0 && index < getUsed() && gameCells[ index ].getFeature() != EMPTY && gameCells[ index ].getFeature() != cell.getFeature()) {
                        if (!(i == 0 && j == 0)) {
                            //cross
                            if (findMatching(cell, i, j) != NULL)
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //if computer can play return x and y coordinates and true
    bool Reversi::computerMove(Cell *cell) const {     
        if (!isBoardFilled()) {
            for (int i = 0; i < getRow(); ++i) {
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
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //player'in hamlesi kaldi mi 
    bool Reversi::canPlayerMove()const {
        if (!isBoardFilled()) {
            for (int i = 0; i < getRow(); ++i) {
                for (int j = 0; j < getCol(); ++j) {
                    if (isLegalMove(Cell(j, i, PLAYER))){
                        //cerr << "y: " << i << " || x: " << j << endl;
                        return true;}
                }
            }
        }
        return false;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //if game is end returns true else returns false
    bool Reversi::isFinish() const {
        Cell cell;
        
        if (!computerMove(&cell) && !canPlayerMove())
            return true;
        
        return false;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //play for a single step with no parameter for computer
    void Reversi::play() {

        Cell move;
        if (computerMove(&move)){
            reverseButtons(move);
            move.setY(move.getY() + 1);
            cout<<"Computer played to";
            move.output();
            cout<<endl;
            displayBoardOnScreen();
        }
        else
            cout << "There is no legal move for computer." << endl << "The turn is yours Player!" << endl;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Retursn the count of computer cells and player cells
    void Reversi::memberCount(int *XCount, int *OCount)const{
    
        int xC =0, oC = 0;
        for(int i= 0; i< getUsed(); ++i){
            if( gameCells[i].getFeature() == COMPUTER)
                xC++;
            else if( gameCells[i].getFeature() == PLAYER)
                oC++;
        }
        *XCount = xC;
        *OCount = oC;
    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //compares other Reversi game object with player Cells count
    bool Reversi::compare(const Reversi &other) const {
    
        int otherXC=0, otherOC=0, thisXC=0, thisOC=0;

        memberCount( &thisXC, &thisOC);
        other.memberCount( &otherXC, &otherOC);

        if(thisOC > otherOC)
            return true;

        return false;    

    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //function play a single step first for player next for computer
    void Reversi::playGame() {
    
        if( isFinish() ){
            cout << "GAME OVER!" << endl;
            displayScore();
            return;
        }

        if (canPlayerMove()) {

            Cell point;

            while (1) {

                point.input();
                point.set(point.getY(), point.getX() - 1);

                if ( isLegalMove(point) ) {
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
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //Display the score end of the game
    void Reversi::displayScore()const{
        int XC,OC;
        memberCount( &XC , &OC );
        cout<<endl<<"COMPUTER :"<<XC<<"    PLAYER :"<<OC<<endl;
        if(XC > OC)
            cout<<"The winner is COMPUTER."<<endl;
        else if(XC < OC)
            cout<<"The winner is PLAYER."<<endl;
        else
            cout<<"There is a TIE."<<endl;

    }
    
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//
    //resize the object with new parameters
    void Reversi::resize(const int &newCol, const int &newRow){
    
        int size = newCol*newRow;
        delete gameCells;
        
        gameCells = new Cell[size];
        
        row = newRow;
        col = newCol;
        
        size = 0;
        
        for (int i = 0; i < row; ++i) {

            for (int j = 0; j < col; ++j) {

                if (i == (row / 2 - 1) && j == (col / 2 - 1)){
                    gameCells[size] = Cell(j,i,COMPUTER);
                    //numOfAliveCell++;
                }                    
                else if (i == (row / 2 - 1) && j == (col / 2)){
                    gameCells[size] = Cell(j,i,PLAYER);
                   // numOfAliveCell++;
                }                    
                else if (i == (row / 2) && j == (col / 2 - 1)){
                    gameCells[size] = Cell(j,i,PLAYER);
                    //numOfAliveCell++;
                }
                   
                else if (i == (row / 2) && j == (col / 2)){
                    gameCells[size] = Cell(j,i,COMPUTER);
                    //numOfAliveCell++;
                }                    
                else
                    gameCells[size] = Cell(j,i,EMPTY);
                size ++;
            }  
        }
        setUsed(size);
    }
    
}//sevgiborazan
