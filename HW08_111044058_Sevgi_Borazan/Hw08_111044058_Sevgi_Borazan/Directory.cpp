//This is the implementation for the class Directory.
//This is the file Directory.cpp.
//The interface for the class Directory is in the header file Directory.h.


#include <iostream>
#include <string>
#include <vector>
#include "Directory.h"
#include "Executable.h"
#include "TextType.h"


using std :: iterator;
using std :: cout;
using std :: cerr;
using std :: endl;
using std :: cin;
using std :: vector;
using sevgiborazan :: Executable;
using sevgiborazan :: TextType;

namespace sevgiborazan{
    
    //----------------------------------------------------------------------------//
    //constructors
    Directory::Directory(){
        
        setFName( "Unnamed Directory" );
        setFOwner( "- rw- root" );
        setFModifyTime( "7.12.2015" );
        setFPath( "/Unnamed Directory");
        setFSize( 0 );
        numOfFile = 0;
        memberFiles.push_back( this );
    }
    
    //----------------------------------------------------------------------------//
    Directory::Directory(const string& newDirName){
        setFName( newDirName );
        setFOwner( "- rw- root" );
        setFModifyTime( "7.12.2015" );
        setFPath( "/" + newDirName );
        setFSize( 0 );
        numOfFile = 0;
        memberFiles.push_back( this );
    }
    
    //----------------------------------------------------------------------------//
    Directory::Directory(const string& newDirName, const string& newDirOwner){
        setFName( newDirName );
        setFOwner( newDirOwner );
        setFModifyTime( "7.12.2015");
        setFPath( "/" + newDirName );
        setFSize( 0 );
        numOfFile = 0;
        memberFiles.push_back( this );
    }
    
    //----------------------------------------------------------------------------//
    Directory::Directory(const string& newDirName, const string& newDirOwner, const string& newDirModTime){
        setFName( newDirName );
        setFOwner( newDirOwner );
        setFModifyTime( newDirModTime );
        setFPath( "/" + newDirName );
        setFSize( 0 );
        numOfFile = 0;
        memberFiles.push_back( this );
    }
    
    //----------------------------------------------------------------------------//
    Directory::Directory(const string& newDirName, const string& newDirOwner, const string& newDirModTime, const int& newDirSize){
        setFName( newDirName );
        setFOwner( newDirOwner );
        setFModifyTime( newDirModTime );
        setFPath( "/" + newDirName );
        setFSize( newDirSize );
        if( getFSize() > 0 )
            numOfFile = 1;  // en az bir tane file olmali
        else
            numOfFile = 0;
        
        memberFiles.push_back( this );
    }

    //----------------------------------------------------------------------------//
    //Destructor
    Directory::~Directory(){
        for(int i=0; i< memberFiles.size(); ++i)
            memberFiles.pop_back();
    }

    //----------------------------------------------------------------------------//
    void Directory::ls()const{
        
        for(int i = 0; i< memberFiles.size(); ++i){
            if( memberFiles[i]->getFName()[0] != '.')
                cout<<memberFiles[i]->getFName()<<endl;
        }
    }  
    
    //----------------------------------------------------------------------------//
    //Istenilen ls mode'a gore klasor icerisindekileri listeler.
    //Gerekli durumda recusrive olarak directoryleri dolasir.
    void Directory::ls(const string& lsMode)const{
        for( int i=0; i< memberFiles.size(); ++i ){
           
            if( (dynamic_cast<const Directory*> ( memberFiles[i]) ) != NULL ){
               
                if( lsMode == "-l" || lsMode == "-Rl" ){
                    if( memberFiles[i]->getFName()[0] != '.' ){
                        cout<< memberFiles[i]->getPermission() <<" "<< memberFiles[i]->getFOwner() <<" "<< memberFiles[i]->getFOwner() 
                            << " "<< memberFiles[i]->getFSize() <<" "<< memberFiles[i]->getFModifyTime() <<" "<< memberFiles[i]->getFName() <<endl;
                    }
                }
                else if( lsMode == "-a" ){
                    cout<< memberFiles[i]->getFName()<< endl;
                }
                else if( lsMode == "-la" || lsMode == "-al"){
                    cout<< memberFiles[i]->getPermission() <<" "<< memberFiles[i]->getFOwner() <<" "<< memberFiles[i]->getFOwner() 
                        << " "<< memberFiles[i]->getFSize() <<" "<< memberFiles[i]->getFModifyTime() <<" "<< memberFiles[i]->getFName() <<endl;
                }
                else if( lsMode == "-R" || lsMode == "-Ra" || lsMode == "-aR" ){
                   if( memberFiles[i]->getFName()[0] == '.')
                        cout<<".:"<<endl;
                    cout<< memberFiles[i]->getFName()<<endl;
                       
                }
                else if( lsMode == "-Ral" || lsMode =="-Rla" || lsMode =="-lRa" || lsMode == "-laR" || lsMode == "-aRl" || lsMode =="-alR" ){
                    cout<< memberFiles[i]->getPermission() <<" "<< memberFiles[i]->getFOwner() <<" "<< memberFiles[i]->getFOwner() 
                        << " "<< memberFiles[i]->getFSize() <<" "<< memberFiles[i]->getFModifyTime() <<" "<< memberFiles[i]->getFName() <<endl;
                }
                else
                    cerr<<"Undefined ls mode"<<endl;
                
            }
            else {               
                if( lsMode[1] == 'R' || lsMode[2]=='R' || lsMode[3]=='R'  ){
                    memberFiles[i]->ls( lsMode );
                    cout<<".." <<memberFiles[i]->getFPath()<<endl;
                }
                else
                    cout<< memberFiles[i]->getFName();
            }
        }
    
    }
    
