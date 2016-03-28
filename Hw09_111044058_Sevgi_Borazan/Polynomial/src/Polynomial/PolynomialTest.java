package Polynomial;

import java.util.Locale;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sevgiborazan
 */
public class PolynomialTest {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /* TODO code application logic here*/
        
        /** create an object with no parameter constructor*/
        Polynomial a = new Polynomial();
        
        int degree;
        
        Scanner input = new Scanner( System.in ).useLocale(Locale.US);
        System.out.println("Enter the degree of polynomial.");
        
        /** get the degree of polynomial*/
        degree = input.nextInt();
        while(degree < 0){
            System.err.println("Invalid degree.");
            degree = input.nextInt();
        }
       
            
        
        double [] array = new double [degree+1];
        
        for(int i= 0; i< degree+1; ++i){
            System.out.printf("Enter the %d. coefficient of polynomial.\n",i);
            array[i] = input.nextDouble();            
        }
        
        /** create second polynomial object*/
        Polynomial b = new Polynomial(array);
        
        /** Show polynomials*/
        System.out.println("a(x) = "+ a);
        System.out.println("b(x) = "+ b);
        
        if( a.equals(b) )
            System.out.println("a(x) and b(x) are equal.\n");
        else
            System.out.println("a(x) and b(x) are not equal.\n");            
        
        /** test methods*/
        System.out.println("(a+b)(x) = " + a.add(b));
        System.out.println("(a-b)(x) = " + a.sub(b));
        System.out.println("(a*b)(x) = " + a.mult(b));
        
        System.out.println("Enter an x value and calculates polynomials with a and b.");
        double x;
        x = input.nextDouble();
        System.out.printf("a(%f) = %f\n",x, a.evalWithX(x));
        System.out.printf("b(%f) = %f\n",x, b.evalWithX(x));        
        System.out.printf("(a+b)(%f) = %f\n",x, a.add(b).evalWithX(x));
        System.out.printf("(a-b)(%f) = %f\n",x, a.sub(b).evalWithX(x));
        System.out.printf("(a*b)(%f) = %f\n",x, a.mult(b).evalWithX(x));
        
    }/** end of main */

}/** end of class*/
