/* 
 * File:   Triangle.h
 * Author: sevgiborazan
 *
 * Created on 01 Kasım 2015 Pazar, 22:15
 */


#include <cstdlib>
#include <iostream>
#include <cmath>

#ifndef TRIANGLE_H
#define	TRIANGLE_H

class Triangle{

public:
	//Constructors
	Triangle();
	Triangle(const double & newA);
	Triangle(const double & newA,const double & newB);
	Triangle(const double & newA, const double & newB, const double & newC);

	//getters function
	double getSideA()const;
	double getSideB()const;
	double getSideC()const;
        
	//setters functions
	void setSide(const double & newA,const double & newB,const double & newC);
	void setSide(const double & newA, const double & newB);
	void setSide(const double & newA);
	void setSideB(const double & newB);
	void setSideC(const double & newC);

	void input();
	void output()const;

	double area()const;
	double perimeter()const;
	bool isRightTriangle(const double &angle)const;
	double angleA()const;
	double angleB()const;
	double angleC()const;

private:
	double sideA;
	double sideB;
	double sideC;
	void testSides()const;
	
};

#endif	/* TRIANGLE_H */

