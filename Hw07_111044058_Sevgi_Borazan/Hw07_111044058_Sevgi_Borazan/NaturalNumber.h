/* 
 * File:   NaturalNumber.h
 * Author: sevgiborazan
 *
 * Created on 14 Aralik 2015 Pazartesi, 02:36
 */


// This is the header file NaturalNumber.h.
// This is the interface for the class NaturalNumber derived from IntegerNumber.

#ifndef NATURALNUMBER_H
#define	NATURALNUMBER_H

#include "IntegerNumber.h"

namespace sevgiborazan{

    class NaturalNumber: public IntegerNumber{
    public:  
        //Constructors
        NaturalNumber();
        NaturalNumber(const int& newNum);
        ~NaturalNumber();
        
        //set num to whatever it is if only if pozitive or zero
        void setNum(const int &newNum); 
        
        static int getNaturalObjCount();
        
        void output()const;
        void input();
        
        friend ostream& operator <<(ostream& outStream,const NaturalNumber& other);
        const NaturalNumber operator +(const NaturalNumber& other)const;
        const NaturalNumber operator -(const NaturalNumber& other)const;
        bool operator< (const NaturalNumber& other)const;
        
    private:
       static int naturalObjCount; 
    
    };//class NaturalNumber

}//sevgiborazan

#endif	/* NATURALNUMBER_H */

