
#include "Triangle.h"

using namespace std;

#define PI 3.14159265

////////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                                 //
///////////////////////////////////////////////////////////////////////////////


// no parameter constructor 
Triangle::Triangle(): sideA(1.0), sideB(1.0),sideC(1.0){
	/* Body is empty*/
}

///////////////////////////////////////////////////////////////////////////////

//one parameter constructor
Triangle::Triangle(const double & newA): sideA(newA),sideB(1.0),sideC(1.0){

	testSides();
}

///////////////////////////////////////////////////////////////////////////////

//two parameters constructor
Triangle::Triangle(const double & newA,const double & newB):sideA(newA),sideB(newB),sideC(1.0) {

	testSides();
}

///////////////////////////////////////////////////////////////////////////////

//three parameters constructor
Triangle::Triangle(const double & newA, const double & newB, const double & newC):sideA(newA),sideB(newB),sideC(newC){

	testSides();
}

///////////////////////////////////////////////////////////////////////////////

//getters functions
double Triangle::getSideA()const{

	return sideA;
}

double Triangle::getSideB()const{

	return sideB;
}

double Triangle::getSideC()const{

	return sideC;
}

///////////////////////////////////////////////////////////////////////////////

//setters functions
void Triangle::setSide(const double & newA, const double & newB, const double & newC){

	testSides();

	sideA = newA;
	sideB = newB;
	sideC = newC;
}

void Triangle::setSide(const double & newA, const double & newB){

	testSides();
	sideA = newA;
	sideB = newB;
}

void Triangle::setSide(const double & newA){

	testSides();
	sideA = newA;

}

void Triangle::setSideB(const double & newB){

	testSides();
	sideB = newB;
}

void Triangle::setSideC(const double & newC){

	testSides();
	sideC = newC;
}

///////////////////////////////////////////////////////////////////////////////

//Input function
void Triangle::input(){

	cout<< "Enter side A of triangle"<<endl;
	cin>> sideA;
	cout<< "Enter side B of triangle"<<endl;
	cin>> sideB;
	cout<< "Enter side C of triangle"<<endl;
	cin>> sideC;

	testSides();
}

///////////////////////////////////////////////////////////////////////////////

//output functrion
void Triangle::output()const{

	int i,j,k,n,m;
	int size = 7;

	for( i = 1; i<= size-2 ; ++i ){
		
		if( i==1){
			for( k= (size ); k>=i;k--){
				cout<< " ";
			}
			cout<<"A"<<endl;
			for( k= (size ); k>=i;k--){
				cout<< " ";
			}
			cout<<"*"<<endl;
		}

		for( k= size-1; k>=i; k--){
			cout<<" ";
		}
		cout<<"*";

		for( j= 1; j<= (2*i); ++j){
			cout<< " ";
		}
		cout<<"*"<<endl;
	}

	cout<<" B";
	for(m=1; m<= (2*size -2); m++){
		cout<<"*";
	}
	cout<<"C"<<endl;

	cout<<"|BC|="<<getSideA()<<" |AC|="<<getSideB()<<" |AB|="<<getSideC()<<endl;
	//cout<<"Angle of A = "<<angleA()<< " Angle of B = "<<angleB()<<" Angle of C = "<<angleC()<<endl;

}

///////////////////////////////////////////////////////////////////////////////

//Calculates area and returns 
//The formula is: 
// u = (a+ b+ c)/2
// area= sqrt( u * (u-a)* (u-b) * (u-c) )

double Triangle::area()const{

	double u;

	u = perimeter() /2;

	return sqrt( u* (u - getSideA() )* (u - getSideB() )* (u - getSideC() ) );
}

///////////////////////////////////////////////////////////////////////////////

//Calculates perimeter and return
//The formula is:
// perimeter= a+b+c

double Triangle::perimeter()const{

	return getSideA() +getSideB() + getSideC();
}

///////////////////////////////////////////////////////////////////////////////

// Tests the each side of a triangle
// if any side of triangle is less then equal to zero; the program will be aborted

