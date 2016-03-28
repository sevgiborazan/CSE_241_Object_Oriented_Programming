/* 
 * File:   ComplexNumber.h
 * Author: sevgiborazan
 *
 * Created on 14 Aralik 2015 Pazartesi, 12:20
 */

#ifndef COMPLEXNUMBER_H
#define	COMPLEXNUMBER_H

#include "Numbers.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

using std ::ostream; 

namespace sevgiborazan{

    class ComplexNumber: public Numbers{
    public:
        //Constructors
        ComplexNumber();
        ComplexNumber(const int & newNum );
        ComplexNumber(const int & newNum ,const int &newDenum );
        ComplexNumber(const int & newNum ,const int &newDenum ,const double &newIm );
        virtual ~ComplexNumber();
        
        //setters
        // The classes who are derived from ComplexNumber have to redifine setters.
        virtual void setNum(const int &newNum);
        virtual void setDenum(const int &newDenum);
        virtual void setIm(const double &newIm);
        virtual void setReal(const double & newReal);
        
        //getters
        inline int getNum()const{ return num; }
        inline int getDenum()const{ return denum; }
        inline double getIm()const{ return im; }
        inline double getReal()const{ return real; }
        inline char getImRep()const { return imRep; }
        inline double getZ()const{ return z; }    
        
        static int getComplexObjCount();

        void output()const;
        void input();
        
        friend ostream& operator <<(ostream& outStream,const ComplexNumber& other);
        const ComplexNumber operator +(const ComplexNumber& other)const;
        const ComplexNumber operator -(const ComplexNumber& other)const;
        bool operator< (const ComplexNumber& other)const;
        
    protected:
        int num;
        int denum;
        double im;
        double real;
        double z;   //magnitude of complex number
        static int complexObjCount;
        const static char imRep = 'i'; //representation of imanigary numbers as a+b*i
        const static double epsilon = 0.000001;
        double calculateMagnitude()const;
        
    
    };//class ComplexNumber


}//sevgiborazan


#endif	/* COMPLEXNUMBER_H */

