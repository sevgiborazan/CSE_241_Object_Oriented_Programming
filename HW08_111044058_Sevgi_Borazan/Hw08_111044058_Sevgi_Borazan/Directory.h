//This is the header file Directory.h.
//This is the interface for the derived class from File .

/* 
 * File:   Directory.h
 * Author: sevgiborazan
 *
 * Created on 17 Aralik 2015 Persembe, 22:13
 */

#ifndef DIRECTORY_H
#define	DIRECTORY_H

#include "File.h"

namespace sevgiborazan{

    class Directory :public File{
    
    public:
        
        //constructors
        Directory();
        Directory(const string& newDirName);
        Directory(const string& newDirName, const string& newDirOwner);
        Directory(const string& newDirName, const string& newDirOwner, const string& newDirModTime);
        Directory(const string& newDirName, const string& newDirOwner, const string& newDirModTime, const int& newDirSize);
        
        //Destructor
        virtual~Directory();
        
        //other setter
        inline void setNumFile(const int &newNum){ numOfFile = newNum; }
        
        //other getter
        inline int getNumOfFile()const{ return numOfFile; }
        
        //will be overriden functions
        void ls()const;
        void ls(const string& lsMode)const;
        File& cd(const File & other)const;
        bool cp( const File& other);
        
        //other member functions
        const File& newDir();
        //File newFile();
        
        bool isDir()const{ return true; }
        
    private:
        int numOfFile;
        vector<File*> memberFiles;  //Holds the files in a directory
        
        //will be used instead of function pointers
        void l( File* f );
        void R( File* f );
        void a( File* f );
        void lR( File* f );
        void la( File* f );
        void Ra( File* f );
        void lRa( File* f );
        void wrapper( Directory* dptr, void ( *mode )( File* ptr ) );
        
    
    };//class Directory

}//sevgiborazan

#endif	/* DIRECTORY_H */

