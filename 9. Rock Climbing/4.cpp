// Solution with Bitmasking
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define inf 1e9


int n,m;
vector<vector<int>>mat,dis;

bool valid(int x,int y){
    return 0<=x && x<n && 0<=y && y<m;
}
bool right(int x,int y){
    y++;
    return valid(x,y) && mat[x][y];
}
bool left(int x,int y){
    y--;
    return valid(x,y) && mat[x][y];
}
bool up(int x,int y){
    x++;
    return valid(x,y) && mat[x][y];
}
bool down(int x,int y){
    x--;
    return valid(x,y) && mat[x][y];
}

int ans;

void dfs(int x,int y,int max_jump){
    // cout<<x<<" "<<y<<" "<<max_jump<<endl;
    if(mat[x][y]==3){
        // cout<<"YES"<<endl;
        ans=min(ans,max_jump);
        return;
    }
    dis[x][y]=max_jump;
    // cout<<right(x,y)<<" "<<dis[x][y]<<endl;
    
    if(right(x,y) && dis[x][y+1]>max_jump){
        dfs(x,y+1,max_jump);
    }
    if(left(x,y) && dis[x][y-1]>max_jump){
        dfs(x,y-1,max_jump);
    }
    for(int i=0;i<n;i++){
        int jump=abs(x-i);
        if(mat[i][y] && dis[i][y]>max(jump,max_jump)){
            dfs(i,y,max(max_jump,jump));
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>m;
    mat.resize(n,vector<int>(m,inf));
    dis=mat;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    ans=inf;
    // for(int i=n-1;i>=0;i--){
    //     for(int j=0;j<m;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(0,0,0);
    cout<<ans<<endl;
    // for(int i=n-1;i>=0;i--){
    //     for(int j=0;j<m;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
