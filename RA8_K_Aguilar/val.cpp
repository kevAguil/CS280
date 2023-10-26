

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
Value Value::operator*(const Value& op) const {
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
        return Value(numericaloper1 * numericaloper2);
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
        return Value(numericaloper1 * numericaloper2);
        
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
        
        return Value(numericaloper1 * numericaloper2);
    }
    
    else if (IsReal() && op.IsReal()){
        // No conversion need to be made
        numericaloper1 = GetReal();
        numericaloper2 = op.GetReal();
        return Value(numericaloper1 * numericaloper2);
    }
    else if ((IsInt() || IsReal()) && (op.IsInt() || op.IsReal())){
        if (IsInt() && op.IsInt()){
            double result = GetInt() * op.GetInt();
            return Value(result);
        }
        else if (IsInt() && op.IsReal()){
            double result = GetInt() * op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsReal()){
            double result = GetReal() * op.GetReal();
            return Value(result);
        }
        else if (IsReal() && op.IsInt()){
            double result = GetReal() * op.GetInt();
            return Value(result);
        }
        else{
            return Value();
        }
        
    }
    else{
        return Value();
    }
}

//---------------------------------------------------------------------------------------------
Value Value::operator^(const Value& op) const {
    
    double numericaloper1,numericaloper2;
    double answer = 1;
    if(IsReal() && op.IsReal()){
        numericaloper1 = GetReal();
        numericaloper2 = op.GetReal();
        answer = pow(numericaloper1, numericaloper2);
        return Value(answer);
    }
    else{
        return Value();
    }
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
Value Value::operator/(const Value& op) const {
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
        if(numericaloper2 == 0){
            return Value();
        }
        return Value(numericaloper1 / numericaloper2);
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
        if(numericaloper2 == 0){
            return Value();
        }
        return Value(numericaloper1 / numericaloper2);
        
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
        if(numericaloper2 == 0){
            return Value();
        }
        return Value(numericaloper1 / numericaloper2);
    }
    
    else if (IsReal() && op.IsReal()){
        // No conversion need to be made
        numericaloper1 = GetReal();
        numericaloper2 = op.GetReal();
        if(numericaloper2 == 0){
            return Value();
        }
        return Value(numericaloper1 / numericaloper2);
    }
    
    else{
        return Value();
    }
    
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


