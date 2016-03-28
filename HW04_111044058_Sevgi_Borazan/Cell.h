/* 
 * File:   Cell.h
 * Author: sevgiborazan
 *
 * Created on 08 Kasım 2015 Pazar, 00:18
 */

#include <string>

using namespace std;

#ifndef CELL_H
#define	CELL_H

class Cell{

public:

	//Constructors
	Cell();
	//Cell(const int & newY);
	Cell(const int & newX);
        Cell(const char newFeature);
	Cell(const int & newX, const int & newY);
        Cell(const int & newX, const int & newY,const char newFeature);        

	//setters
	void setX(const int & newX);
	void setY(const int & newY);
        void set(const char newFeature);
	void set(const int & newX, const int & newY);
        void set(const int & newX, const int & newY, const char newFeature);

	//getters
	inline int getX()const{ return x;}
	inline int getY()const{ return y;}
        inline char getFeature()const{ return feature;}

	void input();
	void output()const;

private:
        int y; //to hold CoorX as string    --col
	int x;    //to hold CoorY           --row
        char feature;   //the cell is empty or user or computer
        const static char PLAYER = 'O';
	const static char COMPUTER = 'X';
	void testData()const;
        int char2int(const string &s);
        void int2char(const int & i)const;
};


#endif	/* CELL_H */

