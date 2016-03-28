//This is the implementation for the class ComplexNumber.
//This is the file ComplexNumber.cpp.
//The interface for the class ComplexNumber is in the header file ComplexNumber.h.

#include "ComplexNumber.h"

using std ::cerr;
using std ::endl;
using std ::cout;
using std ::cin;
using std ::ios;

namespace sevgiborazan{
    
    //initialize the static varible
    int ComplexNumber::complexObjCount = 0;
    
    //----------------------------------------------------------------------------//
    ComplexNumber::ComplexNumber(): Numbers(), num(0), denum(1), real(0), im(0), z(0){
        complexObjCount ++;
    }
    
    //----------------------------------------------------------------------------//
    ComplexNumber::ComplexNumber(const int & newNum ): Numbers(), num(newNum), denum(1), im(0){
        real = static_cast<double>(newNum) /denum;
        z = sqrt( pow(real,2) );
        complexObjCount ++;
    }
    
    //----------------------------------------------------------------------------//
    ComplexNumber::ComplexNumber(const int & newNum ,const int &newDenum ): 
        Numbers(), num(newNum), im(0){
        
        if(newDenum == 0){
            cerr<<"Denominotor can not be zero. I assume denom is 1."<<endl;
            denum = 1;
        }else
            denum = newDenum;
        
        real = static_cast<double>(newNum) /newDenum;
        z = sqrt( pow(real,2) );
        complexObjCount ++;
        
    }
    
    //----------------------------------------------------------------------------//
    ComplexNumber::ComplexNumber(const int & newNum ,const int &newDenum ,const double &newIm ):
        Numbers(), num(newNum), im(newIm){
       
         if(newDenum == 0){
            cerr<<"Denominotor can not be zero. I assume denom is 1."<<endl;
            denum = 1;
        }else
            denum = newDenum;
         
        real = static_cast<double>(newNum) /newDenum;
        z = sqrt( pow(real,2) + pow(im,2));
        complexObjCount ++;
    
    }
    
    //----------------------------------------------------------------------------//
    ComplexNumber::~ComplexNumber(){
        complexObjCount--;
    }
    
    //----------------------------------------------------------------------------//
    int ComplexNumber::getComplexObjCount(){
        return complexObjCount;
    }
  
    //setters
    // The classes who are derived from ComplexNumber have to redifine setters.
    //----------------------------------------------------------------------------//
    void ComplexNumber::setNum(const int &newNum){
        num = newNum;
        real = static_cast<double>(num)/ denum;
        z = calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
    void ComplexNumber::setDenum(const int &newDenum){
        if(denum == 0){
            cerr<<"Denominotor can not be zero."<<endl;
            exit(1);
        }
        denum = newDenum;
        real = static_cast<double>(num)/ denum;
        z = calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
    void ComplexNumber::setIm(const double &newIm){
        im = newIm;
        z = calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
    void ComplexNumber::setReal(const double & newReal){
        real = newReal;
        
        double temp = newReal;
        int coeff = 1;//coefficient
        
        while( !(( temp - static_cast<int>(temp) ) < epsilon && ( temp - static_cast<int>(temp) ) > -epsilon ) ){
            temp *= 10;
            coeff *= 10;            
        }
        
        denum = coeff;
        num = temp;
        z = calculateMagnitude();
    }
    
    //----------------------------------------------------------------------------//
    void ComplexNumber::output()const{
        
        cout.setf( ios:: fixed);
        cout.setf( ios:: showpoint);
        cout.precision(3);
        
        if( this->getIm() < epsilon && this->getIm()> -epsilon ){
             cout<< this->getReal()<<endl;  
        }else
            cout<<"("<< this->getReal()<<")" <<" + "<< "("<<this->getIm()<< this->getImRep()<<")"<<endl;
        
    }
    
    //----------------------------------------------------------------------------//
    void ComplexNumber::input(){
        
        int newNum, newDenum, newIm;
        cout<<"Enter numinator:"<<endl;
        cin>> newNum;
        cout<<"Enter denuminator:"<<endl;
        cin>>newDenum;
        cout<<"Enter imaginary coefficient:"<<endl;
        cin>>newIm;
        
        setNum(newNum);
        setDenum(newDenum);
        setIm(newIm);  
        
    }
    
    //----------------------------------------------------------------------------//    
    ostream& operator <<(ostream& outStream,const ComplexNumber& other){
    
        outStream.setf( ios:: fixed);
        outStream.setf( ios::showpoint);
        outStream.precision(3);
        
        if( other.getIm() < ComplexNumber::epsilon && other.getIm()> -ComplexNumber::epsilon ){
            outStream<< other.getReal();            
            return outStream;
        }
        
        outStream<< "("<<other.getReal() <<")"<<" + ("<<other.getIm()<< other.getImRep()<<")";
        return outStream;
    }
    
    //----------------------------------------------------------------------------//
    const ComplexNumber ComplexNumber::operator +(const ComplexNumber& other)const{
        
        ComplexNumber result;
        
        result.setNum (( this->getNum() * other.getDenum() ) + ( other.getNum() * this->getDenum() ) );
        result.setDenum( this->getDenum() * other.getDenum() );
        result.setReal( static_cast<double>(result.num) / result.denum );
        result.setIm( this->getIm() + other.getIm() );
        
        return result;
    }
    
    //----------------------------------------------------------------------------//
    const ComplexNumber ComplexNumber::operator -(const ComplexNumber& other)const{
        ComplexNumber result;
        
        result.setNum (( this->getNum() * other.getDenum() ) - ( other.getNum() * this->getDenum() ) );
        result.setDenum( this->getDenum() * other.getDenum() );
        result.setReal( static_cast<double>(result.num) / result.denum );
        result.setIm( this->getIm() - other.getIm() );
        
        return result;
    }
    
    //----------------------------------------------------------------------------//
    bool ComplexNumber::operator< (const ComplexNumber& other)const{
    
        if( this->getZ() < other.getZ() )
            return true;
        return false;
    }
    
    //----------------------------------------------------------------------------//
    double ComplexNumber::calculateMagnitude()const{
        return sqrt( pow( real,2 ) + pow( im,2 ) );
    }

}//sevgiborazan
