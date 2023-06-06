#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    vector<string> v; //created a vector
    string con;

    ifstream in("test.txt"); //telling program which file to read from
    string line;

    while (getline(in, line)) {
         v.push_back(line); //inputting one line at a time to the vector
    }

    for (int i = 0; i < v.size(); i++) {
        con += v[i] + "\n"; //adding each line from the vector to the string con, "\n" is for each new line
    }

    cout << con; //printing the concatenated string


    return 0;
}