//This is the header file File.h.
//This is the interface for the abstract class File .

/* 
 * File:   File.h
 * Author: sevgiborazan
 *
 * Created on 17 Aralik 2015 Persembe, 14:09
 */

#ifndef FILE_H
#define	FILE_H

#include <istream>
#include <string>
#include <vector>

using std ::string;
using std ::vector;


namespace sevgiborazan{

    void test();
    
    class File{
       
    public:
        //This class does not have to copy sonctructor
        //Because the file names can not be the same in same directory
        
        //Constructors
        File();
        File(const string& newFName);
        File(const string& newFName, const string& newFOwner);
        File(const string& newFName, const string& newFOwner, const string& newFModTime );
        File(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize );
        //Destructor
        virtual ~File();
        
        //setters
        void setFName(const string& newFName);
        void setFOwner(const string& newFOwner);
        void setFModifyTime(const string& newFModTime);
        void setFSize( const int& newFSize);
        inline void setFPath(const string& newPath ){ fPath = newPath; }
        inline void setPermission( const string& newPerm ){ permission = newPerm; }
        
        //getters
        inline string getFName()const{ return fName; }
        inline string getFOwner()const{ return fOwner;}
        inline string getFModifyTime()const{ return fModifyTime; }
        inline int getFSize()const{ return fSize; }
        inline string getFPath()const{ return fPath; }
        inline string getPermission()const{ return permission; }
        
        /*inline static string getOwnerC(){ return ownerC; }
        inline static string getOwnerU(){ return ownerU; }
        inline static string getDate(){ return defaultDate; }*/
        
        //other member functions
        //pure virtual yaparak File dan tureyen classlarin interfacinde bu fonksiyonlari barindirmasina zorluyoruz.
        virtual void ls()const = 0;     //pure virtual function
        virtual void ls(const string& lsMode)const = 0;     //pure virtual function
        virtual File& cd(const File & other)const = 0 ;
        virtual bool cp( const File& other) = 0;  //pure virtual function
        virtual bool isDir()const = 0;
        
    private:
        string fName;
        string fOwner;
        string fModifyTime;
        string fPath;
        int fSize;
        string permission;
        
        //permission
        /*const static string ownerC = "- rwx root";
        //const static string ownerU = "- rwx sevgiborazan";
        //const static string defaultDate = "7.12.2015";*/
        
    };//class File
    
}//sevgiborazan

#endif	/* FILE_H */

