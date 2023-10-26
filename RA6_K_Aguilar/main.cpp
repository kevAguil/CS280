//
//  main.cpp
//  RA6_K_Aguilar
//
//  Created by Kevin Aguilar on 3/5/23.
//

#include <iostream>
#include <string>

using namespace std;


string DecToBaseN(int num, int base){

    if ((base > 10 && base <=15) || base < 2){
        cout << "Invalid Base: " << base << endl;
        return "";
    }
    if (base == 16){
        if ( num % base >= 10 && num % base <= 15){
            int remainder = num % base;
            switch (remainder) {
                case 10:{
                    return DecToBaseN(num/base, base) + "A";
                    break;
                }
                case 11:{
                    return DecToBaseN(num/base, base) +"B";
                    break;
                }
                case 12:{
                    return DecToBaseN(num/base, base) +"C";
                    break;
                }
                case 13:{
                    return DecToBaseN(num/base, base) +"D";
                    break;
                }
                case 14:{
                    return DecToBaseN(num/base, base) +"E";
                    break;
                }
                case 15:{
                    return DecToBaseN(num/base, base) +"F";
                    break;
                }
                default:
                    break;
            }
        }
    }
    
    if ( num/base == 0){
        return to_string(num % base);
    }
        
    return DecToBaseN(num/base, base) + to_string(num % base);

}


int main(int argc, const char * argv[]) {
    
    int base;
    int decimal;
    cout << "Enter a decimal number:" << endl;
    cin >> decimal;
    cout << "Enter the base of conversion:" << endl;
    cin >> base;
    string answer = DecToBaseN(decimal, base);
    cout << "result of converting the decimal number " << decimal << " to base " << base << ": "<< answer << endl;
    

    return 0;
}