void Triangle::testSides()const{

	if( sideA<=0 ){
		cerr<<"Side A value can not be negative or zero !"<<endl;
		exit(1);
	}
	else if(sideB<=0){
		cerr<<"Side B value can not be negative or zero !"<<endl;
		exit(1);
	}
	else if(sideC<=0){
		cerr<<"Side C value can not be negative or zero !"<<endl;
		exit(1);
	}
        else if( !(fabs(sideA -sideB)<sideC && (sideA+sideB)>sideC ) &&
                 !(fabs(sideA -sideC)<sideB && (sideA+sideC)>sideB ) &&
                 !(fabs(sideC -sideB)<sideA && (sideC+sideB)>sideA ) ){
            cerr<<"The sides are invalid they dont create a triangle! "<<endl;
            exit(1);
        }
}

///////////////////////////////////////////////////////////////////////////////

// Checks the angles of triangle and if is right triangle returns true

bool Triangle::isRightTriangle( const double &angle)const{

	if( static_cast<int> (angle) == 90 )
		return true;
	else
		return false;
}

///////////////////////////////////////////////////////////////////////////////

// Calculates angle of A corner
//The formula is:
//  cosA = ( b*b +c*c -a*a) / (2* b*c)
//  arccos( cosA) * 180/PI

double Triangle::angleA()const{

	double cosA;

	cosA = ( -(sideA*sideA) + (sideB*sideB) + (sideC *sideC) ) / (2*sideB*sideC );

	return acos( cosA) *180 /PI;
}

///////////////////////////////////////////////////////////////////////////////

// Calculates angle of B corner
//The formula is:
//  cosB = (a*a +c*c -b*b) / (2* a*c)
//  arccos( cosB) * 180/PI
double Triangle::angleB()const{

	double cosB;

	cosB = ( (sideA*sideA) - (sideB*sideB) + (sideC *sideC) ) / ( 2*sideA*sideC );

	return acos( cosB) *180 /PI;
}

///////////////////////////////////////////////////////////////////////////////

// Calculates angle of C corner
//The formula is:
//  cosC = (a*a +b*b -c*c) / (2* a*b)
//  arccos( cosC) * 180/PI

double Triangle::angleC()const{

	double cosC;

	cosC = ( (sideA*sideA) + (sideB*sideB) - (sideC *sideC) ) / ( 2*sideA*sideB );

	return acos( cosC) *180 /PI;
}

///////////////////////////////////////////////////////////////////////////////

void testCallByValue( const Triangle t1, const Triangle t2){

	//different of perimeter of triangle objects
	double diffPerimeter;
	//different of area of triangleobjects
	double diffArea;

	//Calculate difference of perimeters
	if( t1.perimeter() > t2.perimeter())
		diffPerimeter = t1.perimeter() -t2.perimeter();
	else
		diffPerimeter = t2.perimeter() -t1.perimeter();

	//Calculate difference of areas
	if( t1.area() > t2.area() )
		diffArea = t1.area()- t2.area();
	else
		diffArea = t2.area()- t1.area();

	cout<<"********************************************************************************"<<endl;
	cout<<"*                     TESTING FOR CALL BY VALUE FUNCTION                       *"<<endl;
	cout<<"********************************************************************************"<<endl;

	//Show triangle objects
	cout<< "First Triangle object is:"<<endl;
	t1.output();
	cout<<endl;
	cout<<endl<<"Second Triangle object is:"<<endl;
	t2.output();
	cout<<endl;

	//Show angels of Triangles
	cout<<"First Triangle object angles are:"<<endl;
	cout<<"Angle of A = "<<t1.angleA()<< " Angle of B = "<<t1.angleB()<<" Angle of C = "<<t1.angleC()<<endl<<endl;
	cout<<"Second Triangle object angels are:"<<endl;
	cout<<"Angle of A = "<<t2.angleA()<< " Angle of B = "<<t2.angleB()<<" Angle of C = "<<t2.angleC()<<endl<<endl;

	//Check if they are rigth triangle
	if( t1.isRightTriangle( t1.angleA() ) ) 
		cout<<"Fist object is a right triangle."<<endl<<endl;
	else if(t1.isRightTriangle( t1.angleB() ) )
		cout<<"Fist object is a right triangle."<<endl<<endl;
	else if(t1.isRightTriangle( t1.angleC() ) )
		cout<<"Fist object is a right triangle."<<endl<<endl;	
	else
		cout<<"Fist object is not a right triangle."<<endl<<endl;

	if( t2.isRightTriangle( t2.angleA() ) ) 
		cout<<"Second object is a right triangle."<<endl<<endl;
	else if(t2.isRightTriangle( t2.angleB() ) )
		cout<<"Second object is a right triangle."<<endl<<endl;
	else if(t2.isRightTriangle( t2.angleC() ) )
		cout<<"Second object is a right triangle."<<endl<<endl;	
	else
		cout<<"Second object is not a right triangle."<<endl<<endl;
		
	cout<<"First object perimeter is:"<<t1.perimeter()<<endl;
	cout<<"Second object perimeter is:"<<t2.perimeter()<<endl;

	//Show difference of area and perimeter
	cout<<"Difference of perimeters: "<<diffPerimeter<<endl<<endl;

	cout<<"First object area is:"<<t1.area()<<endl;
	cout<<"Second object area is:"<<t2.area()<<endl;
	cout<<"Difference of areas: "<<diffArea<<endl<<endl;

}

