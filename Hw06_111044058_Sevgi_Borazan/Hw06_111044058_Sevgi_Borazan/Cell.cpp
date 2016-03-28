//This is the implementation file Cell.cpp of the class Cell.
//The interface for the class Cell is in the header file Cell.h.

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Cell.h"

using std::cout;
using std::cin;

namespace sevgiborazan{
 
    //Constructors

    Cell::Cell() : x(0), y(0), feature('.') {
        /*Body is empty*/
    }

    ///////////////////////////////////////////////////////////////////////////////

    Cell::Cell(const int & newX) : x(newX), y(0), feature('.') {

        testData();
    }

    Cell::Cell(const char newFeature) : x(0), y(0), feature(newFeature) {

        testData();
    }

    ///////////////////////////////////////////////////////////////////////////////

    Cell::Cell(const int & newX, const int & newY) : x(newX), y(newY), feature('.') {

        testData();
    }

    ///////////////////////////////////////////////////////////////////////////////

    Cell::Cell(const int & newX, const int & newY, const char newFeature) :
    x(newX), y(newY), feature(newFeature) {

        testData();
    }

    ///////////////////////////////////////////////////////////////////////////////
    //setters

    void Cell::setX(const int & newX) {

        x = newX;
        testData();
    }

    ///////////////////////////////////////////////////////////////////////////////

    void Cell::setY(const int & newY) {

        y = newY;
        testData();
    }
    ///////////////////////////////////////////////////////////////////////////////

    void Cell::set(const int & newX, const int & newY) {

        x = newX;
        y = newY;
        testData();
    }

    ///////////////////////////////////////////////////////////////////////////////

    void Cell::set(const char newFeature) {

        feature = newFeature;
        testData();
    }


    ///////////////////////////////////////////////////////////////////////////////

    void Cell::set(const int & newX, const int & newY, const char newFeature) {

        x = newX;
        y = newY;
        feature = newFeature;
        testData();
    }

    ///////////////////////////////////////////////////////////////////////////////

    void Cell::input() {
        string s;
        cout << "Enter your move" << endl;

        do {
            cin >> x >> s;

            y = char2int(s);
            if (x<0 || y<0)
                cout << "Invalid move try again!!!" << endl;
        } while ((x < 0) || (y < 0));

        set(PLAYER);
        testData();
    }

    ///////////////////////////////////////////////////////////////////////////////

    void Cell::output()const {

        cout << "(" << y << ",";
        int2char(x);
        cout << ")" << endl;
    }

    ///////////////////////////////////////////////////////////////////////////////

    void Cell::testData()const {
        /* for( int i =0; i< x.length() ; ++i){
             if( !( ( x[i] >= 'a' && x[i] <= 'z' ) || (  x[i] >= 'A' && x[i] <= 'Z') )){	
                 cerr<<"Coordinate X must contain only [a-z] or [A-Z] ."<<endl;
                 exit(1);
             }
         }

         if( y < 0){
             cerr<<"Coordinate Y must be positive."<<endl;
             exit(1);
         }

         if( !(feature =='.' || feature =='X' || feature =='O')){
             cerr<<"Invalid cell representation."<<endl;
             exit(1);
         }*/
    }


    ///////////////////////////////////////////////////////////////////////////////

    //  kendisine string olarak gelen parametrenin karakterlerine gore coordinat'i
    //integer haline cevirir ve return eder.
    //input fonksiyonunda kullanilir.

    int Cell::char2int(const string& s) {

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

    ///////////////////////////////////////////////////////////////////////////////

    // kendisine parametre olarak gelen sayinin represent edilirken temsil ettigi 
    //degeri ekrana basar, output fonksiyonunda cagirilir

    void Cell::int2char(const int &i)const {

        if (i < 26) {
            cout << static_cast<char> (97 + i) << " ";
        } else {
            int j = i % 26;
            cout << "a" << static_cast<char> (97 + j) << " ";
        }
    }

    ///////////////////////////////////////////////////////////////////////////////
    
    bool Cell::operator == (const Cell& other)const{

    if( (getY() == other.getY() ) && (getX() == other.getX()) && (getFeature() == other.getFeature()) )
        return true;
    return false;
}

    ///////////////////////////////////////////////////////////////////////////////

    bool Cell::operator != (const Cell& other)const{

        return !operator ==(other);
    }

    ///////////////////////////////////////////////////////////////////////////////

    ostream& operator << (ostream& out, const Cell& cell){

        out<<"("<<cell.getY()<<","<<cell.getX()<<")"<<endl;
        return out;    
    }

    ///////////////////////////////////////////////////////////////////////////////

    istream& operator >> (istream& inp, Cell& cell){

        inp>> cell.y >> cell.x;

        if(cell.x >=0 && cell.y >=0)
            return inp;
        else{
            cerr<<"Invalid coordinates"<<endl;
            exit(1);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////
    
    //Copy Constructor
    Cell::Cell(const Cell & other){
    
        this->x = other.x;
        this->y = other.y;
        this->feature = other.feature;
    }

    //Overloading operator assignment
    Cell & Cell::operator=(const Cell&other){
    
        this->x = other.x;
        this->y = other.y;
        this->feature = other.feature;
        
        return *this;
    }
    
}//sevgiborazan