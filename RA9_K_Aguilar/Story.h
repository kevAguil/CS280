//
//  Story.h
//  RA9_K_Aguilar
//
//  Created by Kevin Aguilar on 4/23/23.
//


#include <string>
#include <iostream>


class Story{
    
protected:
    int pages;
    std::string title;
    std::string author;
    std::string type;
    std::string msg;

public:
    
    Story(){
        title = "";
        author = "";
        msg = "";
        type = "";
        pages = 0;
    }

    Story(std::string booktype){
        type = booktype;
    }
    
    virtual void setPages(int numOfPages)=0;
    
    virtual void setTitle(std::string booktitle){
        title = booktitle;
    }
    
    virtual std::string getTitle(){
        return title;
    }
    
    virtual void setAuthor(std::string bookauthor){
        author = bookauthor;
    }
    
    virtual std::string getAuthor(){
        return author;
    }
    
    virtual int getPages(){
        return pages;
    }
    
    virtual void setMsg(std::string bookmsg){
        msg = bookmsg;
    }
    
    virtual std::string getMsg(){
        return msg;
    }
    
    virtual std::string getType(){
        return type;
    }
    
    virtual void setType(std::string booktype){
        type = booktype;
    }
    
    
};


