#include <iostream>
#include <fstream>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

long hashFunction(string word) { //to determine where to put words

    while (word.length() < 4) {
        word += ' ';
    }
    return word[0]*pow(128, 3) + word[1]*pow(128, 2) + word[2]*128 + word[3];
  
}

string reverse(string text) {
    reverse(text.begin(), text.end()); //reverse the strings
    return text;
}

bool find(string word, LinkedList*& List) {
    long temp = hashFunction(word);
    if (List[temp].head == NULL) { //not in the LinkedList
            return false;
        }
    else {
        return List[temp].search(word); //trying to find it, will return True or False
    }
}



int main() {
 string word;

 const long N = pow(128,4);

 LinkedList* table = new LinkedList[N];

 ResizableArray Words;

 int count = 0;

 fstream file;

 string Text;

 cout << "Enter the file to be read and checked: ";
 cin >> Text;

 
 file.open(Text, ios::in);
 if (file.is_open()) {
     while (getline(file, word)) {
         Words.append(word);
         long index = hashFunction(word);
         table[index].append(word);
     }
     file.close();
 }
 else {
     cout << "Could not read file..." << endl;
 }
 ResizableArray checked;

 timestamp start = current_time();
 for (long i = 0; i < Words.count; i++) {
     string rev = reverse(Words[i]);
     
     if (reverse(Words[i]) == Words[i]) { //checks for palindromes
         checked.append(rev); //spent too much time doing cout << rev << endl;
         count++;
     }
     else {
         if (find(rev, table)) { //essentially comparing reversed words from array to linkedlist
             checked.append(rev);
             count++;
         }
     }
 }
 timestamp end = current_time();
 long duration = time_diff(start, end);

 cout << "List of valid backward words is: " << checked << endl;
 cout << "Total words found: " << count << " words" << endl;
 cout << "Completed in: " << duration << " ms." << endl;
    return 0;
}
