//This is the implementation for the class IntegerNumber.
//This is the file IntegerNumber.cpp.
//The interface for the class IntegerNumber is in the header file IntegerNumber.h.


#include "IntegerNumber.h"

using std ::cerr;
using std ::endl;
using std ::cout;
using std ::cin;
using std ::ios;

namespace sevgiborazan{
    
    //initialize the static member
    int IntegerNumber::intObjCount = 0;
    
    //----------------------------------------------------------------------------//
    //Constructors
    IntegerNumber::IntegerNumber():RationalNumber(){
        denum = 1;
        real = static_cast<double>(num)/denum;
        z = calculateMagnitude();
        intObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    IntegerNumber::IntegerNumber(const int & newNum):RationalNumber(newNum){
        denum = 1;
        real = static_cast<double>(num)/denum;
        z = calculateMagnitude();
        intObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    IntegerNumber::~IntegerNumber(){
        intObjCount--;
    }

    //----------------------------------------------------------------------------//
    //redefine the setter of denum
    //set denum to 1 whatever it is
    void IntegerNumber::setDenum(const int &newDenum){
        denum = 1;
    } 

    //----------------------------------------------------------------------------//
    //getter
    int IntegerNumber::getIntObjCount(){
        return intObjCount;
    }

    //----------------------------------------------------------------------------//
    void IntegerNumber::output()const{
        cout<<getNum();
    }
    
    //----------------------------------------------------------------------------//
    void IntegerNumber::input(){
        cout<<"Enter an integer number."<<endl;
        cin>> num;
        denum = 1;
        z = calculateMagnitude();
    }

    //----------------------------------------------------------------------------//
    ostream& operator <<(ostream& outStream,const IntegerNumber& other){
        outStream<< other.getNum();
        return outStream;
    }
    
    //----------------------------------------------------------------------------//
    const IntegerNumber IntegerNumber::operator +(const IntegerNumber& other)const{
        IntegerNumber result;
        
        result.num = ( this->getNum() * other.getDenum() ) + ( other.getNum() * this->getDenum() );
        result.denum = 1;
        result.z = result.calculateMagnitude();
                
        return result;
    }
    
    //----------------------------------------------------------------------------//
    const IntegerNumber IntegerNumber::operator -(const IntegerNumber& other)const{
        IntegerNumber result;
        
        result.num = ( this->getNum() * other.getDenum() ) - ( other.getNum() * this->getDenum() );
        result.denum = 1;
        result.z = result.calculateMagnitude();
                
        return result;
    }
    
    //----------------------------------------------------------------------------//
    bool IntegerNumber::operator< (const IntegerNumber& other)const{
        if( this->getZ() < other.getZ() )
            return true;
        return false;
    }

}//sevgiborazan