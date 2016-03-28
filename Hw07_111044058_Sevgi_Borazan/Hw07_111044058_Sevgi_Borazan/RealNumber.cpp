//This is the implementation for the class RealNumber.
//This is the file RealNumber.cpp.
//The interface for the class RealNumber is in the header file RealNumber.h.

#include "RealNumber.h"

using std ::cerr;
using std ::endl;
using std ::cout;
using std ::cin;
using std ::ios;

namespace sevgiborazan{
    
    //initialize static member
    int RealNumber::realObjCount = 0;
    
    //Constructors
    //----------------------------------------------------------------------------//
    RealNumber::RealNumber():ComplexNumber(){
        realObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    RealNumber::RealNumber(const int & newNum):ComplexNumber(newNum){
        num = newNum;
        z = ComplexNumber::calculateMagnitude();
        realObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    RealNumber::RealNumber(const int & newNum ,const int &newDenum ):ComplexNumber(newNum, newDenum){
        
        num = newNum;
        if( newDenum == 0){
            cerr<<"Denominator can not be zero."<<endl;
            exit(1);
        }
        denum = newDenum;
        z = ComplexNumber::calculateMagnitude();
        realObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    RealNumber::RealNumber( const double &newReal):ComplexNumber(){
        setReal( newReal);
        z = ComplexNumber::calculateMagnitude();
        realObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    RealNumber::~RealNumber(){
        realObjCount--;
    }

    //setters    
    //----------------------------------------------------------------------------//
    //set num to what ever it is
    void RealNumber::setNum(const int &newNum){
        num = newNum;
        real = static_cast<double>(num) /denum;
        z = ComplexNumber::calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
    //set denum to what ever it is
    void RealNumber::setDenum(const int &newDenum){
        denum = newDenum;
        real = static_cast<double>(num) /denum;
        z = ComplexNumber::calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
    //set im to zero
    void RealNumber::setIm(const int &newIm){
        im = 0;
        real = static_cast<double>(num) /denum;
        z = ComplexNumber::calculateMagnitude();
    } 
    
    //----------------------------------------------------------------------------//
    //set real to what ever it is 
    void RealNumber::setReal(const double & newReal){
        real = newReal;
        
        double temp = newReal;
        int coeff = 1;//coefficient
        
        while( !(( temp - static_cast<int>(temp) ) < epsilon && ( temp - static_cast<int>(temp) ) > -epsilon ) ){
            temp *= 10;
            coeff *= 10;            
        }
        denum = coeff;
        num = temp;
        z = ComplexNumber::calculateMagnitude();
    } 

    //----------------------------------------------------------------------------//
    //getter
    int RealNumber::getRealObjCount(){
        return realObjCount;
    }
    
    //----------------------------------------------------------------------------//
    void RealNumber::output()const{
        cout.setf( ios:: fixed);
        cout.setf( ios:: showpoint);
        cout.precision(3);
        cout<<getReal()<<endl;
    }
    
    //----------------------------------------------------------------------------//
    void RealNumber::input(){
        double inp;
        cout<<"Please enter a fractional number or real number."<<endl;
        cin>>inp;
        setReal(inp);
    }

    //----------------------------------------------------------------------------//
    ostream& operator <<(ostream& outStream,const RealNumber& other){
    
        outStream.setf( ios:: fixed);
        outStream.setf( ios::showpoint);
        outStream.precision(3);
        outStream<< other.getReal();
        return outStream;
    }
    
    //----------------------------------------------------------------------------//
    const RealNumber RealNumber::operator +(const RealNumber& other)const{
        RealNumber result;
        
        result.setNum( ( this->getNum() * other.getDenum() ) + ( other.getNum() * this->getDenum() ) );
        result.setDenum( this->getDenum() * other.getDenum() );
                
        return result;
    }
    
    //----------------------------------------------------------------------------//
    const RealNumber RealNumber::operator -(const RealNumber& other)const{
        RealNumber result;
        
        result.num = ( this->getNum() * other.getDenum() ) - ( other.getNum() * this->getDenum() );
        result.setDenum( this->getDenum() * other.getDenum() );
                
        return result;
    }
    
    //----------------------------------------------------------------------------//
    bool RealNumber::operator< (const RealNumber& other)const{
        if( this->getZ() < other.getZ() )
            return true;
        return false;
    }


}//sevgiborazan
    