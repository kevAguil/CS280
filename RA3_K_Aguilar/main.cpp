
//
//  main.cpp
//  RA3_K_Aguilar
//
//  Created by Kevin Aguilar on 2/2/23.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
using namespace std;
int main(int argc, char *argv []) {
    string line;
    string word;
    ifstream file;
    int numOfWords = 0;
    int numOfType1 = 0;
    int numOfType2 = 0;
    
    if(argc < 2){
        cout << "NO SPECIFIED INPUT FILE NAME."<< endl;
        exit(0);
    }
    file.open(argv[1]);
    string fileName(argv[1]);
    if(file.fail()){
        cout << "CANNOT OPEN THE FILE " << fileName << endl;
        exit(0);
    }
    if(file.peek() == std::ifstream::traits_type::eof()){
        cout << "File is empty." << endl;
        exit(0);
    }
    while(getline(file, line)){
        istringstream currentLine(line);
        while(currentLine >> word){
            numOfWords++;
            if(word[0] == '$' && isalpha(word[1]) != 0 && isalpha(word.back())!=0 ){
                numOfType1++;
                
            }
            if(word[0] == '@' && isalpha(word[1]) != 0 && isalpha(word.back())!=0 ){
                numOfType2++;
                
            }
            
        }
        
        
    }
    file.close();
    if(argc != 3){
        int totalSpecial = numOfType1 + numOfType2;
        cout <<"Total number of words: "<< numOfWords<<endl;
        cout << "Total number of Type 1 and Type 2 names: "<< totalSpecial << endl;
        exit(0);
    }
    string argumentFlag(argv[2]);
    if(argumentFlag.compare("-all") == 0 || argc < 3){
        cout <<"Total number of words: "<< numOfWords<<endl;
        cout <<"Number of Type 1 names: "<< numOfType1<<endl;
        cout <<"Number of Type 2 names: "<< numOfType2<<endl;
    }
    else if (argumentFlag.compare("-type1") == 0){
        cout <<"Number of Type 1 names: "<< numOfType1<<endl;
    }
    else if (argumentFlag.compare("-type2") == 0){
        cout <<"Number of Type 2 names: "<< numOfType2<<endl;
    }
    else{
        cout << "UNRECOGNIZED FLAG " <<argumentFlag<< endl;
    }
    
    return 0;
}
