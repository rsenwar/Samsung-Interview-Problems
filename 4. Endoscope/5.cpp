// Solution with DFS
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,x,y,l;
vector<vector<int>>arr;
vector<vector<bool>>vis;

bool valid(int x,int y){
    return 0<=x && x<n && 0<=y && y<m;
}
bool up(int x,int y){
    x--;
    return valid(x,y) && (arr[x][y]==1 || arr[x][y]==2 || arr[x][y]==5 || arr[x][y]==6);
}
bool down(int x,int y){
    x++;
    return valid(x,y) && (arr[x][y]==1 || arr[x][y]==2 || arr[x][y]==4 || arr[x][y]==7);
}
bool right(int x,int y){
    y++;
    return valid(x,y) && (arr[x][y]==1 || arr[x][y]==3 || arr[x][y]==6 || arr[x][y]==7);
}
bool left(int x,int y){
    y--;
    return valid(x,y) && (arr[x][y]==1 || arr[x][y]==3 || arr[x][y]==4 || arr[x][y]==5);
}

void dfs(int x,int y,int d){
    if(d<1) return;
    vis[x][y]=true;
    int type=arr[x][y];
    switch(type){
        case 1:
            // up, down, left, right
            if(up(x,y)){
                // cout<<"up at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x-1,y,d-1);
            }
            if(down(x,y)){
                // cout<<"down at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x+1,y,d-1);
            }
            if(left(x,y)){
                // cout<<"left at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x,y-1,d-1);
            }
            if(right(x,y)){
                // cout<<"right at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x,y+1,d-1);
            }
            break;
        case 2:
            // up, down
            if(up(x,y)){
                // cout<<"up at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x-1,y,d-1);
            }
            if(down(x,y)){
                // cout<<"down at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x+1,y,d-1);
            }
            break;
        case 3:
            // left, right
            if(left(x,y)){
                // cout<<"left at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x,y-1,d-1);
            }
            if(right(x,y)){
                // cout<<"right at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x,y+1,d-1);
            }
            break;
        case 4:
            // up, right
            if(up(x,y)){
                // cout<<"up at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x-1,y,d-1);
            }
            if(right(x,y)){
                // cout<<"right at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x,y+1,d-1);
            }
            break;
        case 5:
            // down, right
            if(down(x,y)){
                // cout<<"down at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x+1,y,d-1);
            }
            if(right(x,y)){
                // cout<<"right at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x,y+1,d-1);
            }
            break;
        case 6:
            // down, left
            if(down(x,y)){
                // cout<<"down at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x+1,y,d-1);
            }
            if(left(x,y)){
                // cout<<"left at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x,y-1,d-1);
            }
            break;
        case 7:
            // up, left
            if(up(x,y)){
                // cout<<"up at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x-1,y,d-1);
            }
            if(left(x,y)){
                // cout<<"left at ("<<x<<" "<<y<<") "<<d-1<<endl;
                dfs(x,y-1,d-1);
            }
            break;
    }
}

void solve(){
    cin>>n>>m>>x>>y>>l;
    vis.clear();
    arr.resize(n,vector<int>(m));
    vis.resize(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    dfs(x,y,l);
    // cout<<"arr"<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<"visited"<<endl;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<vis[i][j]<<" ";
            if(vis[i][j]) ans++;
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
