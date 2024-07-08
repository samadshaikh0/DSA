#include "bits/stdc++.h"
using namespace std;


void prepareAdj(int n, unordered_map<int, set<int>> &adjList, vector<vector<int>> &edges){

    for(int i=0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int> > adjList, unordered_map<int,bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);


        for(auto x:adjList[frontNode]){
            if(!visited[x]){
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

vector<int> BFS(int n, vector<vector<int> > edges){
    unordered_map<int, set<int> > adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdj(n,adjList, edges);

    for(int i=0; i<n; i++){
        if(!visited[i])
            bfs(adjList, visited, ans, i);
    } 
    return ans;
}


int main(){
    vector<vector<int>> edges = {
        {0, 4},
        {1, 2},
        {1, 1},
        {2, 5},
    };


    vector<int> ans = BFS(4,edges);
    for(auto x:ans) cout << x << "    ";





    return 0;
}






while(start <= end){
        mid = (start + end)/2;
        long long val = mid* mid;
        if(val == n)
            return mid;
        else if(mid*mid > n){
            end = mid -1;
        }
    }

