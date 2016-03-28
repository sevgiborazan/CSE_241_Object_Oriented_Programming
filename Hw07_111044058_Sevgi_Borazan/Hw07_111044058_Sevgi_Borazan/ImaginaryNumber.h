/* 
 * File:   ImaginaryNumber.h
 * Author: sevgiborazan
 *
 * Created on 14 Aralik 2015 Pazartesi, 12:33
 */

// This is the header file ImaginaryNumber.h.
// This is the interface for the class ImaginaryNumber derived from ComplexNumber.
// This is primarily intended to be used as a base class to derive 
//classes for different kind of ImaginaryNumber.

#ifndef IMAGINARYNUMBER_H
#define	IMAGINARYNUMBER_H

#include "ComplexNumber.h"

namespace sevgiborazan{

    class ImaginaryNumber: public ComplexNumber{
    public:
        //Constructors
        ImaginaryNumber();
        ImaginaryNumber(const double & newIm);
        ~ImaginaryNumber();
        
        //setters
        void setNum(const int &newNum); //set num to zero for every value
        void setDenum(const int &newDenum); //set denum to 1 for every value
        void setIm(const double &newIm);   //set im to what ever it is
        void setReal(const int & newReal);  //set real to 0 for evey value
        
        //getter
        static int getImObjCount();
        
        void output()const;
        void input();
        
        friend ostream& operator <<(ostream& outStream,const ImaginaryNumber& other);
        const ImaginaryNumber operator +(const ImaginaryNumber& other)const;
        const ImaginaryNumber operator -(const ImaginaryNumber& other)const;
        bool operator< (const ImaginaryNumber& other)const;
        
    private:
        static int imObjCount;
        
    };//class RealNumber

}//sevgiborazan


#endif	/* IMAGINARYNUMBER_H */

