#include <iostream>
#include <vector>
#include<climits>

using namespace std;


//using pseudocode from page 604 and 617 as a reference

int t = 0; //creating a global variable, t, that will be used for timestamping
//had to change variable "time" to "t" because it was creating errors due to the name
vector<int>run;//to avoid segmentation faults I set these three vectors as Global vectors
vector<int>run2;
vector<int>ID;


struct Vertex {
    int root;
    int d;//first timestamp
    int f;//second timestamp
    int color;// 1 = WHITE, 2 = GRAY, 3 = BLACK

    vector<int> edge;

    Vertex() {
        root = INT_MAX; 
        color = 1;//start off as WHITE
    }

};

void DFS_VISIT(vector<Vertex*>vertex,int index, int path) {
    int i, adj;
    t = t + 1;//updating time

    vertex[index]->color = 2;//setting it to Gray
    vertex[index]->f = t;

    for (i = 0; i < vertex[index]->edge.size(); i++) { //explore the edges
        adj = vertex[index]->edge[i]; //assigning the edge to variable adj
        if (vertex[adj]->color == 1) {
            vertex[adj]->root = index;//because of this line here I had to set the default value of vertex->root to INT_MAX to avoid issues when checking for roots
            DFS_VISIT(vertex,adj, path); //exploring the edges recursively
        }
    }
  
    t = t + 1;

    vertex[index]->color = 3;//setting it to Black
    vertex[index]->d = t;
    //These if and else statements will decide which vector will hold the index depending if its DFS(G) or DFS(G^T)
    if (path == 0) { // 0 indicates false
        run.push_back(index); 
    }
    else {
        run2.push_back(index); 
    }
}
void DFS(vector<Vertex*>vertex, int path) {
    if (path == 0) { //visit in increasing order
        for (int i = 0; i < vertex.size(); i++) {
            if (vertex[i]->color == 1) {
                DFS_VISIT(vertex, i, path);
            }
        }
    }
    else {
        t = 0;
        for (int j = 0; j < vertex.size(); j++) {
            int index = run[vertex.size() - j - 1]; //consider the vertices in order of decreasing vertex->f
            if (vertex[index]->color == 1) {//checking if its WHITE
                DFS_VISIT(vertex, index, path);
            }
        }
    }
}
void SCC_ID(int pos, int pos2) {
   
    int temp = run2[pos];

    for (int i = pos; i <= pos2; i++) {
        if (temp > run2[i]) {
            temp = run2[i]; //getting the smallest value index
        }
    }
    for (int j = pos; j <= pos2; j++) {
       
        int index = run2[j];
        ID[index] = temp; //vector ID will hold the SCC_ID that will be printed out
        
    }
  
    
}

void PRINT_SCC(vector<Vertex*>vertex2) {
    int temp;
    int counter = 0;

    for (int i = 0; i < run2.size(); i++) {
        
        temp = run2[i];
     
        if (vertex2[temp]->root == INT_MAX) { //Noticed that initialising root to 0 caused the if statements to accept different roots
            SCC_ID(counter, i);
            counter= i + 1;
        }
    }
    for (int j = 0; j < ID.size(); j++) {
        cout << ID[j] << endl;
    }
}
void SCC(vector<Vertex*>vertex, vector<Vertex*>vertex2) {
  
    DFS(vertex, 0); //DFS(G)
    DFS(vertex2, 1);//DFS(G^T)
    PRINT_SCC(vertex2);//print the SCC
}

int main() {
    int size, edges, vertices, vertices2;
	cin >> size;
    cin >> edges;

    vector<Vertex*> vertex;//will be used for DFS(G)
    vector<Vertex*> vertex2;//will be used for DFS(G^T)
   
    vertex.resize(size);
    ID.resize(size);//resizing the vectors to avoid segmentation fault
    vertex2.resize(size);

  
  
    
    for (int i = 0; i < size; i++) {
     
        vertex[i] = new Vertex();
        vertex2[i] = new Vertex();
    }
 

    for (int j = 0; j < edges; j++) {
        cin >> vertices;
        cin >> vertices2;
        vertex[vertices]->edge.push_back(vertices2);
        vertex2[vertices2]->edge.push_back(vertices);
    }

    SCC(vertex, vertex2);

	return 0;
}