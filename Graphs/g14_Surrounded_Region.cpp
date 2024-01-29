#include<bits/stdc++.h>
using namespace std;

#define VVI vector<vector<int>>
#define VVC vector<vector<char>>
#define VC vector<char>

VVC constructRegion(const pair<int,int> &Size){
    VVC region(Size.first, VC(Size.second,' '));
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            cin>>region[i][j];
        }
    }
    return region;
}

vector<vector<int>> constructVisited(const VVC &region, const pair<int,int> &Size){
    vector<vector<int>> visited(Size.first,vector<int>(Size.second,0));
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            if(region[i][j]=='X') visited[i][j] = -1;
        }
    }
    return visited;
}

void printRegion(const VVC &region,const pair<int,int> &Size){
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            cout<<region[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(const VVC &region, const pair<int,int> &Size,VVC &updRegion,VVI &visited,pair<int,int> loc,const int &flag){
    visited[loc.first][loc.second] = 1;
    if(flag){
        updRegion[loc.first][loc.second] = 'X';
    }
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(abs(i)+abs(j)==1){
                if(loc.first+i>=0 && loc.first+i<Size.first && loc.second+j>=0 && loc.second+j<Size.second){
                    if(visited[loc.first+i][loc.second+j]==0) dfs(region,Size,updRegion,visited,{loc.first+i,loc.second+j},flag);
                }
            }
        }
    }
}


int main(){
    pair<int,int> Size;
    cout<<"Enter the size for the Region (Rows,Columns) : ";
    cin>>Size.first>>Size.second;

    VVC region = constructRegion(Size);
    VVC updRegion = region;
    vector<vector<int>> visited = constructVisited(region,Size);
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            if(i==0 || i==Size.first-1 || j==0 || j==Size.second-1){
                if(!visited[i][j]) dfs(region,Size,updRegion,visited,{i,j},0);
            }
        }
    }
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            if(!visited[i][j]) dfs(region,Size,updRegion,visited,{i,j},1);
        }
    }
    cout<<"The updated region is as follow : "<<endl;
    printRegion(updRegion,Size);
    return 0;
}