///////////////////////////////////////////////////////////////////////////////
void testCallByReference(const Triangle& t1, const Triangle& t2){


	//different of perimeter of triangle objects
	double diffPerimeter;
	//different of area of triangleobjects
	double diffArea;

	//Calculate difference of perimeters
	if( t1.perimeter() > t2.perimeter())
		diffPerimeter = t1.perimeter() -t2.perimeter();
	else
		diffPerimeter = t2.perimeter() -t1.perimeter();

	//Calculate difference of areas
	if( t1.area() > t2.area() )
		diffArea = t1.area()- t2.area();
	else
		diffArea = t2.area()- t1.area();

	cout<<"********************************************************************************"<<endl;
	cout<<"*                  TESTING FOR CALL BY VALUE REFERENCE FUNCTION                 *"<<endl;
	cout<<"********************************************************************************"<<endl;

	//Show triangle objects
	cout<< "First Triangle object is:"<<endl;
	t1.output();
	cout<<endl;
	cout<<endl<<"Second Triangle object is:"<<endl;
	t2.output();
	cout<<endl;

	//Show angels of Triangles
	cout<<"First Triangle object angles are:"<<endl;
	cout<<"Angle of A = "<<t1.angleA()<< " Angle of B = "<<t1.angleB()<<" Angle of C = "<<t1.angleC()<<endl<<endl;
	cout<<"Second Triangle object angels are:"<<endl;
	cout<<"Angle of A = "<<t2.angleA()<< " Angle of B = "<<t2.angleB()<<" Angle of C = "<<t2.angleC()<<endl<<endl;

	//Check if they are rigth triangle
	if( t1.isRightTriangle( t1.angleA() ) ) 
		cout<<"Fist object is a right triangle."<<endl<<endl;
	else if(t1.isRightTriangle( t1.angleB() ) )
		cout<<"Fist object is a right triangle."<<endl<<endl;
	else if(t1.isRightTriangle( t1.angleC() ) )
		cout<<"Fist object is a right triangle."<<endl<<endl;	
	else
		cout<<"Fist object is not a right triangle."<<endl<<endl;

	if( t2.isRightTriangle( t2.angleA() ) ) 
		cout<<"Second object is a right triangle."<<endl<<endl;
	else if(t2.isRightTriangle( t2.angleB() ) )
		cout<<"Second object is a right triangle."<<endl<<endl;
	else if(t2.isRightTriangle( t2.angleC() ) )
		cout<<"Second object is a right triangle."<<endl<<endl;	
	else
		cout<<"Second object is not a right triangle."<<endl<<endl;
	
	cout<<"First object perimeter is:"<<t1.perimeter()<<endl;
	cout<<"Second object perimeter is:"<<t2.perimeter()<<endl;

	//Show difference of area and perimeter
	cout<<"Difference of perimeters: "<<diffPerimeter<<endl<<endl;

	cout<<"First object area is:"<<t1.area()<<endl;
	cout<<"Second object area is:"<<t2.area()<<endl;
	cout<<"Difference of areas: "<<diffArea<<endl<<endl;


}