//This is the implementation for the class TextType.
//This is the file Executable.cpp.
//The interface for the class TextType is in the header file TextType.h.


#include <iostream>
#include <string>
#include "TextType.h"


using std :: cout;
using std :: cerr;
using std :: endl;
using std :: cin;

namespace sevgiborazan{
    
    //----------------------------------------------------------------------------//
    //Constructors
    TextType::TextType(): File(){
        type = "txt";
    }
    
    //----------------------------------------------------------------------------//
    TextType::TextType(const string& newFName): File( newFName ){
        type = "txt";
    }
    
    //----------------------------------------------------------------------------//
    TextType::TextType(const string& newFName, const string& newFOwner): File( newFName, newFOwner ) {
        type = "txt";
    }
    
    //----------------------------------------------------------------------------//
    TextType::TextType(const string& newFName, const string& newFOwner, const string& newFModTime )
        :File( newFName, newFOwner,newFModTime ){
        type = "txt";
    }
    
    //----------------------------------------------------------------------------//
    TextType::TextType(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize )
        :File( newFName, newFName, newFModTime ,newFSize ){
        type = "txt";
    }
    
    //----------------------------------------------------------------------------//
    TextType::TextType(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize,const string & newType)
        :File( newFName, newFName, newFModTime ,newFSize ){
        setType( newType );
    }

    //----------------------------------------------------------------------------//
    //Destructor
    TextType::~TextType(){
    
    }

    //----------------------------------------------------------------------------//
    //virtual functions inherited from base class will be implemented
    void TextType::ls()const{
        if( this->getFName()[0] != '.')
            cout<< this->getFName()<< endl;
    } 

    //----------------------------------------------------------------------------//
    void TextType::ls(const string& lsMode)const{
        cout<< this->getFName()<< endl;
    }
    
    //----------------------------------------------------------------------------//
    File& TextType::cd(const File & other)const{
        
        TextType* fptr = new TextType;
        fptr = NULL;
        return *fptr;
    }
    
    //----------------------------------------------------------------------------//
    bool TextType::cp( const File& other){
        return false;
    }

}//sevgiborazan
