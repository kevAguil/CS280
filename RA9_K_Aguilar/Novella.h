//
//  Novella.h
//  CS280 NJIT
//
//  Created by Kevin Aguilar on 4/23/23.
//


#include <string>
#include <iostream>


class Novella : public Story {

protected:
    const int lowerbound = 51;
    const int upperbound = 100;
    int numWords;
    
public:
        
    
    Novella(){
        type = "Novella";
        pages = 90;
        numWords = 0;
    }

    
    Novella (std::string booktype, int numOfWords) {
        type = booktype;
        numWords = numWords;
    }
    
    
    virtual void setPages(int wordsPerPage) override {
        int pages = numWords / wordsPerPage;
        if (pages < lowerbound) {
            int shortfall = lowerbound - pages;
            msg = "Pages must be added to the book to satisfy the requirements of a Novella: " + shortfall;
        }
        else if(pages > upperbound){
            int excess = pages - upperbound;
            msg = "Pages must be cut to the book to satisfy the requirements of a Novella: " + excess;
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



