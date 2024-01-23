#include<bits/stdc++.h>
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



int main(){
    int N,M;
    cout<<"Enter the number of nodes and edges : ";
    cin>>N>>M;
    vector<vector<int>> adjMatrix = constructAdjMat(N,M);
    
    vector<int> dfs;
    vector<int> visited(N,0);
    int root;


    return 0;
}