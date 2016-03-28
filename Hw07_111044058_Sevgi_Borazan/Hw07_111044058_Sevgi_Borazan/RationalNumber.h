/* 
 * File:   RationalNumber.h
 * Author: sevgiborazan
 *
 * Created on 14 Aralik 2015 Pazartesi, 02:06
 */


// This is the header file RationalNumber.h.
// This is the interface for the class RationalNumber derived from RealNumber.
// This is primarily intended to be used as a base class to derive 
//classes for different kind of RationalNumber.

#ifndef RATIONALNUMBER_H
#define	RATIONALNUMBER_H

#include "RealNumber.h"
#include <cstdio>
namespace sevgiborazan{

    class RationalNumber: public RealNumber{
    public:
        //Constructors
        RationalNumber();
        RationalNumber(const int& newNum);
        RationalNumber(const int& newNum, const int &newDenum);
        virtual ~RationalNumber();
        
        //getter
        static int getRationalObjCount();
        
        void output()const;
        void input();
        
        friend ostream& operator <<(ostream& outStream,const RationalNumber& other);
        const RationalNumber operator +(const RationalNumber& other)const;
        const RationalNumber operator -(const RationalNumber& other)const;
        bool operator< (const RationalNumber& other)const;
        
    private:
        static int rationalObjCount;
        
    };//class RationalNumber
    
}//sevgiborazan


#endif	/* RATIONALNUMBER_H */

