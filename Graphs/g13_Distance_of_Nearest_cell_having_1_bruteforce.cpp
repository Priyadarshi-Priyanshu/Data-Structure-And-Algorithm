#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> constructGrid(int size){
    vector<vector<int>> grid(size,vector<int>(size,0));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>grid[i][j];
        }
    }
    return grid;
} 

int distance1_bfs(const vector<vector<int>> &grid, int size,vector<int> loc){
    vector<vector<int>> visited(size,vector<int>(size,0));
    queue<vector<int>> assist;
    int distance = INT_MAX;

    if(grid[loc[0]][loc[1]]==1) return 0;
    visited[loc[0]][loc[1]] = 1;
    assist.push(loc);

    while(!assist.empty()){
        vector<int> currloc = assist.front();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)+abs(j)==1){
                    if(currloc[0]+i>=0 && currloc[0]+i<size && currloc[1]+j>=0 && currloc[1]+j<size){
                        if(!visited[currloc[0]+i][currloc[1]+j]){
                            if(grid[currloc[0]+i][currloc[1]+j]==1) return currloc[2]+abs(i)+abs(j);
                            visited[currloc[0]+i][currloc[1]+j] = 1;
                            assist.push({currloc[0]+i,currloc[1]+j,currloc[2]+abs(i)+abs(j)});
                        }
                    }
                }
            }
        }
        assist.pop();
    } 
    return -1;
}


int main(){
    int size;
    cout<<"Enter the size : ";
    cin>>size;

    vector<vector<int>> grid = constructGrid(size);
    vector<vector<int>> distanceGrid(size,vector<int>(size,0));;

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            vector<int> loc = {i,j,0};
            distanceGrid[i][j] = distance1_bfs(grid,size,loc);
        }
    }


    cout<<"The grid will be : "<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<distanceGrid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}