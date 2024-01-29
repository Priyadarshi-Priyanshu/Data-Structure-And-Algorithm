#include<bits/stdc++.h>
using namespace std;

#define VVI vector<vector<int>>
#define VI vector<int>
#define PII pair<int,int>

VVI constructMap(const PII &Size){
    VVI map(Size.first,VI(Size.second,0));
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            cin>>map[i][j];
        }
    }
    return map;
}

VVI constructVisited(const VVI &grid, const PII &Size,int &landCell){
    VVI visited(Size.first,VI(Size.second,0));
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            if(grid[i][j]==0) visited[i][j] = -1;
            else if(grid[i][j]==1){
                landCell++;
                visited[i][j] = 0;
            }
        }
    }
    return visited;
}

void dfs(const VVI &grid, const PII &Size, VVI &visited,int row,int column,int &enclaves){
    cout<<"Position : ("<<row<<" , "<<column<<")"<<" enclaves count : "<<enclaves<<endl;
    if(visited[row][column]==0){
        visited[row][column] = 1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)+abs(j)==1){
                    if(row+i>=0 && row+i<Size.first && column+j>=0 && column+j<Size.second){
                        if(grid[row+i][column+j]==1 && visited[row+i][column+j]==0)  
                            dfs(grid,Size,visited,row+i,column+j,--enclaves);
                    }
                }
            }
        }
    }
}

int Number_of_Enclaves(const VVI &grid,const PII &Size){
    int enclaves = 0;
    VVI visited = constructVisited(grid,Size,enclaves);
    cout<<"Number of enclaves : "<<enclaves<<endl;
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            if(i==0 || i==Size.first-1 || j==0 || j==Size.second-1){
                if(grid[i][j]==1 && visited[i][j]==0)  dfs(grid,Size,visited,i,j,--enclaves);
            }
        }
    }
    return enclaves;
}

int main(){
    PII Size;
    cout<<"Enter the size of the map (N,M) : ";
    cin>>Size.first>>Size.second;
    VVI map = constructMap(Size);

    cout<<"Enclaves means land cells from which moving out of grid is not feasible"<<endl;
    cout<<"Number of enclaves : "<<Number_of_Enclaves(map,Size)<<endl;
    return 0;
}