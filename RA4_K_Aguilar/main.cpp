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
#include <map>
#include <regex>
using namespace std;
int main(int argc, char *argv []) {
    string line;
    string word;
    ifstream file;
    map<string, int> specialWordMap;
    map<int , int> integersMap;
    map<float,int> fixedPointMap;
    int numOfSpecialWords = 0;
    int numOfIntegers = 0;
    int numOfFixedPoint = 0;
    regex floatExpression("[+-]?([0-9]+\\.[0-9]+)");
    regex integerExpression("^[+-]?\\d+([^.])+");
    
    
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
            if(word[0] == '$' && isalpha(word[1]) != 0 && isalpha(word.back())!=0 ){
                numOfSpecialWords++;
                if( specialWordMap.find(word) == specialWordMap.end() ){
                    specialWordMap[word] = 1;
                }
                else{
                    specialWordMap[word] = specialWordMap[word] + 1;
                }
                
            }
            if(regex_match(word, integerExpression)){
                numOfIntegers++;
                
                if( integersMap.find(stoi(word)) == integersMap.end() ){
                    integersMap[stoi(word)] = 1;
                }
                else{
                    integersMap[stoi(word)] = integersMap[stoi(word)] + 1;
                }
            }
            if(regex_match(word, floatExpression)){
                numOfFixedPoint++;
                if( fixedPointMap.find(stof(word)) == fixedPointMap.end() ){
                    fixedPointMap[stof(word)] = 1;
                }
                else{
                    fixedPointMap[stof(word)] = fixedPointMap[stof(word)] + 1;
                }
            }
            
        }
        
        
    }
    file.close();
    cout << "Number of integers in the file: "<< numOfIntegers<< endl;
    cout << "Number of reals in the file: "<< numOfFixedPoint<<endl;
    cout << "Number of special names in the file: "<< numOfSpecialWords<< endl;
    if(numOfIntegers!= 0){
        cout << endl << "List of integer values and their number of occurrences:" <<endl;
        for(auto it = integersMap.begin(); it!= integersMap.end(); it++ ){
            cout << it->first << ": " << it->second << endl;
        }
    }
    if(numOfFixedPoint != 0){
        cout << endl << "List of real values and their number of occurrences:" <<endl;
        for(auto it = fixedPointMap.begin(); it!= fixedPointMap.end(); it++ ){
            cout << it->first << ": " << it->second << endl;
        }
    }
    if(numOfSpecialWords != 0){
        cout << endl << "List of special names and their number of occurrences:" <<endl;
        for(auto it = specialWordMap.begin(); it!= specialWordMap.end(); it++ ){
            cout << it->first << ": " << it->second << endl;
        }
    }
    return 0;
}

