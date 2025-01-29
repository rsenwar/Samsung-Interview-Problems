// Solution with Bitmasking
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647

int n; 
vector<vector<int>>adj;
int visited_all;

// O(n!) solution
int tsp(int mask,int pos){
    if(mask==visited_all){
        return adj[pos][0];
    }
    int ans=INT_MAX;
    for(int city=0;city<n;city++){
        if(!(mask&(1<<city))){
            int newAns=adj[pos][city]+tsp(mask|(1<<city),city);
            ans=min(ans,newAns);
        }
    }
    return ans;
}
void solve(int& t,int& T){
    cin>>n;
    adj.resize(n);
    for(int i=0;i<n;i++){
        adj[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    visited_all=(1<<n)-1;
    cout<<tsp(1,0)<<endl;
}

//O((2^n)*n) solution
vector<vector<int>>dp;
int tsp2(int mask,int pos){
    if(mask==visited_all){
        return adj[pos][0];
    }
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    int ans=INT_MAX;
    for(int city=0;city<n;city++){
        if(!(mask&(1<<city))){
            int newAns=adj[pos][city]+tsp2(mask|(1<<city),city);
            ans=min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}
void solve2(int& t,int& T){
    cin>>n;
    adj.resize(n);
    for(int i=0;i<n;i++){
        adj[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    visited_all=(1<<n)-1;
    dp.clear();
    dp.resize(1<<n);
    for(int i=0;i<(1<<n);i++){
        dp[i].resize(n,-1);
    }
    cout<<tsp2(1,0)<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++){
        solve2(t,T);
    }
    return 0;
}
