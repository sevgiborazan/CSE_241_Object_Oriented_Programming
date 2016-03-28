/* 
 * File:   main.cpp
 * Author: sevgiborazan
 *
 * Created on 17 Ekim 2015 Cumartesi, 15:04
 */
/********************************************************************************/
/* 			      Sevgi BORAZAN 111044058                           */
/*                                                                              */
/*                                 Function Pointer                             */
/*                                                                              */
/********************************************************************************/


#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

#define N_SIZE 50
#define ID_SIZE 10

///////////////////////////////////////////////////////////////////////////////
//                   DayOfYear and Person Classes                            //
///////////////////////////////////////////////////////////////////////////////

class DayOfYear{
    
public:
    int month;
    int day;    
};


class Person{

public:
    char name[N_SIZE];
    char surname[N_SIZE];
    char personID[ID_SIZE];
    
};

///////////////////////////////////////////////////////////////////////////////
//							Functions Prototypes							 //
///////////////////////////////////////////////////////////////////////////////

int return_mode (const void * base, size_t num, size_t size, 
					bool (* equals) (const void *, const void *));


// for integer type
// void pointer tipindeki parametrelerini int* 'a cast ederek değerleri 
//karsilastirarak esitlik kontrolu yapar
bool intEquals ( const void *int1, const void *int2);

//for double type
//void pointer tipindeki parametrelerini double* 'a cast ederek değerleri 
//karsilastirarak esitlik kontrolu yapar
bool doubleEquals ( const void *double1, const void *double2);

//for char type
//void pointer tipindeki parametrelerini char* 'a cast ederek değerleri 
//karsilastirarak esitlik kontrolu yapar
bool charEquals ( const void *ch1, const void *ch2);

//for DayOfYear type
//void pointer tipindeki parametrelerini DayOfYear* 'a cast eder day memberlarini 
//karsilastirarak esitlik kontrolu yapar
bool dofEquals ( const void *dof1, const void *dof2);

//for Person type
//void pointer tipindeki parametrelerini Person* 'a cast ederek name ve surnameleri 
//karsilastirarak esitlik kontrolu yapar
bool personEquals ( const void *p1, const void *p2);


///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

    int intArr[]= {10,20,10,20,10,5,50,15,50,10};

    char charArr[]= {'a','a','2','8','2','8','8','2','j'};
    
    double doubleArr[]= { 2.2 , 5.5 , 1.1 , 1.1 , 1.1, 5.5, 5.5};
    
    Person personArr[6];

    strcpy(personArr[0].name,"Sevgi");
    strcpy(personArr[0].surname,"BORAZAN");
    strcpy(personArr[0].personID,"111044058");

    strcpy(personArr[1].name,"Feyza");
    strcpy(personArr[1].surname,"KONUKLAR");
    strcpy(personArr[1].personID,"111024032");

    strcpy(personArr[2].name,"Tuba");
    strcpy(personArr[2].surname,"SAPMAZ");
    strcpy(personArr[2].personID,"111024016");

    strcpy(personArr[3].name,"Sevgi");
    strcpy(personArr[3].surname,"BORAZAN");
    strcpy(personArr[3].personID,"111044058");

    strcpy(personArr[4].name,"Feyza");
    strcpy(personArr[4].surname,"KONUKLAR");
    strcpy(personArr[4].personID,"111024032");

    strcpy(personArr[5].name,"Feyza");
    strcpy(personArr[5].surname,"KONUKLAR");
    strcpy(personArr[5].personID,"111024032");

    DayOfYear dofArr[8];

    dofArr[0].day = 13;
    dofArr[0].month= 11;

    dofArr[1].day = 16;
    dofArr[1].month= 11;

    dofArr[2].day = 9;
    dofArr[2].month= 12;

    dofArr[3].day = 10;
    dofArr[3].month= 4;

    dofArr[4].day = 19;
    dofArr[4].month= 7;

    dofArr[5].day = 19;
    dofArr[5].month= 7;

    dofArr[6].day = 10;
    dofArr[6].month= 4;

    dofArr[7].day = 21;
    dofArr[7].month= 11;

    cout<<"********************************************************************************"<<endl;
    cout<< "*                       TEST FOR AN INTEGER ARRAY                             *"<<endl;
    cout<<"********************************************************************************"<<endl;
    
    cout<<"The array is:"<<endl;
    for(int i=0; i<10; ++i){
        cout<<intArr[i]<<" ";
    }
    cout<<endl;
    
    cout<< "Return Mode Index: "<< return_mode( intArr, 10, sizeof(int), intEquals )<<endl;
    
    cout<<"********************************************************************************"<<endl;
    cout<< "*                       TEST FOR A CHARACHTER ARRAY                           *"<<endl;
    cout<<"********************************************************************************"<<endl;

    cout<<"The array is:"<<endl;
    for(int i=0; i<9; ++i){
        cout<<charArr[i]<<" ";
    }

    cout<<endl;
    
    cout<< "Return Mode Index: "<<return_mode( charArr, 9, sizeof(char), charEquals )<<endl;
    
    cout<<"********************************************************************************"<<endl;
    cout<< "*                       TEST FOR A DOUBLE ARRAY                               *"<<endl;
    cout<<"********************************************************************************"<<endl;
    
    cout<<"The array is:"<<endl;
    for(int i=0; i<7; ++i){
        cout<<doubleArr[i]<<" ";
    }

    cout<<endl;
    
    cout<< "Return Mode Index: "<<return_mode( doubleArr, 7, sizeof(double), doubleEquals )<<endl;

    cout<<"********************************************************************************"<<endl;
    cout<< "*                       TEST FOR A PERSON ARRAY                               *"<<endl;
    cout<<"********************************************************************************"<<endl;
    
    cout<<"The array is:"<<endl;
    for(int i=0; i<6; ++i){
        cout<<personArr[i].name<<" "<<personArr[i].surname<<" "<<personArr[i].personID<<endl;
    }
    
    cout<< "Return Mode Index: "<<return_mode( personArr, 6, sizeof(Person), personEquals )<<endl;
    
    cout<<"********************************************************************************"<<endl;
    cout<< "*                       TEST FOR A DAY OF YEAR ARRAY                          *"<<endl;
    cout<<"********************************************************************************"<<endl;
   
    cout<<"The array is:"<<endl;
    for(int i=0; i<8; ++i){
        cout<<dofArr[i].month<<"/"<<dofArr[i].day<<endl;
    }
    
    cout<< "Return Mode Index: "<<return_mode( dofArr, 8, sizeof(DayOfYear), dofEquals )<<endl;



    return 0;
}

