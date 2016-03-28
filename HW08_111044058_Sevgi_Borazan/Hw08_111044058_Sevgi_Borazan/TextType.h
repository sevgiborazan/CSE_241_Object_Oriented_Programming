//This is the header file TextType.h.
//This is the interface for the derived class from File .

/* 
 * File:   TextType.h
 * Author: sevgiborazan
 *
 * Created on 20 Aralık 2015 Pazar, 16:43
 */

#ifndef TEXTTYPE_H
#define	TEXTTYPE_H

#include "File.h"

namespace sevgiborazan{
    
    class TextType : public File{
    
    public:
        
        //Constructors
        TextType();
        TextType(const string& newFName);
        TextType(const string& newFName, const string& newFOwner);
        TextType(const string& newFName, const string& newFOwner, const string& newFModTime );
        TextType(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize );
        TextType(const string& newFName, const string& newFOwner, const string& newFModTime, const int& newFSize,const string & newType);
        
        //Destructor
        virtual ~TextType();
        
        //other setter and getter
        inline void setType(const string& newType){ type = newType; }
        inline string getType()const{ return type; }
        
        //virtual functions inherited from base class will be implemented
        void ls()const;     
        void ls(const string& lsMode)const;
        File& cd(const File & other)const; 
        bool cp( const File& other) ;
        inline bool isDir()const{ return false; }
        
    private:
        string type;
        
    };//class TextType

}//sevgiborazan


#endif	/* TEXTTYPE_H */

