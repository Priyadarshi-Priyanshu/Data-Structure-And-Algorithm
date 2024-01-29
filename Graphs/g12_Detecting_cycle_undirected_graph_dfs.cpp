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

bool detect_cycle_dfs(const vector<vector<int>> &adjList, vector<int> &visited, int node, int parent){
    cout<<"(Node,Parent) : ("<<node<<","<<parent<<")"<<endl;
    if(!visited[node]){
        visited[node] = 1;
        for(int i=0;i<adjList[node].size();i++){
            if(adjList[node][i]!=parent){
                if(detect_cycle_dfs(adjList,visited,adjList[node][i],node)) return true;
            } 
        }
        return false;
    }
    return true;
}

int main(){
    int N,M;
    cout<<"Enter the number of nodes and edges : ";
    cin>>N>>M;

    cout<<"Constructing Adjacency List"<<endl;
    vector<vector<int>> adjList = constructAdjList(N+1,M);
    vector<vector<int>> adjList(N+1);
    vector<int> visited(N+1,0);

    cout<<"Adjacency List is as follow : "<<endl;
    for(int i=0;i<N+1;i++){
        cout<<i<<" : ";
        for(int j=0;j<adjList[i].size();j++){
            cout<< adjList[i][j]<<" ";
        }
        cout<<endl;
    }

    int root;
    cout<<"Enter the root : ";
    cin>>root;

    if(detect_cycle_dfs(adjList,visited,root,-1)) cout<<"Cycle is present in the graph"<<endl;
    else cout<<"Cycle is not present in the graph"<<endl;

    return 0;
}