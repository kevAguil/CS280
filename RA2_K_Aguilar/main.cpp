//
//  main.cpp
//  RA2_K_Aguilar
//
//  Created by Kevin Aguilar on 1/26/23.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
int main() {
    string fileName;
    cout<< "Enter the name of a file to read from:\n" << endl;
    cin >> fileName;
    ifstream inFile;
    inFile.open(fileName);
    string lines;
    int numOfLines=0;
    int numOfComLines=0;
    int maxLine=0;
    int maxComLine=0;
    string maxLines;
    string maxComLines;
    
    if(!inFile.is_open()){
        cout << "File cannot be opened "<<fileName << endl;
        exit(0);
    }
    while(getline(inFile,lines)){
        numOfLines++;

        if(lines.substr(0,2).compare("//") == 0 || lines.substr(0,2).compare("##") == 0){
            numOfComLines++;
            if(maxComLine < lines.size()){
                maxComLine = lines.size();
                maxComLines = lines;
            }
            
        }
        else if(maxLine < lines.size()){
            maxLine = lines.size();
            maxLines = lines;
                
        }
       
    }
    
    
    
    
    cout << "Total Number of Lines: " << numOfLines << endl;
    cout << "Number of commented lines: " << numOfComLines << endl;
    cout << "Maximum Length of commented lines: " << maxComLine << endl;
    cout << "Maximum Length of non-commented lines: " << maxLine << endl;
    cout << "Commented line of maximum length: " << '"' << maxComLines << '"' << endl;
    cout << "Non-commented line of maximum length: " << '"' << maxLines << '"' << endl;
    
    
    return 0;
}
