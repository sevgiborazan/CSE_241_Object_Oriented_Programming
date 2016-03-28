/* 
 * File:   Cell.h
 * Author: sevgiborazan
 *
 * Created on 29 Kasım 2015 Pazar, 15:41
 */

//This is the header file Cell.h. This is the interface for the class Cell.
//Values of this type are x and y coordinates and who has thar coordinates.
#ifndef CELL_H
#define	CELL_H

#include <string>

using namespace std;

namespace sevgiborazan{

    class Cell{
            
        //This class does not need BIG THREE
        public:

            //Constructors
            Cell();
            Cell(const int & newX);
            Cell(const char newFeature);
            Cell(const int & newX, const int & newY);
            Cell(const int & newX, const int & newY,const char newFeature);
            
            //Copy Constructor
            Cell(const Cell & other);
            
            //Overloading operator assignment
            Cell & operator=(const Cell&other);

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

            //operators
            bool operator == (const Cell& other)const;
            bool operator != (const Cell& other)const;

            friend ostream& operator << (ostream& out, const Cell& cell);
            friend istream& operator >> (istream& inp, Cell& cell);

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

}//sevgiborazan
#endif	/* CELL_H */

