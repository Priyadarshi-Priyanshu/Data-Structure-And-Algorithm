#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> constructingFilm(pair<int,int> Size){
    vector<vector<int>> film(Size.first,vector<int>(Size.second,0));
    cout<<"Construct the film : "<<endl;
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            cin>>film[i][j];
        }
    }
    return film;
}

void ReadFilm(vector<vector<int>> film){
    for(int i=0;i<film.size();i++){
        for(int j=0;j<film[i].size();j++){
            cout<<film[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> constructingVisited(const vector<vector<int>> &film, const pair<int,int> &loc){
    pair<int,int> Size(film.size(),film[0].size());
    vector<vector<int>> visited(Size.first,vector<int>(Size.second,-1));
    for(int i=0;i<film.size();i++){
        for(int j=0;j<film[i].size();j++){
            if(film[loc.first][loc.second]==film[i][j]) visited[i][j] = 0;
        }
    }
    return visited;
}

void bfs_traversal(vector<vector<int>> &film, pair<int,int> loc, const int fillColor){
    pair<int,int> Size(film.size(),film[0].size());
    vector<vector<int>> visited = constructingVisited(film,loc);
    queue<pair<int,int>> assistance;
    int currColor = film[loc.first][loc.second];

    assistance.push(loc);
    visited[loc.first][loc.second] = 1;
    film[loc.first][loc.second] = fillColor;
    while(!assistance.empty()){
        loc = assistance.front();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)+abs(j)==1){
                    if(loc.first+i>=0 && loc.first+i<Size.first && loc.second+j>=0 && loc.second+j<Size.second){
                        pair<int,int> newloc(loc.first+i,loc.second+j);
                        if(visited[newloc.first][newloc.second]==0 && film[newloc.first][newloc.second]==currColor){
                            assistance.push(newloc);
                            visited[newloc.first][newloc.second] = 1;
                            film[newloc.first][newloc.second] = fillColor;
                        }
                    }
                }
            }
        }
        assistance.pop();
    }
}


int main(){
    pair<int,int> Size;
    cout<<"Enter the Resolution of the film (x,y) : ";
    cin>>Size.first>>Size.second;

    vector<vector<int>> film = constructingFilm(Size);

    pair<int,int> loc;
    int fillColor;
    cout<<"Enter an integer specifying a new color : ";
    cin>>fillColor;
    cout<<"Enter the present Coordinates (x,y) : ";
    cin>> loc.first >> loc.second;

    cout<<"Before filling the color"<<endl;
    ReadFilm(film);
    bfs_traversal(film,loc,fillColor);
    cout<<"After filling the color"<<endl;
    ReadFilm(film);
    
    return 0;
}