    //----------------------------------------------------------------------------//
    //Directory icerindeki acilmak istenilen directory vector icerisinde bulunur ve return edilir
    File& Directory::cd(const File & other)const{
        
        if( other.isDir() ){
            for(int i = 0; i< this->memberFiles.size() ; ++i){
                if( this->memberFiles[i]->getFName() == other.getFName() )
                    return *memberFiles[i];
            }
        }  
    }
    
    //----------------------------------------------------------------------------//
    //File & olarak gelen objeyi dynamic cast yaparak hangi tip oldugunu bulur ve
    //istenilen yere kopylar. Const olarak geldigi icin uzerinde degisiklik yapilamayacagindan
    //temp objesi uzerinden gerekli set islemleri yapilir ve vector'e eklenir yani kopyalanir
    bool Directory::cp(const File& other){
        
        if( (dynamic_cast<const Directory*> (&other) ) != NULL ){
            
            const Directory *temp = dynamic_cast<const Directory*> (&other);
            Directory *willBeAdd = new Directory;
            
            willBeAdd->setFModifyTime( temp->getFModifyTime());
            
            willBeAdd->setFOwner( temp->getFOwner() );
            
            willBeAdd->setFSize( temp->getFSize() );
            
            //path de recursive olarak değiştirilecek.
            willBeAdd->setFPath( this->getFPath() + temp->getFPath());
            willBeAdd->setFName( temp->getFName() );
            
            willBeAdd->setPermission( temp->getPermission() );
            
            memberFiles.push_back( willBeAdd );
            return true;
        }
        else if( (dynamic_cast<const Executable*> (&other) ) != NULL){
            
            const Executable *temp = dynamic_cast<const Executable*> (&other);
            Executable *willBeAdd = new Executable;
            
            willBeAdd->setFModifyTime( temp->getFModifyTime());            
            willBeAdd->setFOwner( temp->getFOwner() );            
            willBeAdd->setFSize( temp->getFSize() );  
            willBeAdd->setFName( temp->getFName() );
            willBeAdd->setFPath( this->getFPath() + temp->getFPath());
            //path de recursive olarak değiştirilecek.            
            willBeAdd->setPermission( temp->getPermission() );
            
            memberFiles.push_back( willBeAdd );
            
            return true;
            
        }else if( (dynamic_cast<const TextType*> (&other) ) != NULL ){
            
            const TextType *temp = dynamic_cast<const TextType*> (&other);
            TextType *willBeAdd = new TextType;
            
            willBeAdd->setFModifyTime( temp->getFModifyTime());            
            willBeAdd->setFOwner( temp->getFOwner() );            
            willBeAdd->setFSize( temp->getFSize() ); 
            willBeAdd->setFName( temp->getFName() );
            willBeAdd->setFPath( this->getFPath() + temp->getFPath());
            //path de recursive olarak değiştirilecek.            
            willBeAdd->setPermission( temp->getPermission() );
            
            memberFiles.push_back( willBeAdd );
            
            return true;
            
        }else 
            return false;
    }
    
    //----------------------------------------------------------------------------//
    //creates sub directory in a directory
    const File& Directory::newDir(){
        Directory* newD = new Directory;
        
        string name, date;
        cout<<"Enter new Directory Name:"<<endl;
        cin>> name;
        newD->setFName( name);
        cout<< "Enter the current date:"<<endl;
        cin>> date;
        newD->setFModifyTime( date );
        newD->setFPath( this->getFPath()+ "/" + name);
        newD->setPermission("- rw-");
        newD->setFOwner("sevgiborazan");
        //add the new directory to the vector
        this->memberFiles.push_back( newD );
        //return the last index of vector
        return *(this->memberFiles[ memberFiles.size() -1]);
        
    }
    
}//sevgiborazan
