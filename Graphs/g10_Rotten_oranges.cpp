#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> constructingBasket(pair<int,int> Size){
    vector<vector<int>> basket(Size.first,vector<int>(Size.second,0));
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            cin>>basket[i][j];
        }
    }
    return basket;
}

void ReadBasket(vector<vector<int>> basket){
    for(int i=0;i<basket.size();i++){
        for(int j=0;j<basket[i].size();j++){
            cout<<basket[i][j]<<" ";
        }
        cout<<endl;
    }
}

void constructingVisited(const vector<vector<int>> &basket,queue<vector<int>> &assistance,vector<vector<int>> &visited){
    pair<int,int> Size;
    Size.first = basket.size();
    Size.second = basket[0].size();
    for(int i=0;i<Size.first;i++){
        for(int j=0;j<Size.second;j++){
            if(basket[i][j]==1) visited[i][j]=0;
            else if(basket[i][j]==2){
                vector<int> rottenOrange={i,j,0};
                visited[i][j] = 1;
                assistance.push(rottenOrange);
            }
        }
    }
}


int bfs_traversal(const vector<vector<int>> &basket,const pair<int,int> &Size){
    vector<vector<int>> visited(Size.first,vector<int>(Size.second,-1));
    queue<vector<int>> assistance;
    constructingVisited(basket,assistance,visited);
    int time = 0;
    while(!assistance.empty()){
        vector<int> currloc = assistance.front();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)+abs(j)==1){
                    if(currloc[0]+i>=0 && currloc[0]+i<Size.first && currloc[1]+j>=0 && currloc[1]+j<Size.second){
                        vector<int> newloc = {currloc[0]+i, currloc[1]+j, currloc[2]+1};
                        if(visited[newloc[0]][newloc[1]]==0 && basket[newloc[0]][newloc[1]]==1){
                            time = max(time,newloc[2]);
                            visited[newloc[0]][newloc[1]] = 1;
                            assistance.push(newloc);
                        }
                    }
                }
            }
        }
        assistance.pop();
    }
    return time;
}

int main(){
    pair<int,int> Size;
    cout<<"Enter the size of the fruit Basket : "<<endl;
    cin>>Size.first>>Size.second;

    cout<<"Arrange the fruits in the basket : "<<endl;
    vector<vector<int>> basket = constructingBasket(Size);

    int time = bfs_traversal(basket,Size);

    cout<<"Time taken to rot the entire basket is "<<time<<endl; 

    return 0;
}