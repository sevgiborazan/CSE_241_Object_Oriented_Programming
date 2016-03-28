/* 
 * File:   RealNumber.h
 * Author: sevgiborazan
 *
 * Created on 14 Aralik 2015 Pazartesi, 01:51
 */


// This is the header file RealNumber.h.
// This is the interface for the class RealNumber derived from ComplexNumber.
// This is primarily intended to be used as a base class to derive 
//classes for different kind of RealNumbers.

#ifndef REALNUMBER_H
#define	REALNUMBER_H

#include "ComplexNumber.h"

namespace sevgiborazan{

    class RealNumber: public ComplexNumber{
    public:
        //Constructors
        RealNumber();
        RealNumber(const int & newNum);
        RealNumber(const int & newNum ,const int &newDenum );
        RealNumber(const double &newReal);
        virtual~RealNumber();
        
        //setters
        void setNum(const int &newNum); //set num to what ever it is
        void setDenum(const int &newDenum); //set denum to what ever it is
        void setIm(const int &newIm);   //set im to zero
        void setReal(const double & newReal);  //set real to what ever it is      
        
        //getter
        static int getRealObjCount();
        
        void output()const;
        void input();
        
        friend ostream& operator <<(ostream& outStream,const RealNumber& other);
        const RealNumber operator +(const RealNumber& other)const;
        const RealNumber operator -(const RealNumber& other)const;
        bool operator< (const RealNumber& other)const;
        
    private:
        static int realObjCount;
        
    };//class RealNumber

}//sevgiborazan


#endif	/* REALNUMBER_H */

