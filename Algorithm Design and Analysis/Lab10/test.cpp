//Nimitt Tripathy
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

static int max_int = INT_MAX;
int t = 0;

vector<int> vec;
vector<int> finish_times;
vector<int> t_finish_time;

struct Vertex {
    int parent;
    int start;
    int end;
    int color;

    vector<int> adj;

    Vertex() {
        parent = max_int;
        color = 1;
    }

};

vector<Vertex*> verts;
vector<Vertex*> vert;

void visit(int index, vector<Vertex*> verts, bool transverse) {
    t++;
    verts[index]->start = t;
    verts[index]->color = 2;

    for (int g = 0; g < verts[index]->adj.size(); g++) {
        int adjacent = verts[index]->adj[g];

        if (verts[adjacent]->color == 1) {

            verts[adjacent]->parent = index;
            visit(adjacent, verts, transverse);
        }
    }

    t++;
    verts[index]->color = 3;
    verts[index]->end = t;

    if (!transverse) {
        finish_times.push_back(index);
    }
    else {
        t_finish_time.push_back(index);
    }
}

void dfs(vector<Vertex*> verts, bool transverse) {
    if (transverse) {
        t = 0;
        for (int k = 0; k < verts.size(); k++) {
            int t_index = finish_times[verts.size() - k - 1];
            //cout <<"index"<< t_index << endl;
            if (verts[t_index]->color == 1) {
                visit(t_index, verts, transverse);
            }
        }
    }
    else {
        for (int j = 0; j < verts.size(); j++) {
            if (verts[j]->color == 1) {
                visit(j, verts, transverse);
            }
        }
    }
}
bool isRoot(int index) {

    if (vert[index]->parent == max_int) {
        return true;
    }
    return false;
}

void setID(int index1, int index2) {

    int min = t_finish_time[index1];

    cout << "Finishing Time: " << t_finish_time[index1] << endl;

    for (int i = index1; i <= index2; i++) {
        if (min > t_finish_time[i]) {

            min = t_finish_time[i];
        }
    }
    for (int j = index1; j <= index2; j++) {

        cout << "min: " << min << endl;

        vec[t_finish_time[j]] = min;

        cout << vec[t_finish_time[j]] << endl;
    }
    cout << "Printing ID After Every iteration" << endl;
    for (int j = 0; j < vec.size(); j++) {
        cout << "ID: " << vec[t_finish_time[j]] << endl;
    }

}

void print() {
    int index = 0;

    for (int i = 0; i < t_finish_time.size(); i++) {
        cout << "root: " << vert[index]->parent << endl;
        if (isRoot(t_finish_time[i])) {
            setID(index, i);
            index = i + 1;
        }
    }

    for (int j = 0; j < vec.size(); j++) {
        cout << vec[j] << endl;
    }
}

int main() {
    int size, edges, vertex1, vertex2;

    cin >> size >> edges;
    verts.resize(size);
    vert.resize(size);
    vec.resize(size);

    for (int j = 0; j < size; j++) {

        verts[j] = new Vertex();
        vert[j] = new Vertex();
    }


    for (int i = 0; i < edges; i++) {
        cin >> vertex1;
        cin >> vertex2;
        verts[vertex1]->adj.push_back(vertex2);
        vert[vertex2]->adj.push_back(vertex1);
    }
    dfs(verts, false);
    dfs(vert, true);

    print();

}