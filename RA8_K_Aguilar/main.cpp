//
//  main.cpp
//  RA8_K_Aguilar
//
//  Created by Kevin Aguilar on 4/9/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}






#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <sstream>
#include "val.h"

using namespace std;

//---------------------------------------------------------------------------------------------
Value Value::operator*(const Value& op) const //MULTIPLICATION
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            double result = oper1 * oper2;
            return Value(result);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt())
            {
                double result = oper1 * op.GetInt();
                return Value(result);
            }
            else if (op.IsReal())
            {
                double result = oper1 * op.GetReal();
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (IsInt())
            {
                double result = GetInt() * oper1;
                return Value(result);
            }
            else if (IsReal())
            {
                double result = GetReal() * oper1;
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            double result = GetInt() * op.GetInt();
            return Value(result);
        }
        else if (IsInt() && op.IsReal())
        {
            double result = GetInt() * op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsReal())
        {
            double result = GetReal() * op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsInt())
        {
            double result = GetReal() * op.GetInt();
            return Value(result);
        }
    }
    return Value();
}

//---------------------------------------------------------------------------------------------
Value Value::operator^(const Value& oper) const //EXPONENT
{
    if (IsInt() && oper.IsInt())
    {
        double result = pow(GetInt(), oper.GetInt());
        return Value(result);
    }
    else if (IsReal() && oper.IsReal())
    {
        double result = pow(GetReal(), oper.GetReal());
        return Value(result);
    }
    else if (IsInt() && oper.IsReal())
    {
        double result = pow(GetInt(), oper.GetReal());
        return Value(result);
    }
    else if (IsReal() && oper.IsInt())
    {
        double result = pow(GetReal(), oper.GetInt());
        return Value(result);
    }
    return Value();
}

