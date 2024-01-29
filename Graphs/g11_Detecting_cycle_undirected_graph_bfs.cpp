#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdjList(int N,int M){
    vector<vector<int>> adjList(N);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}
bool detect_cycle_bfs(const vector<vector<int>> &adjList,int N,int root){
    vector<int> visited(N,0);
    queue<pair<int,int>> assist;
    assist.push({root,-1});
    visited[root] = 1;
    while(!assist.empty()){
        int node = assist.front().first;
        int parent = assist.front().second;
        for(int i=0;i<adjList[node].size();i++){
            if(!visited[adjList[node][i]]){
                assist.push({adjList[node][i],node});
                visited[adjList[node][i]] = 1;
            } else if(adjList[node][i]!=parent){
                cout<<"Cycle at :"<<adjList[node][i]<<endl;
                return true;
            }
        }
        assist.pop();
    }
    return false;
}

int main(){
    int N,M;
    cout<<"Enter the number of nodes and edges : ";
    cin>>N>>M;

    cout<<"Constructing Adjacency List"<<endl;
    vector<vector<int>> adjList = constructAdjList(N,M);

    int root;
    cout<<"Enter the root node : ";
    cin>>root;

    if(detect_cycle_bfs(adjList,N,root)) cout<<"Cycle is present in the graph"<<endl;
    else cout<<"Cycle is not present in the graph"<<endl;
    return 0;
}