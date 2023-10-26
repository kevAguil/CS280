//
//  ra5.cpp
//  RA5_K_Aguilar
//
//  Created by Kevin Aguilar on 2/26/23.
//

#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <map>
#include <sstream>
#include <regex>
#include "lex.h"
using namespace std;

map<string, Token> keyWords =
{
    {"IF",IF},
    {"ELSE",ELSE},
    {"WRITELN",WRITELN},
};

regex id("[[a-z][A-Z]_]?([[a-zA-Z0-9_]*)");

LexItem id_or_kw(const string& lexeme, int linenum){
    
    if(keyWords.find(lexeme)!= keyWords.end()){
        return LexItem(keyWords[lexeme], lexeme, linenum);
    }
    else if(lexeme[0] == '@'){
        return LexItem(SIDENT, lexeme, linenum);
    }
    else if(lexeme[0] == '$'){
        return LexItem(NIDENT, lexeme, linenum);
    }
    else{
        return LexItem(IDENT, lexeme, linenum);
    }
}

ostream& operator<<(ostream& out, const LexItem& tok){
    Token tokType = tok.GetToken();
        switch (tokType)
        {
        case WRITELN:
        {
            out << "WRITELN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case IF:
        {
            out << "IF: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case ELSE:
        {
            out << "ELSE: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case IDENT:
        {
            out << "IDENTIFIER: " << tok.GetLexeme() << " at Line " << tok.GetLinenum() << endl;
            break;
        }
        case NIDENT:
        {
            out << "NIDENT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case SIDENT:
        {
            out << "SIDENT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case ICONST:
        {
            out << "ICONST: (" << tok.GetLexeme() << ") at Line " << tok.GetLinenum() << endl;
            break;
        }
        case RCONST:
        {
            out << "RCONST: (" << tok.GetLexeme() << ") at Line " << tok.GetLinenum() << endl;
            break;
        }
        case SCONST:
        {
            out << "SCONST: \'" << tok.GetLexeme() << "\' at Line " << tok.GetLinenum() << endl;
            break;
        }
        case PLUS:
        {
            out << "PLUS: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case MINUS:
        {
            out << "MINUS: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case MULT:
        {
            out << "MULT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case DIV:
        {
            out << "DIV: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case EXPONENT:
        {
            out << "EXPONENT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case ASSOP:
        {
            out << "ASSOP: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case NEQ:
        {
            out << "NEQ: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case NGTHAN:
        {
            out << "NGTHAN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case NLTHAN:
        {
            out << "NLTHAN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case CAT:
        {
            out << "CAT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case SREPEAT:
        {
            out << "SREPEAT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case SEQ:
        {
            out << "SEQ: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case SLTHAN:
        {
            out << "SLTHAN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case SGTHAN:
        {
            out << "SGTHAN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case COMMA:
        {
            out << "COMMA: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case SEMICOL:
        {
            out << "SEMICOL: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case LPAREN:
        {
            out << "LPAREN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case RPAREN:
        {
            out << "RPAREN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case LBRACES:
        {
            out << "LBRACES: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case RBRACES:
        {
            out << "RBRACES: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        case ERR:
        {
            out << "Error: : \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        }
        default:
            break;
        }
        return out;
    }


