//This is the implementation for the class RationalNumber.
//This is the file RationalNumber.cpp.
//The interface for the class RationalNumber is in the header file RationalNumber.h.


#include "RationalNumber.h"

using std ::cerr;
using std ::endl;
using std ::cout;
using std ::cin;
using std ::ios;

namespace sevgiborazan{

    //initialize the static member
    int RationalNumber::rationalObjCount = 0;
    
    //----------------------------------------------------------------------------//
    //Constructors
    RationalNumber::RationalNumber(): RealNumber(){
        rationalObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    RationalNumber::RationalNumber(const int& newNum):RealNumber(newNum){
        rationalObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    RationalNumber::RationalNumber(const int& newNum, const int &newDenum):RealNumber(newNum,newDenum){
        rationalObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    RationalNumber::~RationalNumber(){
        rationalObjCount--;
    }

    //----------------------------------------------------------------------------//
    //getter
    int RationalNumber::getRationalObjCount(){
        return rationalObjCount;
    }

    //----------------------------------------------------------------------------//
    void RationalNumber::output()const{
        if( getDenum() != 1)
            cout<<"( "<<getNum()<<"/"<<getDenum()<<" )"<<endl;
        else
            cout<<"( "<< getNum() <<" )";
    }
   
    //----------------------------------------------------------------------------//
    void RationalNumber::input(){
        char inp[20];
        int tempNum, tempDenum;
        char ch;
        cout<<"Enter a rational number as a/b"<<endl;
        cin>>inp;
        
        sscanf (inp,"%d %c %d", &tempNum ,&ch,&tempDenum);
        setNum(tempNum);
        setDenum(tempDenum);
        
    }

    //----------------------------------------------------------------------------//
    ostream& operator <<(ostream& outStream,const RationalNumber& other){
        if( other.getDenum() != 1)
            outStream<<"( "<<other.getNum()<<"/"<<other.getDenum()<<" )";
        else
            outStream<<"( "<<other.getNum()<<" )";
        
        return outStream;
    }
    
    //----------------------------------------------------------------------------//
    const RationalNumber RationalNumber::operator +(const RationalNumber& other)const{
        RationalNumber result;
        
        result.num = ( this->getNum() * other.getDenum() ) + ( other.getNum() * this->getDenum() );
        result.setDenum( this->getDenum() * other.getDenum() );
                
        return result;
    }
    
    //----------------------------------------------------------------------------//
    const RationalNumber RationalNumber::operator -(const RationalNumber& other)const{
        RationalNumber result;
        
        result.num = ( this->getNum() * other.getDenum() ) - ( other.getNum() * this->getDenum() );
        result.setDenum( this->getDenum() * other.getDenum() );
                
        return result;
    }
    
    //----------------------------------------------------------------------------//
    bool RationalNumber::operator< (const RationalNumber& other)const{
        if( this->getZ() < other.getZ() )
            return true;
        return false;
    }

}//sevgiborazan