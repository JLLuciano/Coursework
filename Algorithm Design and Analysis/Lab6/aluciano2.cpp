#include<iostream>
#include<iterator>
#include<list>

using namespace std; 
  
class Hash 
{ 
    //how many buckets we are going to use 
    int hSize;
  
    // Pointer to an array containing buckets 
    list<int> *table; 
public: 
    Hash(int V);  // Constructor 
  
    // inserts a key into hash table 
    void insertElement(int k); 
  
    // deletes a key from hash table 
    void deleteElement(int key);

    //searches for key in the hash table
    void searchHash(int key);
  
    // hash function to map values to key 
    int hashFunction(int k) { 
        return (k % hSize); 
    } 
  
    void displayHash(); 
}; 
  
Hash::Hash(int hashSize) 
{ 
    this->hSize = hashSize; 
    table = new list<int>[hSize]; 
} 
  
void Hash::insertElement(int key) 
{ 
    int index = hashFunction(key); 
    table[index].push_front(key);  
} 
  
void Hash::deleteElement(int key){
    //i is the index of the Hash table and j is the index of the linked list

    int k = hashFunction(key);
    list <int> :: iterator i; 
 for(i = table[k].begin(); i != table[k].end(); i++){

     if(*i == key){
         break;
     }
 }

 //checking iterator to see if it has found the key, if not then print out not Delete FAILED
if (i != table[k].end()){ // it has not reached the end of the list, then it has found the value

    table[k].erase(i); //using erase func to delte inde from list
    cout<< key << " : DELETED"<<endl;
}
else{
    cout<< key << " : DELETE FAILED"<< endl;
}

}

//using the same format from deletItem except we are keeping track of
//hash table index and list index
void Hash::searchHash(int key){ 

   int k = hashFunction(key);
    int ith = k, jth =0;
    list <int> :: iterator i; 
 for(i = table[k].begin(); i != table[k].end(); i++){

     if(*i == key){
         break;
     }
     
     jth++;
 }

 if (i != table[k].end()){ // it has not reached the end of the list, then it has found the value

    cout<< key << " : FOUND AT "<< ith << "," << jth << endl;
}
else{
    cout<< key << " : NOT FOUND" << endl; 
}

}
  
// function to display hash table 
void Hash::displayHash() { 
    
    list <int>::iterator i; //index of list
    
   
  for (int j = 0; j < hSize; j++) { 
    cout << j << " : "; 
     i = table[j].begin();
    if(*i == NULL){
        //continue
        cout<<endl;
    }
    else{
        for (auto x : table[j]){
         
              if(i == table[j].begin()){
                
              }
              else{
                  cout<<"->";
              }
              cout<< x;
            // if(i == table->begin()){
            //             cout<<"->";
            // }
            // else if(i != prev(table->end())){
            //     cout<< "->";
            // }
            
            i++; 
        }
     cout << endl;
    } 
    }
} 
   
int main(){ 
    char operation;
    int hashSize, num;
    cin>> hashSize;

    Hash h(hashSize);

    while(operation != 'e'){

        cin>> operation;

        //Print out hash
        if(operation == 'o'){
            h.displayHash();
            cout<<"++++++++++++++++++++"<< endl;
        }
        //Search for num
        if(operation == 's'){
            cin>>num;
            h.searchHash(num);
            cout<<"++++++++++++++++++++"<< endl;
        }
        //Insert num
        if(operation == 'i'){
            cin>>num;
            h.insertElement(num);
            //cout<<"++++++++++++++++++++"<< endl;
        }
        //delete num
        if(operation == 'd'){
            cin>>num;
            h.deleteElement(num);
            cout<<"++++++++++++++++++++"<< endl;
        }
        
    }  

    //Stop program
        if(operation == 'e'){
            exit;
        }

  return 0; 
}