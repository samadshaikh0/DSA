#include "bits/stdc++.h"
using namespace std;

class Graph {
    public:
    map<int,list<int>> adj;

    // create an edge
    void createEdge(int u, int v,bool direction){

        // directed graph
        adj[u].push_back(v);
        if(direction == 0){ //undirected graph
            adj[v].push_back(u);
        }
    }

    void printGraph(){

        for(auto i:adj){
            cout << i.first << "-> ";
            for(auto j:i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};


int main(){
    int n,m;
    cout << "Enter Number of Nodes: " << endl;
    cin >> n;
    cout << "Enter Number of Edges: " << endl;
    cin >> m;

    Graph g;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        g.createEdge(u,v,0);
    }

    g.printGraph();
    
    return 0;
}