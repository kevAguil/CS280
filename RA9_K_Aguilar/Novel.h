//
//  Novel.h
//  CS280 NJIT
//
//  Created by Kevin Aguilar on 4/23/23.
//


#include <string>
#include <iostream>

class Novel : public Story {

protected:
    const int lowerbound = 101;
    int numWords;
    
public:
    
    
    Novel(){
        type = "Novel";
        pages = 224;
        numWords = 0;
    }
    
    Novel (std::string booktype, int numOfWords) {
        type = booktype;
        numWords = numOfWords;
    }
    
    
    
    virtual void setPages(int wordsPerPage) override {
        int pages = numWords / wordsPerPage;
        if (pages < lowerbound) {
            int shortfall = lowerbound - pages;
            msg = "Pages must be added to the book to satisfy the requirements of a Novel: " + shortfall;
        }
        else {
            msg = "Book is accepted.";
        }
    }
    
    
    virtual int getWords() {
        return numWords;
    }
    
    virtual void setWords(int numOfWords){
        numWords = numOfWords;
    }
    
    virtual std::string getType(){
        return type;
    }
    
    virtual void setType(std::string booktype){
        type = booktype;
    }
    
    virtual int getPages(){
        return pages;
    }
    
};



