#define _USE_MATH_DEFINES //need it to get the value of pi
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int radius;
    cout << "Enter a radius value: ";
    cin >> radius; //asking for user input

    cout << "The area of the circle is: " <<  M_PI * radius * radius << endl; //area of circle is pi*r^2

    return 0;
}