/* 
 * File:   main.cpp
 * Author: sevgiborazan
 *
 * Created on 08 Kasim 2015 Pazar, 00:17
 */

#include <cstdlib>
#include "Cell.h"
#include "Reversi.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    Reversi r0,r1("table1.txt"),r2("table2.txt"),r3("table4.txt"),r4("table5.txt"),r5(12,8);
    bool flag0 =false, flag1= false, flag2 =false, flag3=false,flag4=false,flag5=false;
    
    while(1){
       
        if(r0.isFinish() && !flag0){
            cout<<"         GAME 1 is END"<<endl;
            r0.displayScore();
            
            r0.compare(r5);
            flag0 = true;
        }else if(!flag0){
            cout<<endl<<endl<<"         GAME 1"<<endl;
            r0.displayBoardOnScreen();
            r0.playGame();
        }
        
        if(r1.isFinish() && !flag1){
            cout<<"         GAME 2 is END"<<endl;
            r1.displayScore();
            r1.compare(r5);
            flag1 = true;
        }else if(!flag1){
            cout<<endl<<endl<<"         GAME 2"<<endl;
            r1.displayBoardOnScreen();
            r1.playGame();
        }
        
        if(r2.isFinish() && !flag2){
            cout<<"         GAME 3 is END"<<endl;
            r2.compare(r3);
            r2.displayScore();
            flag2 = true;
        }else if(!flag2){
            cout<<endl<<endl<<"         GAME 3"<<endl;
            r2.displayBoardOnScreen();
            r2.playGame();
        }
        
        if(r3.isFinish() && !flag3){
            cout<<"         GAME 1 is END"<<endl;
            r3.displayScore();
            r3.compare(r4);
            flag3 = true;
        }else if(!flag3){
            cout<<endl<<endl<<"         GAME 4"<<endl;
            r3.displayBoardOnScreen();
            r3.playGame();
        }
        
        if(r4.isFinish() && !flag4){
            cout<<"         GAME 5 is END"<<endl;
            r4.displayScore();
            r4.compare(r5);
            flag4 = true;
        }else if(!flag4){
            cout<<endl<<endl<<"         GAME 5"<<endl;
            r4.displayBoardOnScreen();
            r4.playGame();
        }
        
        if(r5.isFinish() && !flag5){
            cout<<endl<<endl<<"         GAME 6 is END"<<endl;
            r5.displayScore();
            r5.compare(r3);
            flag5 = true;
        }else if(!flag5){
            cout<<"         GAME 6"<<endl;
            r5.displayBoardOnScreen();
            r5.playGame();
        }
        
                 
    }
    
    return 0;
}

