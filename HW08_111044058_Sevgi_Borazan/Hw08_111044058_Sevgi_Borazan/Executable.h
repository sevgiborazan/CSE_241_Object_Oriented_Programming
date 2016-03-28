//This is the header file Executable.h.
//This is the interface for the derived class from File .

/* 
 * File:   Executable.h
 * Author: sevgiborazan
 *
 * Created on 20 Aralik 2015 Pazar, 15:17
 */

#ifndef EXECUTABLE_H
#define	EXECUTABLE_H

#include "File.h"

namespace sevgiborazan{
 
    class Executable: public File{
    public:
        //Constructors
        Executable();
        Executable(const string& newFName);
        Executable(const string& newFName, const string& newFOwner);
        Executable(const string& newFName, const string& newFOwner, const string& newFModTime );
        Executable(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize );
        Executable(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize,const string & newComp);
        
        //destructor
        virtual ~Executable();
        
        //other getter and setter
        inline void setCompiler(const string& newComp){ compiler = newComp; }
        inline string getCompiler()const{ return compiler; }
        
        //virtual functions inherited from base class will be implemented
        void ls()const;     
        void ls(const string& lsMode)const;
        File& cd(const File & other)const; 
        bool cp( const File& other) ;
        inline bool isDir()const{ return false; }
        
    private:
        string compiler;
    
    };//class Executable

}//sevgiborazan

#endif	/* EXECUTABLE_H */

