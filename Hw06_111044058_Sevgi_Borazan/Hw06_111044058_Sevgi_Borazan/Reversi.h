/* 
 * File:   Reversi.h
 * Author: sevgiborazan
 *
 * Created on 29 Kasim 2015 Pazar, 15:47
 */


//This is the header file od Reversi.h.This is the interface for the class Reversi.
//Values of this type are alive game cells as Cell object, current row and coloumn number.
#ifndef REVERSI_H
#define	REVERSI_H

using namespace std;

#include "Cell.h"
#include <string>


namespace sevgiborazan{
    
    //Pre class definiton for test functions
    class Reversi;
    
    void testCallByValue( Reversi obj1, Reversi obj2);
    void testCallVyReferance( Reversi &obj1, Reversi &obj2 );
    
    class Reversi {
        //This class has BIG THREE
        public:
            //Constructors
            Reversi();
            Reversi(const int & newX, const int & newY);
            Reversi(const char* fname);
            
            //Copy constructor
            Reversi(const Reversi &other);
            
            //Destructor
            ~Reversi();
            
            friend ostream & operator << ( ostream & out, const Reversi & other);
            
            //setters
            inline void setCol(const int & newCol) { col = newCol; }
            inline void setRow(const int & newRow) { row = newRow; }

            //getters
            inline int getCol() const { return col; }
            inline int getRow() const { return row; }
            inline int getUsed()const { return used; }
            static int getNumOfAliveCell();

            //other member functions
            void readFromFile(const char * fname);
            void displayBoardOnScreen() const;

            void play();    //for computer move
            void play(Cell & point);   //for player move
            void playGame();

            bool compare(const Reversi &other) const;
            void displayScore()const;
            bool isFinish() const;

            void resize(const int &newCol, const int &newRow);
            
            Reversi operator ++(void);
            Reversi operator ++(const int ignoreMe);
            
            //Overloading operator assignment
            Reversi & operator=(const Reversi& other);
            
        private:
            Cell * gameCells;
            int row;
            int col;
            int used;
            static int numRversiObj;

            const static char PLAYER = 'O';
            const static char COMPUTER = 'X';
            const static char EMPTY = '.';
            
            void reverse(Cell &cell);
            void reverse(const Cell &start, const Cell &end);
            const Cell *findMatching(const Cell &cell, int di, int dj) const;
            void reverseButtons(Cell &cell);
            bool isBoardFilled() const;  //check the empty cells if there is return true
            bool computerMove(Cell *cell)const; //if computer can play return x and y coordinates and true
            bool canPlayerMove() const;  //player'in hamlesi kaldi mi
            bool isLegalMove(const Cell &cell) const; //player'in girdigi hamle legal mi degil mi ?
            void memberCount(int *XCount, int *OCount)const;
            int char2int(const string &s);
            
            int currentAlive()const;
            
            inline void setUsed(const int & newUsed){ used = newUsed; }


    };
}//sevgiborazan

#endif	/* REVERSI_H */

