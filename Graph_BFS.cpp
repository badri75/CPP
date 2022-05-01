#include<bits/stdc++.h>
using namespace std;
#define V 4
vector<int> graph[V];

void addVec(int u, int v){
    graph[u].push_back(v);
//    graph[v].push_back(u);
}

void printGraph(){
    for (int v = 1; v < V; ++v){
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : graph[v])
            cout << "-> " << x;
        printf("\n");
    }
}

void BFS(int s){
    vector<bool> visited;
    list<int> queue;
    visited.resize(V,false);

    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()){
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(auto i: graph[s]){
            if(!visited[i]){
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

int main(){
    addVec(1,2);
    addVec(1,3);
    addVec(1,4);
    addVec(2,3);
    addVec(2,4);
    addVec(3,4);
    addVec(4,1);
    printGraph();
    BFS(3);
    return 0;
}