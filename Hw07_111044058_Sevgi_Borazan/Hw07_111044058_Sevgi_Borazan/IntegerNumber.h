/* 
 * File:   IntegerNumber.h
 * Author: sevgiborazan
 *
 * Created on 14 Aralik 2015 Pazartesi, 02:31
 */


// This is the header file IntegerNumber.h.
// This is the interface for the class IntegerNumber derived from RationalNumber.
// This is primarily intended to be used as a base class to derive 
//classes for different kind of IntegerNumber.

#ifndef INTEGERNUMBER_H
#define	INTEGERNUMBER_H

#include "RationalNumber.h"

namespace sevgiborazan{

    class IntegerNumber: public RationalNumber{
    public:
        //Constructors
        IntegerNumber();
        IntegerNumber(const int & newNum);
        virtual ~IntegerNumber();
        
        
        //redefine the setter of denum
        void setDenum(const int &newDenum); //set denum to 1 whatever it is
        
        //getter
        static int getIntObjCount();
        
        void output()const;
        void input();
        
        friend ostream& operator <<(ostream& outStream,const IntegerNumber& other);
        const IntegerNumber operator +(const IntegerNumber& other)const;
        const IntegerNumber operator -(const IntegerNumber& other)const;
        bool operator< (const IntegerNumber& other)const;
        
    private:
        static int intObjCount;
        
    };//class IntegerNumber

}//sevgiborazan

#endif	/* INTEGERNUMBER_H */

