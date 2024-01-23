#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjListConstruct(int N,int M){
    vector<vector<int>> adjList(N,vector<int>());
    cout<<"Construct the graph --> Add the node point which are connecting"<<endl;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected Graph
    }
    return adjList;
}

void dfs_traversal(vector<vector<int>> adjList,int root,vector<int> &visited,vector<int> &dfs){
    visited[root]=1;
    dfs.push_back(root);
    for(auto node: adjList[root]){
        if(!visited[node]){
            dfs_traversal(adjList,node,visited,dfs);
        }
    }
}

int main(){
    int N,M;
    int root;
    cout<<"Enter the number of Nodes and Edges : ";
    cin>>N>>M;

    vector<vector<int>> adjList = adjListConstruct(N,M);

    vector<int> dfs;
    vector<int> visited(N,0);

    int count = 0;
    for(int i=0;i<visited.size();i++){
        if(!visited[i]){
            count++;
            vector<int> dfs;
            cout<<"The dfs for "<<count<<" number component are as follow"<<endl;
            dfs_traversal(adjList,i,visited,dfs);
            cout<<" The dfs for the component is as follow ------> "<<endl;
            for(const auto &node : dfs){
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}