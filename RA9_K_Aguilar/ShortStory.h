//
//  ShortStory.h
//  RA9_K_Aguilar
//
//  Created by Kevin Aguilar on 4/23/23.
//


#include <string>
#include <iostream>



class ShortStory : public Story {

protected:
    const int lowerbound = 5;
    const int upperbound = 50;
    int numWords;
    
public:
    
    ShortStory(){
        type = "Short Story";
        pages = 4;
        numWords = 0;

    }
    
  
    ShortStory (std::string booktype, int numOfWords) {
        type= booktype;
        numWords = numWords;
    }
    

    virtual void setPages(int wordsPerPage) override {
        int pages = numWords / wordsPerPage;
        if (pages < lowerbound) {
            int shortfall = lowerbound - pages;
            msg = "Pages must be added to the book to satisfy the requirements of a Short Story: " + shortfall;
        }
        else if(pages > upperbound){
            int excess = pages - upperbound;
            msg = "Pages must be cut to the book to satisfy the requirements of a Short Story: " + excess;
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