///////////////////////////////////////////////////////////////////////////////

bool intEquals ( const void *int1, const void *int2){

	const int *num1, *num2;

	num1 = static_cast<const int*> (int1);
	num2 = static_cast<const int*> (int2);

	if( *num1 == *num2)
		return true;
	else
		return false;
	
}

///////////////////////////////////////////////////////////////////////////////

bool doubleEquals ( const void *double1, const void *double2){

	const double *num1,*num2;

	num1 = static_cast<const double*> (double1);
	num2 = static_cast<const double*> (double2);

	if( *num1 == *num2)
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////

bool charEquals ( const void *ch1, const void *ch2){

	const char *char1,*char2;

	char1 = static_cast<const char*> (ch1);
	char2 = static_cast<const char*> (ch2);

	if( *char1 == *char2)
		return true;
	else
		return false;

}

///////////////////////////////////////////////////////////////////////////////

bool dofEquals ( const void *dof1, const void *dof2){

	const DayOfYear *dofObj1,*dofObj2;

	dofObj1 = static_cast<const DayOfYear*> (dof1);
	dofObj2 = static_cast<const DayOfYear*> (dof2);

	if( (dofObj1->day == dofObj2->day) && ( dofObj1 ->month == dofObj2->month ))
		return true;
	else
		return false;	 
}

///////////////////////////////////////////////////////////////////////////////

bool personEquals ( const void *p1, const void *p2){

	const Person *pObj1,*pObj2;

	pObj1 = static_cast<const Person*> (p1);
	pObj2 = static_cast<const Person*> (p2);

	if( strcmp(pObj1->name, pObj2->name) == 0 && 
		strcmp(pObj1->surname, pObj2->surname) == 0 &&
		strcmp(pObj1->personID, pObj2->personID)== 0 ){
		
		return true;
	}
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////


// base : array baslangic adresi,
// num : array size'i
// size : bir eleman kac byte
int return_mode (const void * base, size_t num, size_t size, 
					bool (* equals) (const void *, const void *)){

	//base arrayinin baslangic adresi
	unsigned char *start = (unsigned char*) (base);

	// base arrayinin toplam byte'i
	unsigned char *end = start +	(size * num);

	int k=0,
		returnVal=0,
		maxOccur=0,
		current =1;	//array'deki bir elemanin tekrar sayisi
	
	//tum elemanlarin  occurence sayilarini bulan dongu
	for( unsigned char *i= start; i < end; i += size ){
		for( unsigned char *j= i+size; j< end ; j +=size ){
			if( equals( i , j) ){
				current += 1;
			}			
		}
		//en cok hangi indexteki elemanin tekrar ettigini kiyaslama ve return value ya karar verme
		if( current >maxOccur){
			maxOccur = current ;
			returnVal = k;
		}
		//update current and k(index)
		current =1;
		k+=1;

	}

	return returnVal;
}
