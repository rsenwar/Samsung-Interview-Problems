// Solution with Bitmasking
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<tuple>
using namespace std;

#define it(idx) get<idx>(it)

int n,startX,startY,endX,endY;
vector<pair<pair<pair<int,int>,pair<int,int>>,int>>v;

int ans,allone;

int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

void getDist(int sourceX,int sourceY,int mask,int sum){
    int d=dist(sourceX,sourceY,endX,endY);
    ans=min(ans,sum+d);
    if(mask==allone) return;
    for(int i=0;i<n;i++){
        if((mask & (1<<i))==0){
            int fromX=v[i].first.first.first;
            int fromY=v[i].first.first.second;
            int toX=v[i].first.second.first;
            int toY=v[i].first.second.second;
            {
                int sourceToFrom=dist(sourceX,sourceY,fromX,fromY);
                int costInWormHole=v[i].second;
                getDist(toX,toY,(mask | (1<<i)),sum+sourceToFrom+costInWormHole);
            }
            {
                int sourceToTo=dist(sourceX,sourceY,toX,toY);
                int costInWormHole=v[i].second;
                getDist(fromX,fromY,(mask | (1<<i)),sum+sourceToTo+costInWormHole);
            }
            
        }
    }
}

void solve(){
    v.clear();
    cin>>n>>startX>>startY>>endX>>endY;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2,cost; cin>>x1>>y1>>x2>>y2>>cost;
        v.push_back({{{x1,y1},{x2,y2}},cost});
    }
    int mask=0,sum=0;
    ans=1e9,allone=(1<<n)-1;
    getDist(startX,startY,mask,sum);
    cout<<ans<<endl;
    // cout<<"OK"<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++){
        solve();
    }
    return 0;
}