//---------------------------------------------------------------------------------------------
Value Value::operator==(const Value& op) const{
    double numericaloperand1, numericaloperand2;
    bool result = false;
    if(IsReal() && op.IsReal()){
        numericaloperand1 = GetReal();
        
        numericaloperand2 = op.GetReal();
        if(numericaloperand1 == numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    else if(IsString() && op.IsString()){
        // Both operands must be converted
        // First operand must bc converted to Numeric
        try{
            numericaloperand1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        // Second operand must be converted to numeric
        try{
            numericaloperand2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        if(numericaloperand1 == numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    else if(IsString() && op.IsReal()){
        // First operand must be converted
        try{
            numericaloperand1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        numericaloperand2 = op.GetReal();
        if(numericaloperand1 == numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
        
    }
    
    else if(IsReal() && op.IsString()){
        // Second operand must be converted
        numericaloperand1 = GetReal();
        
        try{
            numericaloperand2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        if(numericaloperand1 == numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    return Value();
}

//---------------------------------------------------------------------------------------------
Value Value::Catenate(const Value& op) const{
    string stringoperand1, stringoperand2;
    
        if(IsString() && op.IsString()){
            // No operand must be converted
            stringoperand1 = GetString();
            
            stringoperand2 = op.GetString();
            return Value(stringoperand1 + stringoperand2);

        }
    
        else if(IsReal() && op.IsString()){
            //first operand must be converted to a string
            ostringstream outStr1;
            outStr1 << GetReal();
            stringoperand1 = outStr1.str();
            
            stringoperand2 = op.GetString();
            return Value(stringoperand1 + stringoperand2);

        }
        else if (IsReal() && op.IsReal()) {
            //Both operands must be converted
            ostringstream outStr1;
            outStr1 << GetReal();
            stringoperand1 = outStr1.str();
            
            ostringstream outStr2;
            outStr2 << op.GetReal();
            stringoperand2 = outStr2.str();
            return Value(stringoperand1 + stringoperand2);
 
        }
        else if (IsString() && op.IsReal()){
            //Second operator must be converted
            stringoperand1 = GetString();
            
            ostringstream outStr2;
            outStr2 << op.GetReal();
            stringoperand2 = outStr2.str();
            return Value(stringoperand1 + stringoperand2);
        }
    
        else {
            return Value();
        }

}


//---------------------------------------------------------------------------------------------
Value Value::SLthan(const Value& op) const{
    string stringoperand1, stringoperand2;
    bool result = false;
    
        if(IsString() && op.IsString()){
            // No operand must be converted
            stringoperand1 = GetString();
            
            stringoperand2 = op.GetString();
            
            if(stringoperand1.compare(stringoperand2) < 0){
                result = true;
            }
            return Value(result);
        }
    
        else if(IsReal() && op.IsString()){
            //first operand must be converted to a string
            ostringstream outStr1;
            outStr1 << GetReal();
            stringoperand1 = outStr1.str();
            
            stringoperand2 = op.GetString();
            if(stringoperand1.compare(stringoperand2) < 0){
                result = true;
            }
            return Value(result);
        }
        else if (IsReal() && op.IsReal()) {
            //Both operands must be converted
            ostringstream outStr1;
            outStr1 << GetReal();
            stringoperand1 = outStr1.str();
            
            ostringstream outStr2;
            outStr2 << op.GetReal();
            stringoperand2 = outStr2.str();
            if(stringoperand1.compare(stringoperand2) < 0){
                result = true;
            }
            return Value(result);
 
        }
        else if (IsString() && op.IsReal()){
            //Second operator must be converted
            stringoperand1 = GetString();
            
            ostringstream outStr2;
            outStr2 << op.GetReal();
            stringoperand2 = outStr2.str();
            if(stringoperand1.compare(stringoperand2) < 0){
                result = true;
            }
            return Value(result);
        }
        else {
            return Value();
        }

}


//---------------------------------------------------------------------------------------------
Value Value::operator+(const Value& op) const {
    double numericaloper1;
    double numericaloper2;
    
    if(IsString() && op.IsString()){
        // Both operands must be converted
        // First operand must bc converted to Numeric
        try{
            numericaloper1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        // Second operand must be converted to numeric
        try{
            numericaloper2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(numericaloper1 + numericaloper2);
    }
    
    else if(IsString() && op.IsReal()){
        // First operand must be converted
        try{
            numericaloper1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        numericaloper2 = op.GetReal();
        return Value(numericaloper1 + numericaloper2);
        
    }
    
    else if(IsReal() && op.IsString()){
        // Second operand must be converted
        numericaloper1 = GetReal();
        
        try{
            numericaloper2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        return Value(numericaloper1 + numericaloper2);
    }
    
    else if (IsReal() && op.IsReal()){
        // No conversion need to be made
        numericaloper1 = GetReal();
        numericaloper2 = op.GetReal();
        return Value(numericaloper1 + numericaloper2);
    }
    
    else{
        return Value();
    }
    
}



//---------------------------------------------------------------------------------------------
Value Value::operator-(const Value& op) const {
    double numericaloper1;
    double numericaloper2;
    
    if(IsString() && op.IsString()){
        // Both operands must be converted
        // First operand must bc converted to Numeric
        try{
            numericaloper1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        // Second operand must be converted to numeric
        try{
            numericaloper2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        return Value(numericaloper1 - numericaloper2);
    }
    
    else if(IsString() && op.IsReal()){
        // First operand must be converted
        try{
            numericaloper1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        numericaloper2 = op.GetReal();
        return Value(numericaloper1 - numericaloper2);
        
    }
    
    else if(IsReal() && op.IsString()){
        // Second operand must be converted
        numericaloper1 = GetReal();
        
        try{
            numericaloper2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        return Value(numericaloper1 - numericaloper2);
    }
    
    else if (IsReal() && op.IsReal()){
        // No conversion need to be made
        numericaloper1 = GetReal();
        numericaloper2 = op.GetReal();
        return Value(numericaloper1 - numericaloper2);
    }
    
    else{
        return Value();
    }
    
}


//---------------------------------------------------------------------------------------------
Value Value::operator/(const Value& op) const //DIVISION
{
    double oper1, oper2;
    if (IsString() && op.IsString())
    {
        try
        {
            oper1 = stod(GetString());
            oper2 = stod(op.GetString());
            if (oper2 == 0)
            {
                return Value(); //DIVISION BY 0 ERROR
            }
            double result = oper1 / oper2;
            return Value(result);
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if (IsString() && (op.IsInt() || op.IsReal()))
    {
        try
        {
            oper1 = stod(GetString());
            if (op.IsInt() && op.GetInt() != 0)
            {
                double result = oper1 / op.GetInt();
                return Value(result);
            }
            else if (op.IsReal() && op.GetReal() != 0)
            {
                double result = oper1 / op.GetReal();
                return Value(result);
            }
            else
            {
                return Value(); // DIVISION BY 0 ERROR
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && op.IsString())
    {
        try
        {
            oper1 = stod(op.GetString());
            if (oper1 == 0)
            {
                return Value(); //DIVISON BY 0 ERROR;
            }
            else if (IsInt())
            {
                double result = GetInt() / oper1;
                return Value(result);
            }
            else if (IsReal())
            {
                double result = GetReal() / oper1;
                return Value(result);
            }
        }
        catch (invalid_argument& arg)
        {
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal()))
    {
        if (IsInt() && op.IsInt())
        {
            if (op.GetInt() != 0)
            {
                double result = GetInt() / op.GetInt();
                return Value(result);
            }
            return Value(); //DIVISON BY 0 ERROR;
        }
        else if (IsInt() && op.IsReal())
        {
            if (op.GetReal() != 0)
            {
                double result = GetInt() / op.GetReal();
                return Value(result);
            }
            return Value(); //DIVISON BY 0 ERROR;
        }
        else if (IsReal() && op.IsReal())
        {
            if (op.GetReal() != 0)
            {
                double result = GetReal() / op.GetReal();
                return Value(result);
            }
            return Value(); //DIVISON BY 0 ERROR;
        }
        else if (IsReal() && op.IsInt())
        {
            if (op.GetInt() != 0);
            {
                double result = GetReal() / op.GetInt();
                return Value(result);
            }
            return Value(); //DIVISON BY 0 ERROR;
        }
    }
    return Value();
}
//---------------------------------------------------------------------------------------------
Value Value::operator>(const Value& op) const{
    double numericaloperand1, numericaloperand2;
    bool result = false;
    if(IsReal() && op.IsReal()){
        numericaloperand1 = GetReal();
        
        numericaloperand2 = op.GetReal();
        if(numericaloperand1 > numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    else if(IsString() && op.IsString()){
        // Both operands must be converted
        // First operand must bc converted to Numeric
        try{
            numericaloperand1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        // Second operand must be converted to numeric
        try{
            numericaloperand2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        if(numericaloperand1 > numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    else if(IsString() && op.IsReal()){
        // First operand must be converted
        try{
            numericaloperand1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        numericaloperand2 = op.GetReal();
        if(numericaloperand1 > numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
        
    }
    
    else if(IsReal() && op.IsString()){
        // Second operand must be converted
        numericaloperand1 = GetReal();
        
        try{
            numericaloperand2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        if(numericaloperand1 > numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    return Value();
}



//---------------------------------------------------------------------------------------------
Value Value::operator<(const Value& op) const{
    double numericaloperand1, numericaloperand2;
    bool result = false;
    if(IsReal() && op.IsReal()){
        numericaloperand1 = GetReal();
        
        numericaloperand2 = op.GetReal();
        if(numericaloperand1 < numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    else if(IsString() && op.IsString()){
        // Both operands must be converted
        // First operand must bc converted to Numeric
        try{
            numericaloperand1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        // Second operand must be converted to numeric
        try{
            numericaloperand2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        if(numericaloperand1 < numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    else if(IsString() && op.IsReal()){
        // First operand must be converted
        try{
            numericaloperand1 = stod(GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        numericaloperand2 = op.GetReal();
        if(numericaloperand1 < numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
        
    }
    
    else if(IsReal() && op.IsString()){
        // Second operand must be converted
        numericaloperand1 = GetReal();
        
        try{
            numericaloperand2 = stod(op.GetString());
        }
        catch(invalid_argument & arg){
            cout << "Invalid conversion from string to double." << endl;
            return Value();
        }
        
        if(numericaloperand1 < numericaloperand2){
            result = true;
            return Value(result);
        }
        else{
            return result;
        }
    }
    
    return Value();
}



//---------------------------------------------------------------------------------------------
Value Value::SGthan(const Value& op) const{
    string stringoperand1, stringoperand2;
    bool result = false;
    
        if(IsString() && op.IsString()){
            // No operand must be converted
            stringoperand1 = GetString();
            
            stringoperand2 = op.GetString();
            
            if(stringoperand1.compare(stringoperand2) > 0){
                result = true;
            }
            return Value(result);
        }
    
        else if(IsReal() && op.IsString()){
            //first operand must be converted to a string
            ostringstream outStr1;
            outStr1 << GetReal();
            stringoperand1 = outStr1.str();
            
            stringoperand2 = op.GetString();
            if(stringoperand1.compare(stringoperand2) > 0){
                result = true;
            }
            return Value(result);
        }
        else if (IsReal() && op.IsReal()) {
            //Both operands must be converted
            ostringstream outStr1;
            outStr1 << GetReal();
            stringoperand1 = outStr1.str();
            
            ostringstream outStr2;
            outStr2 << op.GetReal();
            stringoperand2 = outStr2.str();
            if(stringoperand1.compare(stringoperand2) > 0){
                result = true;
            }
            return Value(result);
 
        }
        else if (IsString() && op.IsReal()){
            //Second operator must be converted
            stringoperand1 = GetString();
            
            ostringstream outStr2;
            outStr2 << op.GetReal();
            stringoperand2 = outStr2.str();
            if(stringoperand1.compare(stringoperand2) > 0){
                result = true;
            }
            return Value(result);
        }
        else {
            return Value();
        }

}




//---------------------------------------------------------------------------------------------
Value Value::SEqual(const Value& op) const{
    string stringoperand1, stringoperand2;
    bool result = false;
    
        if(IsString() && op.IsString()){
            // No operand must be converted
            stringoperand1 = GetString();
            
            stringoperand2 = op.GetString();
            
            if(stringoperand1.compare(stringoperand2) == 0){
                result = true;
            }
            return Value(result);
        }
    
        else if(IsReal() && op.IsString()){
            //first operand must be converted to a string
            ostringstream outStr1;
            outStr1 << GetReal();
            stringoperand1 = outStr1.str();
            
            stringoperand2 = op.GetString();
            if(stringoperand1.compare(stringoperand2) == 0){
                result = true;
            }
            return Value(result);
        }
        else if (IsReal() && op.IsReal()) {
            //Both operands must be converted
            ostringstream outStr1;
            outStr1 << GetReal();
            stringoperand1 = outStr1.str();
            
            ostringstream outStr2;
            outStr2 << op.GetReal();
            stringoperand2 = outStr2.str();
            if(stringoperand1.compare(stringoperand2) == 0){
                result = true;
            }
            return Value(result);
 
        }
        else if (IsString() && op.IsReal()){
            //Second operator must be converted
            stringoperand1 = GetString();
            
            ostringstream outStr2;
            outStr2 << op.GetReal();
            stringoperand2 = outStr2.str();
            if(stringoperand1.compare(stringoperand2) == 0){
                result = true;
            }
            return Value(result);
        }
        else {
            return Value();
        }

}



//---------------------------------------------------------------------------------------------

Value Value::Repeat(const Value& op) const{
    
    string stringoperand1;
    double numericaloper2;
    string newStr = "";
    if(IsString() && op.IsReal()){
        stringoperand1 = GetString();
        numericaloper2 = op.GetReal();
        for(int i=1;i<= numericaloper2; i++){
            newStr.append(stringoperand1);
        }
        return Value(newStr);
    }
    else{
        return Value();
    }
    
}


