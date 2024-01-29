#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> constructGrid(pair<int,int> Size){
    vector<vector<int>> grid(Size.first,vector<int>(Size.second,0));
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            cin>>grid[i][j];
        }
    }
    return grid;
}

void populateVisited(const vector<vector<int>> &grid,const pair<int,int> &Size,queue<vector<int>> &assist,vector<vector<int>> &visited){
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            if(grid[i][j]){
                assist.push({i,j,0});
                cout<<"Position : ("<<i<<" , "<<j<<" , "<<0<<")"<<endl;
                visited[i][j] = 1;
            }
        }
    }
}

vector<vector<int>> bfsDistance(const vector<vector<int>> &grid,const pair<int,int> &Size){
    vector<vector<int>> distanceGrid(Size.first,vector<int>(Size.second,0));
    vector<vector<int>> visited(Size.first,vector<int>(Size.second,0));
    queue<vector<int>> assist;
    populateVisited(grid,Size,assist,visited);

    while(!assist.empty()){
        vector<int> state = assist.front();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)+abs(j)==1){
                    if(state[0]+i>=0 && state[0]+i<Size.first && state[1]+j>=0 && state[1]+j<Size.second){
                        if(!visited[state[0]+i][state[1]+j]){
                            assist.push({state[0]+i,state[1]+j,state[2]+1});
                            cout<<"Position : ("<<state[0]+i<<" , "<<state[1]+j<<" , "<<state[2]+1<<")"<<endl;
                            distanceGrid[state[0]+i][state[1]+j] = state[2]+1;
                            visited[state[0]+i][state[1]+j] = 1;
                        }
                    }
                }
            }
        }
        assist.pop();
    }
    return distanceGrid;
}

int main(){
    pair<int,int> Size;
    cout<<"Enter the size : ";
    cin>>Size.first>>Size.second;

    vector<vector<int>> grid = constructGrid(Size);
    vector<vector<int>> distanceGrid = bfsDistance(grid,Size);
    cout<<"The Distance Grid is as follow : "<<endl;
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            cout<<distanceGrid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}