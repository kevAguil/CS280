//
//  PostfixEval.cpp
//  RA7_K_Aguilar
//
//  Created by Kevin Aguilar on 4/3/23.
//

#include <stdio.h>
#include <string>
#include <map>
#include <stack>
#include <sstream>
#include <regex>
#include <iostream>
using namespace std;

void PostfixEval(string instr)
{
    stack<int> stack;
    map<string, int>var;
    for (int i = 0; i < instr.size(); ++i) {
        string word = "";
        while (i < instr.size() && instr[i] != ' '){
            word += instr[i];
            i++;
        }
        if (isdigit(word[0])){
            stack.push(stoi(word));
        }
        else if (regex_match(word, regex("[$][a-zA-Z]+"))){
            string varname = word.substr(1); // removes prefix '$'
            auto it = var.find(varname);
            if (it != var.end()){
                stack.push(it->second);
            }
            else{
                stack.push(0);
            }
        }
        else if (isalpha(word[0])){ //inserts variable
            if (stack.empty()){
                cerr << "Error: Incomplete input postfix expression." << endl;
                exit(0);
            }
            int num = stack.top();
            stack.pop();
            var.insert(make_pair(word, num));
        }
        else{
            if (stack.size() < 2){
                cerr << "Error: Incomplete input postfix expression." << endl;
                exit(0);
            }
            int var_One = stack.top();
            stack.pop();
            int var_Two = stack.top();
            stack.pop();
            switch (word[0])
            {
            case '+':
            {
                stack.push(var_Two + var_One);
                break;
            }
            case '-':
            {
                stack.push(var_Two - var_One);
                break;
            }
            case '*':
            {
                stack.push(var_Two * var_One);
                break;
            }
            case '/':
            {
                stack.push(var_Two / var_One);
                break;
            }
            default:
            {
                cerr << "Error: Invalid string \"" << instr << '"' << endl;
                exit(1);
                break;
            }
            }
        }
    }
    if (stack.empty()){
        cerr << "Error: Incomplete input postfix expression." << endl;
        exit(0);
    }
    else if (stack.size() > 1){
        cerr << "The evaluation is incomplete, missing input operators." << endl;
        exit(0);
    }
    else{
        
        int result = stack.top();
        stack.pop();
        cout << "The result of evaluating the postfix expression " << '"' << instr << '"' << " is the value: " << result << endl;
        exit(0);
    }
}

int main()
{
    //ifstream file;
    string instr;
    cout << "Please enter a postfix expression for evalution, using only single lowercase characters as variables:" << endl;
    getline(cin, instr);
    //cout << instr << endl;
    PostfixEval(instr);
    //cout << endl;
    //cout<<"Thank you." << endl;


    return 0;
}


