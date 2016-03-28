/* 
 * File:   IrrationalNumber.h
 * Author: sevgiborazan
 *
 * Created on 14 Aralik 2015 Pazartesi, 13:04
 */

// This is the header file IrrationalNumber.h.
// This is the interface for the class IrrationalNumber derived from RealNumber.

#ifndef IRRATIONALNUMBER_H
#define	IRRATIONALNUMBER_H

#include "RealNumber.h"

namespace sevgiborazan{

    class Irrational: public RealNumber{
    public:
        //Constructors
        Irrational();
        ~Irrational();
        
        //getter
        static int getIrratObjCount();
        static double getPi();
        static double getE();
        
        void output()const;
        void input();
        
        friend ostream& operator <<(ostream& outStream,const Irrational& other);
        const Irrational operator +(const Irrational& other)const;
        const Irrational operator -(const Irrational& other)const;
        bool operator< (const Irrational& other)const;
        
    private:
        static int irratObjCount;
        const static double PI = 3.141592653589;
        const static double e = 2.718281828459;
        
    };//class RationalNumber
    
}//sevgiborazan


#endif	/* IRRATIONALNUMBER_H */

