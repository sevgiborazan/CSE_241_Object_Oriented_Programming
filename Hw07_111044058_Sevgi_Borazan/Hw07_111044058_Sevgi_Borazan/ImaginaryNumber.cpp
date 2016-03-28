//This is the implementation for the class ImaginaryNumber.
//This is the file ImaginaryNumber.cpp.
//The interface for the class ImaginaryNumber is in the header file ImaginaryNumber.h.


#include "ImaginaryNumber.h"

using std ::cerr;
using std ::endl;
using std ::cout;
using std ::cin;
using std ::ios;

namespace sevgiborazan{

    //initialize the static member
    int ImaginaryNumber::imObjCount = 0;
    
    //Constructors
    //----------------------------------------------------------------------------//
    ImaginaryNumber::ImaginaryNumber():ComplexNumber(){
        imObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    ImaginaryNumber::ImaginaryNumber(const double & newIm):ComplexNumber(){
        im = newIm;
        real = 0;
        num = 0;
        denum =1;
        z = calculateMagnitude();
        imObjCount++;
    }
        
    //----------------------------------------------------------------------------//
    ImaginaryNumber::~ImaginaryNumber(){
        imObjCount--;
    }

    //setters
    //----------------------------------------------------------------------------//
    //set num to zero for every value
    void ImaginaryNumber::setNum(const int &newNum){
        num = 0;
        z = calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
     //set denum to 1 for every value
    void ImaginaryNumber::setDenum(const int &newDenum){
        denum = 1;
        z = calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
    //set im to what ever it is
    void ImaginaryNumber::setIm(const double &newIm){
        im = newIm;
        z = calculateMagnitude();
    }   
    
    //----------------------------------------------------------------------------//
     //set real to 0 for evey value
    void ImaginaryNumber::setReal(const int & newReal){
        real = 0;
        z = calculateMagnitude();
    } 

    //getter
    //----------------------------------------------------------------------------//
    int ImaginaryNumber::getImObjCount(){
        return imObjCount;
    }

    //----------------------------------------------------------------------------//
    void ImaginaryNumber::output()const{
        cout.setf( ios:: fixed);
        cout.setf( ios:: showpoint);
        cout.precision(3);
        
        cout<< getIm()<< getImRep()<<endl;
    }
    
    //----------------------------------------------------------------------------//
    void ImaginaryNumber::input(){
        cout<<"Enter your imaginary number."<<endl;
        cin>>im;
        z = calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
    ostream& operator <<(ostream& outStream,const ImaginaryNumber& other){
        outStream.setf( ios:: fixed);
        outStream.setf( ios::showpoint);
        outStream.precision(3);
        
        outStream << other.getIm()<< other.getImRep();
        
        return outStream;
    }
    
    //----------------------------------------------------------------------------//
    const ImaginaryNumber ImaginaryNumber::operator +(const ImaginaryNumber& other)const{
        ImaginaryNumber result;
        
        result.setIm( this->getIm() + other.getIm() );
        
        return result;
    }
    
    //----------------------------------------------------------------------------//
    const ImaginaryNumber ImaginaryNumber::operator -(const ImaginaryNumber& other)const{
        ImaginaryNumber result;
        
        result.setIm( this->getIm() - other.getIm() );
        
        return result;
    }
    
    //----------------------------------------------------------------------------//
    bool ImaginaryNumber::operator< (const ImaginaryNumber& other)const{
        if( this->getIm() < other.getIm() )
            return true;
        return false;
    }

}//sevgiborazan
