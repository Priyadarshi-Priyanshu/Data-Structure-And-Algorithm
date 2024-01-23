#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ConstructMap(pair<int,int> gridSize){
    cout<<"Lets Construct the Map"<<endl;
    vector<vector<int>> map(gridSize.first,vector<int>(gridSize.second,0));
    for(int i=0;i<gridSize.first;i++){
        for(int j=0;j<gridSize.second;j++){
            cin>>map[i][j];
        }
    }
    return map;
}
void ReadMap(vector<vector<int>> map){
    cout<<"Map of the specified geographical region"<<endl;
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[i].size();j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}


void dfs(vector<vector<int>> &visited, const vector<vector<int>> &map, const pair<int,int> &gridSize, pair<int,int> loc){
    visited[loc.first][loc.second]=1;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            pair<int,int> newloc(loc.first+i,loc.second+j);
            if(newloc.first>=0 && newloc.first<gridSize.first && newloc.second>=0 && newloc.second<gridSize.second){
                if(!visited[newloc.first][newloc.second] && map[newloc.first][newloc.second])
                    dfs(visited,map,gridSize,newloc);
            }
        }
    }
}

int main(){
    pair<int,int> gridSize;
    cout<<"Enter the size of the grid (length,breadth) : ";
    cin>>gridSize.first>>gridSize.second;

    vector<vector<int>> map = ConstructMap(gridSize);

    vector<vector<int>> visited(gridSize.first,vector<int>(gridSize.second,0));
    int count = 0;
    for(int i=0;i<gridSize.first;i++){
        for(int j=0;j<gridSize.second;j++){
            if(!visited[i][j] && map[i][j]){
                count++;
                pair<int,int> location(i,j);
                dfs(visited,map,gridSize,location);
            }
        }
    }
    
    cout<<"The number of islands in the map are "<<count<<endl;
    return 0;
}