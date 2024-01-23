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



vector<int> bfs_traversal(vector<vector<int>> adjList,int root){
    queue<int> traversal_bucket;
    vector<int> visited(adjList.size(),0);
    vector<int> bfs;
    
    
    traversal_bucket.push(root);
    visited[root] = 1;
    bfs.push_back(root);
    while(!traversal_bucket.empty()){
        for(int i=0;i<adjList[traversal_bucket.front()].size();i++) {
            if(visited[adjList[traversal_bucket.front()][i]]!=1){ 
                traversal_bucket.push(adjList[traversal_bucket.front()][i]);
                visited[adjList[traversal_bucket.front()][i]] = 1;
                bfs.push_back(adjList[traversal_bucket.front()][i]);
            }
        }
        
        traversal_bucket.pop();
    }
    return bfs;
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

    cout<<"The BFS Traversal of the graph is as follow : "<<endl;
    vector<int> bfs = bfs_traversal(adjList,root);

    // printting the bfs traversal
    for(auto element : bfs) cout<<element<<" ";
    cout<<endl;

    return 0;
}