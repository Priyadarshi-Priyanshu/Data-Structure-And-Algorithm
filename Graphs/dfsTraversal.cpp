#include<bits/stdc++.h>
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

void dfs_traversal(vector<vector<int>> adjList,int root,vector<int> &dfs,vector<int> &visited){
    visited[root] = 1;
    dfs.push_back(root);
    for(auto node: adjList[root]){
        if(!visited[node]){
            dfs_traversal(adjList,node,dfs,visited);
        }
    }
}

int main(){
    int N,M;
    int root;
    cout<<"Enter the number of Nodes and Edges : ";
    cin>>N>>M;

    cout<<"Constructing the graphs using Adjacency List"<<endl;
    vector<vector<int>> adjList = constructAdjList(N,M);

    cout<<"Enter the root of the graph : ";
    cin>>root;

    vector<int> dfs;
    vector<int> visited(N,0);
    dfs_traversal(adjList,root,dfs,visited);

    cout<<"The dfs traversal of the graph is as follow : "<<endl;
    for(auto node : dfs){
        cout<< node << " ";
    }
    cout<<endl;

    return 0;
}