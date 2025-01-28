// Solution with DFS
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,ans;
vector<vector<int>>v;

bool valid(int position){
    return 0<=position && position<5;
}

void game(int index,int position,int sum,int life){
    // cout<<index<<" "<<position<<" "<<sum<<" "<<life<<endl;
    if(index==n || !life){
        ans=max(sum,ans);
        // cout<<"OK: "<<ans<<endl;
        return;
    }
    if(v[index][position]==1) sum++;
    else if(v[index][position]==2 || life!=5) life--;
    
    if(valid(position)) game(index+1,position,sum,life);
    if(valid(position-1)) game(index+1,position-1,sum,life);
    if(valid(position+1)) game(index+1,position+1,sum,life);
}

void solve(){
    cin>>n;
    v.resize(n);
    for(int i=n-1;i>=0;i--){
        v[i].resize(5);
        for(int j=0;j<5;j++){
            cin>>v[i][j];
        }
    }
    // position,sum,blasted,life
    ans=0;
    game(0,2,0,5);
    game(0,1,0,5);
    game(0,3,0,5);
    cout<<ans<<endl;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        cout<<"#"<<t<<" ";
        solve();
    }
    return 0;
}
