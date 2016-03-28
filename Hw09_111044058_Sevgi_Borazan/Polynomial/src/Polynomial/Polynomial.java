/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Polynomial;

import static java.lang.Math.pow;

/**
 *
 * @author sevgiborazan
 */


public class Polynomial {
    
    /** coefficients data field*/
    private final double [] coefficients;
    
    
    /**
     * no parameter constructor
     */
    public Polynomial(){
    
        /** create and initialize the data field*/
        coefficients = new double [5];
        
        for( int i = 0; i< coefficients.length; ++i){
            coefficients[i] = 5*i+2 ;
        }
    }
    
    /**
     * @param arr another array
     * constructor with a double array parameter
     */
    public Polynomial( double [] arr){
        
        /** get parameter length*/
        int length = arr.length;
        
        /** create coefficients and copy parameter values to array*/
        coefficients = new double [length];
        
        for( int i=0; i< coefficients.length ; ++i){
            coefficients[i] = arr[i];
        }
        
    }
    
    /**
     * @return all private coefficients
     */
    public double [] getCoefficients(){
    
        return coefficients;
    }
    
    /**
     * @param index is which coefficient
     * @param value is new coefficient value
     */
    public void setCoef( int index, double value ){
        if( index <0 || index > coefficients.length )
            System.err.println(" Invalid index format !");
        else
            coefficients[ index ] = value;
    }

    /**
     * @param index is which coefficient
     * @return value of coefficient
     */
    public double getCoef( int index){
        
       if( index <0 || index > coefficients.length ){
            System.err.println(" Invalid index format !");
            return 0;
       }
        else
           return coefficients[index];         
    }
    
    /**
     * @param x evaluate the polynomial 
     * @return result
     */
    public double evalWithX(double x){
        
        double result = 0.0;
        
        for( int i = 0; i< this.getCoefficients().length; ++i ){
             result += this.getCoef(i)* pow(x,i);
        }
        
        return result;
    }
    
    /**
     * @param other will be added to object
     * @return addition of two polynomials
     * checks if polynomial degrees are equal or not then calculates result
     */
    public Polynomial add(Polynomial other){
        
        if( this.getCoefficients().length == other.getCoefficients().length ){
            
            double [] result = new double [this.getCoefficients().length]; 
            
            for( int i=0; i< this.getCoefficients().length; ++i ){
                result[i] = this.getCoef(i) + other.getCoef(i);
            }
            
            return new Polynomial(result);
            
        }else{
            
            int index, flag;  /** kimin indexi buyuk bilmek icin flag*/
            
            if( this.getCoefficients().length > other.getCoefficients().length ){
                index = this.getCoefficients().length;
                flag =0;
            }
            else{
                index = other.getCoefficients().length;
                flag =1;
            }
            
            
            double [] result = new double [index];
            
            for(int i = index-1; i>=0; --i ){
                
                if( flag == 0 && i > other.getCoefficients().length-1 )
                    result[i] = this.getCoef(i);
                else if(flag == 1 && i > this.coefficients.length-1 )
                    result[i] = other.getCoef(i);
                else
                    result[i] = this.getCoef(i) + other.getCoef(i);
            }
            return new Polynomial(result);
        }       
    }
    
    /**
     * @param other will be added to object
     * @return substraction of two polynomials
     * checks if polynomial degrees are equal or not then calculates result
     */
    public Polynomial sub( Polynomial other ){
    
        if( this.getCoefficients().length == other.getCoefficients().length ){
            
            double [] result = new double [this.getCoefficients().length]; 
            
            for( int i=0; i< this.getCoefficients().length; ++i ){
                result[i] = this.getCoef(i) - other.getCoef(i);
            }
            
            return new Polynomial(result);
            
        }else{
            
            int index, flag ;  /** kimin indexi buyuk bilmek icin flag*/
            
            if( this.getCoefficients().length > other.getCoefficients().length ){
                index = this.getCoefficients().length;
                flag =0;
            }
            else{
                index = other.getCoefficients().length;
                flag =1;
            }
            
            
            double [] result = new double [index];
            
            for(int i = index-1; i>=0; --i ){
                
                if( flag == 0 && i > other.getCoefficients().length-1 )
                    result[i] = this.getCoef(i);
                else if(flag == 1 && i > this.getCoefficients().length-1 )
                    result[i] = -other.getCoef(i);
                else
                    result[i] = this.getCoef(i) - other.getCoef(i);
            }
            return new Polynomial(result);
        }       
    }
    
    /**
     * @param other as multiplier
     * @return result of multiply operation
     */
    public Polynomial mult( Polynomial other ){
        
        int index = this.getCoefficients().length+ other.getCoefficients().length-1;
        
        double [] result = new double [index];
        /** clear result coefficient array*/
        for(int i=0; i< index; ++i)
            result[i]=0.0;
        
        for(int i=0; i< this.getCoefficients().length; ++i){
            for( int j=0; j< other.getCoefficients().length ;++j){
                result[i+j] += this.getCoef(i)*other.getCoef(j);
            }
        }
        
        return new Polynomial(result);
    }
    
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        
        for(int i = getCoefficients().length-1; i>=0; --i ){
            if(i !=0 ){
                if (this.getCoef(i) < 0) {
                    result.append("-");
                }else if (i != this.getCoefficients().length-1){
                    result.append("+");
                }
            
                result.append( Math.abs(this.getCoef(i)) +"(x^"+ i +")");
            }
            else{
                if (this.getCoef(i) < 0) {
                    result.append("-");
                }else{
                    result.append("+");
                }
                result.append( Math.abs(this.getCoef(i)));
            }
               
        }
        result.append("\n");
        
        return result.toString();
    }

    @Override
    public boolean equals(Object obj) {
        
        if (obj == null) 
           return false;
        if (obj == this) 
           return true;
        if (!(obj instanceof Polynomial))
            return false;
        
        Polynomial other = (Polynomial)obj;
        
        if( this.getCoefficients().length != other.getCoefficients().length )
            return false;
        else{
            
            for(int i=0; i< this.getCoefficients().length ;++i){
                if( this.getCoef(i) != other.getCoef(i) )
                    return false;
            }
            return true;
        } 
    }    
    
}/** end of class Polynomial*/