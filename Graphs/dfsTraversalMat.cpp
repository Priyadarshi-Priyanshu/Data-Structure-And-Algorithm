#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdjMat(int N, int M){
    cout<<"Constructing the Adjacency Matrix ----> "<<endl;
    vector<vector<int>> adjMat(N,vector<int>(N,0));
    for(int i=0;i<M;i++){
        int u,v;
        cout<<"Enter the nodes you want to connect : ";
        cin>>u>>v;
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }
    return adjMat;
}

void printAdjMat(vector<vector<int>> adjMat){
    int size = adjMat.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs_traversal(const vector<vector<int>> &adjMat,const int &root,vector<int> &visited,vector<int> &dfs){
    // Operation applied
    visited[root] = 1;
    dfs.push_back(root);
    for(int i=0;i<adjMat.size();i++){
        if(adjMat[root][i]==1 && visited[i]!=1){
            dfs_traversal(adjMat,i,visited,dfs);
        }
    }
}

int main(){
    int N,M;
    cout<<"Enter the number of nodes and edges : ";
    cin>>N>>M;
    vector<vector<int>> adjMatrix = constructAdjMat(N,M);
    // depth first search traversal
    vector<int> dfs;
    vector<int> visited(N,0);
    int root;
    cout<<"Enter the root : ";
    cin>>root;

    dfs_traversal(adjMatrix,root,visited,dfs);
    cout<<"The dfs traversal of the graph is as follow : "<<endl;
    for(int i=0;i<dfs.size();i++){
        cout<<dfs[i]<<" ";
    }
    cout<<endl;
    return 0;
}