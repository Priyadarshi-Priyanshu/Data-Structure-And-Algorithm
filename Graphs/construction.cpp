#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> constructAdjMatrix(int N,int M){
    vector<vector<int>> adjMat( N , vector<int>(N,0));
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    return adjMat;
}

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

int main(){
    int N,M;
    cout<<"Enter the number of nodes and edges : ";
    cin>>N>>M;

    cout<<"Constructing Adjacency Matrix"<<endl;
    vector<vector<int>> adjMat = constructAdjMatrix(N,M);
    cout<<"Adjacency matrix is as follow : "<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Constructing Adjacency List"<<endl;
    vector<vector<int>> adjList = constructAdjList(N,M);
    cout<<"Adjacency List is as follow : "<<endl;
    for(int i=0;i<N;i++){
        cout<<i<<" ";
        for(int j=0;j<adjList[i].size();j++){
            cout<< adjList[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}