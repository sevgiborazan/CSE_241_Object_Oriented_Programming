/* 
 * File:   main.cpp
 * Author: sevgiborazan
 *
 * Created on 26 Kasim 2015 Persembe, 14:02
 */

#include <cstdlib>
#include "Cell.h"
#include "Reversi.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const static char PLAYER = 'O';
    
    Reversi r0,r1("table1.txt"),r2("table2.txt"),r3("table3.txt"),r4("table4.txt");
    bool flag0 =false, flag1= false, flag2 =false, flag3=false,flag4=false,flag5=false;
    
    int count = 0;
    
    while(1){
       
        if(r0.isFinish() && !flag0){
            cout<<"         GAME 1 is END"<<endl;
            r0.displayScore();
            if(r0.compare(r4))
                cout<<"Player of Game 1's beating Player of Game 4"<<endl;
            flag0 = true;
            
        }else if(!flag0){
            
            cout<<endl<<endl<<"         GAME 1"<<endl;
            r0.displayBoardOnScreen();
            r0.playGame();
            count ++;
            
            if( count %2 ==0){
                cout<<"I didnt enjoy your move i want to undo"<<endl;
                r0--;
                r0.playGame();
            }  
        }
        
       if(r1.isFinish() && !flag1){
            cout<<"         GAME 2 is END"<<endl;
            r1.displayScore();
            r1.compare(r4);
            flag1 = true;
        }else if(!flag1){
            cout<<endl<<endl<<"         GAME 2"<<endl;
            r1.displayBoardOnScreen();
            r1.playGame();
            
            count ++;
            
            if( count %3 ==0){
                cout<<"I want to play again you Player"<<endl;
                ++r0;
            }
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
            
            count ++;
            
            if( count %4 ==0){
                cout<<"I want to test my operator+="<<endl;
                Cell c;
                cout<<"Enter a cell coordinates"<<endl;
                cin>>c;
                c.set(PLAYER);
                r2 += c;
            }
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
            
            if( count %5 ==0){
                cout<<"I want to test my operator[]"<<endl;
                cout<<"Get to me r3[5A] if is exist"<<endl;
                r3["5A"].output();
            }
            
        }
        
        if(r4.isFinish() && !flag4){
            cout<<"         GAME 5 is END"<<endl;
            r4.displayScore();
            r4.compare(r0);
            flag4 = true;
        }else if(!flag4){
            cout<<endl<<endl<<"         GAME 5"<<endl;
            r4.displayBoardOnScreen();
            r4.playGame();
            
            if( count %6 ==0){
                cout<<"I want to test my operator()"<<endl;
                cout<<"Get to me r4(7B) if is exist"<<endl;
                r3(7,"B").output();
            }
        }
        
    }
    return 0;
}

    