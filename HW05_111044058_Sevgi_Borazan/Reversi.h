/* 
 * File:   Reversi.h
 * Author: sevgiborazan
 *
 * Created on 26 Kasim 2015 Persembe, 14:03
 */

using namespace std;

#include "Cell.h"
#include <vector>
#include <string>

#ifndef REVERSI_H
#define	REVERSI_H

class Reversi {
public:
	//Constructors
	Reversi();
	Reversi(const int & newX, const int & newY);
	Reversi(const char* fname);

	//setters
	inline void setCol(const int & newCol) { col = newCol; }
	inline void setRow(const int & newRow) { row = newRow; }

	//getters
	inline int getCol() const { return col; }
	inline int getRow() const { return row; }
	static int getNumOfAliveCell();

	//other member functions
	void write2File(const char * fname) const;
	void readFromFile(const char * fname);
	void displayBoardOnScreen() const;

	void play();    //for computer move
	void play(Cell & point);   //for player move
	void playGame();

	bool compare(const Reversi &other) const;
        void displayScore()const;
        bool isFinish() const;

        
        Reversi operator ++(void);
        Reversi operator ++(const int ignoreMe);	
        Reversi operator --(void);
        Reversi operator --(const int ignoreMe);

        void operator +=( Cell &other);

        Cell operator ()(int r, string c);

        Cell operator [](string s);
		
private:
	vector< vector<Cell> > gameCells;
	int row;
	int col;
	static int numOfAliveCell;
        
        vector<Reversi> playedGames;

	const static char PLAYER = 'O';
	const static char COMPUTER = 'X';
	bool isMember(const int &r, const int &c) const;
	bool isSamePlayer(const int &r, const int &c, const char &p) const;
	Cell &returnCell(const int &r, const int& c);
	const Cell &returnCell(const int &r, const int& c) const;

	void reverse(Cell &cell);
	void reverse(const Cell &start, const Cell &end);
	const Cell *findMatching(const Cell &cell, int di, int dj) const;
	void reverseButtons(Cell &cell);
	bool isBoardFilled() const;  //check the empty cells if there is return true
	bool computerMove(Cell *cell)const; //if computer can play return x and y coordinates and true
	bool canPlayerMove() const;  //player'in hamlesi kaldi mi
	bool isLegalMove(const Cell &cell) const; //player'in girdigi hamle legal mi degil mi ?
        void memberCount(int *XCount, int *YCount)const;
        int char2int(const string &s);
	
};

#endif	/* REVERSI_H */

