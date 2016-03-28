/* 
 * File:   Numbers.h
 * Author: sevgiborazan
 *
 * Created on 12 Aralik 2015 Cumartesi, 13:46
 */

// This is the header file Numbers.h.
// This is the interface for the class Numbers.
// This is primarily intended to be used as a base class to derive 
//classes for different kind of Numbers.
//This class doesnt have an object, it has pure virtual function.

#ifndef NUMBERS_H
#define	NUMBERS_H

namespace sevgiborazan{
    
    void test();

    class Numbers{
    public:
        //Constructors
        Numbers();
        virtual ~Numbers();
        
        static int getNumbersObjCount();
        
        //pure virtual functions
        virtual void output()const = 0;
        virtual void input() = 0;
        
        
    private:
        static int numbersObjCount;
        
    };//class Numbers


}//sevgiborazan


#endif	/* NUMBERS_H */

