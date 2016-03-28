/* 
 * File:   main.cpp
 * Author: sevgiborazan
 *
 * Created on 29 Kasim 2015 Pazar, 15:41
 */

#include <cstdlib>
#include <iostream>
#include "Reversi.h"


using namespace std;
//my namespace 
using namespace sevgiborazan;
        
/*
 * 
 */
int main(int argc, char** argv) {

    
    
    Reversi r(7,15),r1,r2("table5.txt"),r3;
    
    testCallByValue(r,r1);
    
    testCallVyReferance(r2,r3);
    
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"|                    ALL TESTS WERE SUCESSEFUL !                        |"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;

    
    
    return 0;
}

