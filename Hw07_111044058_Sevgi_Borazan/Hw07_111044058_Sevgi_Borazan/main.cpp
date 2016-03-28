/* 
 * File:   main.cpp
 * Author: sevgiborazan
 *
 * Created on 12 Aralik 2015 Cumartesi, 13:46
 */

#include <cstdlib>

#include "Numbers.h"
#include "ComplexNumber.h"
#include "ImaginaryNumber.h"
#include "IntegerNumber.h"
#include "IrrationalNumber.h"
#include "NaturalNumber.h"
#include "RationalNumber.h"
#include "RealNumber.h"

using std:: cout;
using std:: endl;
using namespace sevgiborazan;
/*
 * 
 */


int main(int argc, char** argv) {

    test();
    
    cout<<"\n\nAfter test function "<<endl;
    cout<<"Total numbers count          : "<<Numbers::getNumbersObjCount()<<endl;
    cout<<"Total complex number count   : "<<ComplexNumber::getComplexObjCount()<<endl;
    cout<<"Total real number count      : "<<RealNumber::getRealObjCount()<<endl;
    cout<<"Toral imaginary number count : "<< ImaginaryNumber::getImObjCount()<<endl;
    cout<<"Total rational number count  : "<<RationalNumber::getRationalObjCount()<<endl;
    cout<<"Total integer number count   : "<<IntegerNumber::getIntObjCount()<<endl;
    cout<<"Total natural number count   : "<<NaturalNumber::getNaturalObjCount()<<endl;
    cout<<"Total irrational number count: "<< Irrational::getIrratObjCount()<<endl;
       
    return 0;
}

