#include "data.h"
#include <iostream>

using namespace m;
using namespace std;

int Type::Integer(int a, float b, char c) {
    cout << "Function name: Integer" << endl; //prints the name of the function
    cout << "Argument list: " << a << ", " << b << ", " << c << endl;
    cout << "Return type: int" << endl;
    return 0;
}

void Type::Void(int d, char e) {
    cout << "Function name: Void" << endl;
    cout << "Argument list: " << d << ", " << e << endl;//prints each argument present in the function
    cout << "Return type: void" << endl;
}

float Type::Float(float f, float g, int h, char i) {
    cout << "Function name: Float" << endl;
    cout << "Argument list: " << f << ", " << g << ", " << h << ", " << i << endl;
    cout << "Return type: float" << endl;//prints the return type of the function
    return 0;
}

char Type::Character(char j, float k) {
    cout << "Function name: Character" << endl;
    cout << "Argument list: " << j << ", " << k << endl;
    cout << "Return type: char" << endl;
    return 0;
}