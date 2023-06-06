#include <iostream>
#include <vector>
#include <climits>

using namespace std;


//using pseudocode from page 604 and 617 as a reference
int t = 0; //creating a global variable, t, that will be used for timestamping
//had to change variable time to t because it was creating errors due to the name
//vector<int>run;
//vector<int>run2;
vector<int>ID;
vector<vector<int>> run;

struct Vertex {
    int root;
    int d;//first timestamp
    int f;//second timestamp
    int color;// 0 = WHITE, 1 = GRAY, 2 = BLACK

    vector<int> edge;

    Vertex() {
        root = INT_MAX;
        color = 1;//start off as WHITE
    }

};
void DFS_VISIT(vector<Vertex*>vertex, int index, int path) {
    int i, adj;
    t = t + 1;
    vertex[index]->d = t;
    vertex[index]->color = 2;


    for (i = 0; i < vertex[index]->edge.size(); i++) { //explore the edges
        adj = vertex[index]->edge[i]; //assigning the edge to variable adj
        if (vertex[adj]->color == 1) {
            vertex[adj]->root = index;
            DFS_VISIT(vertex, adj, path); //exploring the edges recursively
        }
    }

    t = t + 1;

    vertex[index]->color = 3;
    vertex[index]->f = t;

    if (path == 0) { // 0 indicates false
        run[0].push_back(index); //first row will hold the first set of time
    }
    else {
        run[1].push_back(index); //second row will hold second set of time after the first run
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
            int index = run[0][vertex.size() - j - 1]; //consider the vertices in order of decreasing vertex->f
            if (vertex[index]->color == 1) {//checking if its WHITE
                DFS_VISIT(vertex, index, path);
            }
        }
    }
}
void SCC_ID(int pos, int pos2) {
    
    int temp = run[1][pos];


    

    for (int i = pos; i <= pos2; i++) {
        if (temp > run[1][i]) {
            temp = run[1][i]; //getting the smallest value index
        }
    }
    for (int j = pos; j <= pos2; j++) {
      
        int index = run[1][j];
        ID[index] = temp; //third row will hold the ID

    }
    
    for (int j = 0; j < ID.size(); j++) {
        cout << ID[j] << endl;
    }

}
void PRINT_SCC(vector<Vertex*>vertex) {
    int temp;
    int counter = 0;

    for (int i = 0; i < run[1].size(); i++) {

        temp = run[1][i];
       
        if (vertex[temp]->root == INT_MAX) {
            SCC_ID(counter, i);
            counter = i+1;
        }
    }
    for (int j = 0; j < ID.size(); j++) {
        cout << ID[j] << endl;
    }
}
void SCC(vector<Vertex*>vertex, vector<Vertex*>vertex2) {
    
    DFS(vertex, 0);
    DFS(vertex2, 1);
}
int main() {
    int size, edges, vertices, vertices2;
    cin >> size;
    cin >> edges;

    vector<Vertex*> vertex;
    vector<Vertex*> vertex2;
  


    vertex.resize(size);
    ID.resize(size);
    vertex2.resize(size);//created two vectors because SCC will calculated the running time twice


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
    PRINT_SCC(vertex2);

    return 0;
}