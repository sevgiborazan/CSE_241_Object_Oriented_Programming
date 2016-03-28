//This is the implementation for the class Numbers.
//This is the file Numbers.cpp.
//The interface for the class Numbers is in the header file Numbers.h.

#include "Numbers.h"
#include "ComplexNumber.h"
#include "ImaginaryNumber.h"
#include "IntegerNumber.h"
#include "RealNumber.h"
#include "RationalNumber.h"
#include "NaturalNumber.h"
#include "IrrationalNumber.h"

using namespace std;

namespace sevgiborazan{

    //----------------------------------------------------------------------------//
    //test function for all classes
    void test(){     
        
        cout<<"Total numbers count          : " <<Numbers::getNumbersObjCount()<<endl;
        cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
        cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
        cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
        cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
        cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
        cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;
        
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"                     Testing for Complex Numbers                     "<<endl;
        cout<<"---------------------------------------------------------------------"<<endl<<endl;

        ComplexNumber a(2,5), b(3,5,2.5);

        cout<<"Complex a: "<<a<<"   Complex b: "<<b<<endl;
        cout<<"Magnitude a is: "<<a.getZ()<<endl;
        cout<<"Magnitude b is: "<<b.getZ()<<endl;
        cout<<" a + b = "<< a+b<<endl;
        cout<<" a - b = "<< a-b<<endl;
        if( a < b)
            cout<< a <<" is less than "<<b<<endl;
        else
            cout<< a <<" is grater than "<<b<<endl;
        cout<<"Total numbers count          : " <<Numbers::getNumbersObjCount()<<endl;
        cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
        cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
        cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
        cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
        cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
        cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;

        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"                      Testing for Real Numbers                        "<<endl;
        cout<<"---------------------------------------------------------------------"<<endl<<endl;

        RealNumber real1(3,8), real2(0.036);

        cout<<"Real r1: "<< real1 <<"   Real r2: "<< real2 <<endl;
        cout<<"Magnitude r1 is: "<< real1.getZ()<<endl;
        cout<<"Magnitude r2 is: "<< real2.getZ()<<endl;
        cout<<" r1 + r2 = "<< real1 + real2 <<endl;
        cout<<" r1 - r2 = "<< real1 - real2 <<endl;
        if( real1 < real2)
            cout<< real1 <<" is less than "<< real2 <<endl;
        else
            cout<< real1 <<" is grater than "<< real2 <<endl;

        cout<<"Total numbers count          : " <<Numbers::getNumbersObjCount()<<endl;
        cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
        cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
        cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
        cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
        cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
        cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;
        
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"                      Testing for Imaginary Numbers                  "<<endl;
        cout<<"---------------------------------------------------------------------"<<endl<<endl;

        ImaginaryNumber i1(3.5), i2(5);

        cout<<"Imaginary i1: "<< i1 <<"   Imaginary i2: "<< i2 <<endl;
        cout<<"Magnitude i1 is: "<< i1.getZ()<<endl;
        cout<<"Magnitude i2 is: "<< i2.getZ()<<endl;
        cout<<" i1 + i2 = "<< i1 + i2 <<endl;
        cout<<" i1 - i2 = "<< i1 - i2 <<endl;
        if( i1 < i2)
            cout<< i1 <<" is less than "<< i2 <<endl;
        else
            cout<< i1 <<" is grater than "<< i2 <<endl;

        cout<<"Total numbers count          : " <<Numbers::getNumbersObjCount()<<endl;
        cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
        cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
        cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
        cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
        cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
        cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;
        
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"                      Testing for Rational Numbers                  "<<endl;
        cout<<"---------------------------------------------------------------------"<<endl<<endl;

        RationalNumber rat1,rat2(9.9);
        rat1.input();

        cout<<"Rational rat1: "<< rat1 <<"   Rational rat2: "<< rat2 <<endl;
        cout<<"Magnitude rat1 is: "<< rat1.getZ()<<endl;
        cout<<"Magnitude rat2 is: "<< rat2.getZ()<<endl;
        cout<<" rat1 + rat2 = "<< rat1 + rat2 <<" = "<< (rat1 + rat2 ).getZ() <<endl;
        cout<<" rat1 - rat2 = "<< rat1 - rat2 <<endl;
        if( rat1 < rat2)
            cout<< rat1 <<" is less than "<< rat2 <<endl;
        else
            cout<< rat1 <<" is grater than "<< rat2 <<endl;

        cout<<"Total numbers count          : " <<Numbers::getNumbersObjCount()<<endl;
        cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
        cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
        cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
        cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
        cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
        cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;
        
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"                      Testing for Integer Numbers                  "<<endl;
        cout<<"---------------------------------------------------------------------"<<endl<<endl;

        IntegerNumber in1(1907), in2(1004);

        cout<<"Integer int1: "<< in1 <<"   Integer int2: "<< in2 <<endl;
        cout<<"Magnitude int1 is: "<< in1.getZ()<<endl;
        cout<<"Magnitude int2 is: "<< in2.getZ()<<endl;
        cout<<" int1 + int2 = "<< in1 + in2 <<endl;
        cout<<" int1 - int2 = "<< in1 - in2 <<endl;
        if( in1 < in2)
            cout<< in1 <<" is less than "<< in2 <<endl;
        else
            cout<< in1 <<" is grater than "<< in2 <<endl;

        cout<<"Total numbers count          : " <<Numbers::getNumbersObjCount()<<endl;
        cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
        cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
        cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
        cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
        cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
        cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;
        
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"                      Testing for Natural Numbers                  "<<endl;
        cout<<"---------------------------------------------------------------------"<<endl<<endl;

        NaturalNumber nat1(89), nat2;
        nat2.input();

        cout<<"Natural n1: "<< nat1 <<"   Natural n2: "<< nat2 <<endl;
        cout<<"Magnitude n1 is: "<< static_cast<int>( nat1.getZ()) <<endl;
        cout<<"Magnitude n2 is: "<< static_cast<int>( nat2.getZ())<<endl;
        cout<<" n1 + n2 = "<< nat1 + nat2 <<endl;
        cout<<" n1 - n2 = "<< nat1 - nat2 <<endl;
        if( nat1 < nat2)
            cout<< nat1 <<" is less than "<< nat2 <<endl;
        else
            cout<< nat1 <<" is grater than "<< nat2 <<endl;

        cout<<"Total numbers count          : " <<Numbers::getNumbersObjCount()<<endl;
        cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
        cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
        cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
        cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
        cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
        cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;
        
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"                      Testing for Irrational Numbers                  "<<endl;
        cout<<"---------------------------------------------------------------------"<<endl<<endl;

        Irrational irrat1;
        
        cout<<"Irrational example pi: "<< irrat1.getPi()<<endl;
        cout<<"Irrational example e: " << irrat1.getE()<<endl;
        
        cout<<irrat1<<endl;
    
        cout<<"Total numbers count          : " <<Numbers::getNumbersObjCount()<<endl;
        cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
        cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
        cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
        cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
        cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
        cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;
        
        cout<<"---------------------------------------------------------------------"<<endl<<endl;
        cout<<"a + b + r1 + r2 + i1 + i2 + int1 + int2 + n1 + n2  = "<< endl<<
                a<<" + "<<b <<" + "<< real1 <<" + "<< real2<< " + "<< i1<<" + "<<i2<<" + "<< rat1<<" + "<<rat2<<" + "<< in1<<" + "<<in2<<" + "<<nat1<<" + "<<nat2<<endl<< 
                a + b + real1 + real2 + i1 + i2 + rat1 + rat2 + in1 + in2 + nat1 + nat2<<endl;
        
        cout<<"---------------------------------------------------------------------"<<endl<<endl;
        cout<<"a - b - r1 - r2 - i1 - i2 - int1 - int2 - n1 - n2  = "<< endl<<
                a<<" - "<<b <<" - "<< real1 <<" - "<< real2<< " - "<< i1<<" - "<<i2<<" - "<< rat1<<" - "<<rat2<<" - "<< in1<<" - "<<in2<<" - "<<nat1<<" - "<<nat2<<endl<< 
                a - b - real1 - real2 - i1 - i2 - rat1 - rat2 - in1 - in2 - nat1 - nat2<<endl;

        /*cout<<r+ irrat<<endl;

        rat.input();
        cout<<"rat: "<<rat<<endl;


        /*cout<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<a<<endl<<b<<endl;
        cout<< a+b<<endl;
        if(a<b)
            cout<<"true"<<endl;
        cout<<a-b<<endl;

        cout<<"Imaginary test"<<endl;
        cout<<x<<endl<<y<<endl;
        cout<<x+y<<endl<<x-y<<endl;
        if(!(y<x) )
            cout<<"false"<<endl;
        cout<< Numbers::getNumbersObjCount()<<endl;*/

        /*cout<< b<<" + "<<r<<" + "<<rat<<" + "<<nat <<" = "<< b+r+rat+nat<<endl;
        cout<< Numbers::getNumbersObjCount()<<endl;
        cout<<ComplexNumber::getComplexObjCount()<<endl;
        cout<<RealNumber::getRealObjCount()<<endl;
        cout<<RationalNumber::getRationalObjCount()<<endl;
        cout<<IntegerNumber::getIntObjCount()<<endl;
        cout<<NaturalNumber::getNaturalObjCount()<<endl;*/


    }
    
    //initialization of static data member
    int Numbers::numbersObjCount = 0;
    
    //----------------------------------------------------------------------------//
    Numbers::Numbers(){
        numbersObjCount++;
    }
    
    //----------------------------------------------------------------------------//
    Numbers::~Numbers(){
        numbersObjCount--;
    }
    
    //----------------------------------------------------------------------------//
    int Numbers::getNumbersObjCount(){
        return numbersObjCount;
    }
}
