//This is the implementation for the class RationalNumber.
//This is the file RationalNumber.cpp.
//The interface for the class RationalNumber is in the header file RationalNumber.h.

#include "IrrationalNumber.h"

using std ::cerr;
using std ::endl;
using std ::cout;
using std ::cin;
using std ::ios;

namespace sevgiborazan{
    
    //----------------------------------------------------------------------------//
    //initialize static data member
    int Irrational::irratObjCount = 0;
    
    //----------------------------------------------------------------------------//
    //Constructors
    Irrational::Irrational():RealNumber(){
        irratObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    Irrational::~Irrational(){
        irratObjCount--;
    }

    //----------------------------------------------------------------------------//
    //getter
    int Irrational::getIrratObjCount(){
        return irratObjCount;
    }

    //----------------------------------------------------------------------------//
    double Irrational::getPi(){
        return PI;
    }
    
    //----------------------------------------------------------------------------//
    double Irrational::getE(){
        return e;
    }
    
    //----------------------------------------------------------------------------//
    void Irrational::output()const{
        cout<<"Irrational object has PI and square root. "<<endl;
        cout<<"PI: "<<getPi()<<endl;
        cout<<"e: "<<getE()<<" ";
    }
    
    //----------------------------------------------------------------------------//
    void Irrational::input(){
        cout<<"Irratinal class can not take any input, everything is const static member."<<endl;
    }

    //----------------------------------------------------------------------------//
    ostream& operator <<(ostream& outStream,const Irrational& other){
        outStream<<"Irrational object has PI and square root. "<<endl;
        outStream<< "PI: "<<Irrational::getPi()<<endl;
        outStream<<"e: "<<Irrational::getE()<<" ";
        return outStream;
    }
    
    //----------------------------------------------------------------------------//
    const Irrational Irrational::operator +(const Irrational& other)const{
        Irrational temp;
        cout<<"Irrational class can not implement operator +"<<endl;
        return temp;
    }
    
    //----------------------------------------------------------------------------//
    const Irrational Irrational::operator -(const Irrational& other)const{
        Irrational temp;
        cout<<"Irrational class can not implement operator -"<<endl;
        return temp;
    }
    
    //----------------------------------------------------------------------------//
    bool Irrational::operator< (const Irrational& other)const{
        cout<<"Irrational class can not implement operator <"<<endl;
        return false;
    }


}//sevgiborazan

