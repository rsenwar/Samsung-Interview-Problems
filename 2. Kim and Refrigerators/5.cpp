// Solution with Bitmasking
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n; 
int startX,startY,endX,endY;
int ans;
vector<pair<int,int>>v;
int allone;

int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

void find(int sum,int mask,int last){
    if(mask==allone){
        int d=dist(v[last].first,v[last].second,endX,endY);
        ans=min(ans,sum+d);
        return;
    }
    for(int i=0;i<n;i++){
        if((mask & (1<<i))==0){
            int d=dist(v[last].first,v[last].second,v[i].first,v[i].second);
            find(sum+d,(mask | (1<<i)),i);
        }
    }
}

void solve(){
    cin>>n;
    cin>>startX>>startY>>endX>>endY;
    v.clear();
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    ans=1e9;
    allone=(1<<n)-1;
    for(int i=0;i<n;i++){
        int sum=dist(startX,startY,v[i].first,v[i].second);
        find(sum,(1<<i),i);
    }
    cout<<ans<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T=10;
    for(int t=1;t<=T;t++){
        cout<<"# "<<t<<" ";
        solve();
    }
    return 0;
}
