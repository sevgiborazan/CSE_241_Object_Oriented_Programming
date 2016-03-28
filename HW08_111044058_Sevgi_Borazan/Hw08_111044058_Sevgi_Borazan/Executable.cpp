//This is the implementation for the class Executable.
//This is the file Executable.cpp.
//The interface for the class Executable is in the header file Executable.h.


#include <iostream>
#include <string>
#include "Executable.h"


using std :: cout;
using std :: cerr;
using std :: endl;
using std :: cin;

namespace sevgiborazan{

    //----------------------------------------------------------------------------//
    Executable::Executable(): File(){
        
        compiler = "g++ ";
        setFSize(100);
    }
    
    //----------------------------------------------------------------------------//
    Executable::Executable(const string& newFName): File( newFName ){
        compiler = "g++ ";
        setFSize(100);
    }
    
    //----------------------------------------------------------------------------//
    Executable::Executable(const string& newFName, const string& newFOwner):File( newFName, newFOwner){
        setFSize(100);
        compiler = "g++ ";
    }
    
    //----------------------------------------------------------------------------//
    Executable::Executable(const string& newFName, const string& newFOwner, const string& newFModTime )
        :File( newFName, newFName, newFModTime ){
        setFSize(100);
        compiler = "g++ ";
    
    }
    
    //----------------------------------------------------------------------------//
    Executable::Executable(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize )
        :File( newFName, newFName, newFModTime ,newFSize){
        compiler = "g++ ";
    }
    
    //----------------------------------------------------------------------------//
    Executable::Executable(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize,const string & newComp)
        :File( newFName, newFName, newFModTime ,newFSize){
        setCompiler( newComp );
    }
    
    //----------------------------------------------------------------------------//
    Executable::~Executable(){
    
    }
    
    //----------------------------------------------------------------------------//
    void Executable::ls()const{
        if( this->getFName()[0] != '.')
            cout<< this->getFName()<< endl;
    }
    
    //----------------------------------------------------------------------------//
    void Executable::ls(const string& lsMode)const{
        cout<< this->getFName()<< endl;
    }
    
    //----------------------------------------------------------------------------//
    File& Executable::cd(const File & other)const{
        Executable* fptr = new Executable;
        fptr = NULL;
        return *fptr;
    }
    
    //----------------------------------------------------------------------------//
    bool Executable::cp( const File& other) {
        return false;
    }

}//sevgiborazan