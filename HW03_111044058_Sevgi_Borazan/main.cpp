/* 
 * File:   main.cpp
 * Author: sevgiborazan
 *
 * Created on 18 Ekim 2015 Pazar, 14:17
 */

/********************************************************************************/
/* 				 Sevgi BORAZAN 111044058                        */
/*                                       HW3                                    */
/*                                  Triangle Class                              */
/*                                                                              */
/********************************************************************************/

#include "Triangle.h"

using namespace std;


//Parametre olarak gelen triangle objeleri ile kendi icerisinde bazi hesaplamalar
//yaparak Triangle Class'i test edilir.
void testCallByValue( const Triangle t1, const Triangle t2);

///////////////////////////////////////////////////////////////////////////////

//Parametre olarak gelen triangle objeleri ile kendi icerisinde bazi hesaplamalar
//yaparak Triangle Class'i test edilir.
void testCallByReference(const Triangle& t1, const Triangle& t2);

/*
 * 
 */
int main(int argc, char** argv) {

	//Farkli sekillerde triangle objeleri olusturulur. Constructor kullanarak ya da
	//setter metotlari araciligi ile
	Triangle tObj1, tObj2(3.0,4.0,5.0);

	char ch;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout<<"Initialize a Triangle object"<<endl;
	tObj1.input();

	cout<<"Enter a key and start test call by value."<<endl;
	cin>>ch;

	testCallByValue( tObj1, tObj2 );

	cout<<"Enter a key and start test call by reference."<<endl;
	cin>>ch;

	testCallByReference( tObj1, tObj2 );

	cout<<"Set the objects and testing again"<<endl<<endl;

	cout<<"Re Initialize First object"<<endl;
	tObj1.input();
	cout<<"Re Initialize Second object"<<endl;
	tObj2.input();

	cout<<"Enter a key and start test call by value."<<endl;
	cin>>ch;

	testCallByValue( tObj1, tObj2 );

	cout<<"Enter a key and start test call by reference."<<endl;
	cin>>ch;

	testCallByReference( tObj1, tObj2 );
	

    return 0;
}

