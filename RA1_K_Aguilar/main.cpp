//
//  main.cpp
//  RA1_K_Aguilar
//
//  Created by Kevin Aguilar on 1/19/23.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Welcome to CS 280 in Spring 2023 Semester"<< endl;
    cout << "Please enter your first name" << endl;
    string firstName;
    cin >> firstName;
    cout << "Please enter your last name" << endl;
    string lastName;
    cin >> lastName;
    cout << "Welcome "+firstName+" "+lastName+" to CS 280" << endl;
    return 0;
}
