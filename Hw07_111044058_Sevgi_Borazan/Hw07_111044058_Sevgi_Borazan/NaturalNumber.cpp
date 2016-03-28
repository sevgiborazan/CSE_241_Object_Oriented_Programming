//This is the implementation for the class NaturalNumber.
//This is the file NaturalNumber.cpp.
//The interface for the class NaturalNumber is in the header file NaturalNumber.h.


#include "NaturalNumber.h"

using std ::cerr;
using std ::endl;
using std ::cout;
using std ::cin;
using std ::ios;

namespace sevgiborazan{

    //initialize the static data member
    int NaturalNumber::naturalObjCount = 0;
    
    //----------------------------------------------------------------------------//
    //Constructors
    NaturalNumber::NaturalNumber():IntegerNumber(){
        
        if(num < 0){
            cerr<<"Natural numbers can not be negative, Object didnt created."<<endl;
            exit(1);
        }
        
        naturalObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    NaturalNumber::NaturalNumber(const int& newNum): IntegerNumber(newNum){
        if(num < 0){
            cerr<<"Natural numbers can not be negative, Object didnt created."<<endl;
            exit(1);
        }
        
        naturalObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    NaturalNumber::~NaturalNumber(){
        naturalObjCount--;
    }

    //----------------------------------------------------------------------------//
    //set num to whatever it is if only if pozitive or zero
    void NaturalNumber::setNum(const int &newNum){
        if( newNum <0 )
            num = 0;
        else
            num = newNum;
        denum = 1;
        real = num / denum;
        z = ComplexNumber::calculateMagnitude();
    } 

    //----------------------------------------------------------------------------//
    int NaturalNumber::getNaturalObjCount(){
        return naturalObjCount;
    }

    //----------------------------------------------------------------------------//
    void NaturalNumber::output()const{
        cout<< getNum();
    }
    void NaturalNumber::input(){
        cout<<"Enter a natural number."<<endl;
        int temp;
        cin>>temp;
        if(temp <0 ){
            cerr<<"Natural numbers can not be negative,invalid input."<<endl;
            exit(1);
        }
        setNum(temp);
        //setDenum(1);
    }

    //----------------------------------------------------------------------------//
    ostream& operator <<(ostream& outStream,const NaturalNumber& other){
        outStream<< other.getNum();
        return outStream;
    }
    
    //----------------------------------------------------------------------------//
    const NaturalNumber NaturalNumber::operator +(const NaturalNumber& other)const{
        NaturalNumber result;
        
        result.num = ( this->getNum() * other.getDenum() ) + ( other.getNum() * this->getDenum() );
        result.denum = 1;
        result.z = result.calculateMagnitude();
                
        return result;
    }
    
    //----------------------------------------------------------------------------//
    const NaturalNumber NaturalNumber::operator -(const NaturalNumber& other)const{
        NaturalNumber result;
        
        result.num = ( this->getNum() * other.getDenum() ) - ( other.getNum() * this->getDenum() );
        result.denum = 1;
        result.z = result.calculateMagnitude();
                
        return result;
    }
    
    //----------------------------------------------------------------------------//
    bool NaturalNumber::operator< (const NaturalNumber& other)const{
        if( this->getZ() < other.getZ() )
            return true;
        return false;
    }

}//sevgiborazan