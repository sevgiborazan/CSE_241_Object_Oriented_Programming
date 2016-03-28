//This is the implementation for the class File.
//This is the file File.cpp.
//The interface for the class File is in the header file File.h.


#include <iostream>
#include <string>
#include "File.h"
#include "Directory.h"
#include "Executable.h"
#include "TextType.h"

using std :: cerr;
using std :: endl;
using std :: cout;

namespace sevgiborazan{

    //----------------------------------------------------------------------------//
    void test(){
    
        Executable myex("hw8.exe"),ex("hw7.exe");
        TextType asd("asd.txt"), text1;
        Directory myDir("myDir","sevgiborazan");
        Directory dir1 ("CSE241");
        Directory dir("sevgi","sevgiborazan");
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"asd is a TextType object."<<endl<<"Testing for cp with asd and another text file"<<endl;
        if( !asd.cp(text1) )
            cout<<"Text file can not copy to another text File!"<<endl;
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"asd is a TextType object."<<endl<<"Testing for ls command with asd"<<endl;
        asd.ls();
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"myex is a Executable object."<<endl<< "The myex's compiler is: "<<myex.getCompiler()<<endl;
        cout<<"Testing for cp with asd and another executable file"<<endl;
        if( !myex.cp( ex ) )
            cout<<"Executable file can not copy to another executable File!"<<endl;
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"myex is a Executable object."<<endl<<"Testing for ls command with myex"<<endl;
        myex.ls();
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"Copying something to /CSE241"<<endl;
        dir1.cp( asd );
        dir1.cp( myex);
        dir1.cp(text1);        
        dir1.cp( dir );
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"Copying something to /myDir"<<endl;
        myDir.cp(dir);
        myDir.cp(dir1);
        myDir.cp(myex);
        myDir.cp(asd);
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"/myDir ls"<<endl;
        myDir.ls();        
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"Create new Directory in /myDir"<<endl;
        myDir.newDir();
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"/myDir ls -R"<<endl;
        myDir.ls("-R");
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"/myDir ls -l"<<endl;
        myDir.ls("-l");
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"/myDir ls -Rl"<<endl;
        myDir.ls("-Rl");
        
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"/myDir ls -Ral"<<endl;
        myDir.ls("-Ral");
    }
    
    //----------------------------------------------------------------------------//
    //Constructors
    File::File(){
        fName = "Unnamed File";
        fOwner = "root";
        fModifyTime = "7.12.2015" ;
        fPath = "/Unnamed File";
        fSize = 0;
        permission = "-rwx";
    }
    
    //----------------------------------------------------------------------------//
    File::File(const string& newFName){
        fName = newFName;
        fOwner = "root";
        fModifyTime = "7.12.2015";
        fPath = "/" + fName;
        fSize = 0;
        permission = "-rwx";
    }
    
    //----------------------------------------------------------------------------//
    File::File(const string& newFName, const string& newFOwner){
        fName = newFName;
        fOwner = newFOwner;
        fModifyTime = "7.12.2015" ;
        fPath = "/" + fName;
        fSize = 0;
        permission = "-rwx";
    }
    
    //----------------------------------------------------------------------------//
    File::File(const string& newFName, const string& newFOwner, const string& newFModTime ){
        fName = newFName;
        fOwner = newFOwner;
        fModifyTime = newFModTime;
        fPath = "/" + fName;
        fSize = 0;
        permission = "-rwx";
    }
    
    //----------------------------------------------------------------------------//
    File::File(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize ){
        fName = newFName;
        fOwner = newFOwner;
        fModifyTime = newFModTime;
        fPath = "/" + fName;
        fSize = newFSize;
        permission = "-rwx";
    }
    
    //----------------------------------------------------------------------------//
    File::~File(){
    
    }

    //----------------------------------------------------------------------------//
    //setters
    void File::setFName(const string& newFName){
        fName = newFName;
    }
    
    //----------------------------------------------------------------------------//
    void File::setFOwner(const string& newFOwner){
        fOwner = newFOwner;
    }
    
    //----------------------------------------------------------------------------//
    void File::setFModifyTime(const string& newFModTime){
        fModifyTime = newFModTime;
    }
    
    //----------------------------------------------------------------------------//
    void File::setFSize( const int& newFSize){
        if( newFSize < 0){
            cerr<<"File Size can not be negative."<<endl;
            fSize = 0;
        }
        else
            fSize = newFSize;
    }

  
}//sevgiborazan
