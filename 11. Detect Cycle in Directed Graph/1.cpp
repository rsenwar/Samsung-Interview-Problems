#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstring> // extra added
using namespace std;

#define pb push_back
#define pp pop_back

// // solution 1
// int n,m,adj[11][11],stack[11],ans[11],idx,minCycleSum=200005;
// int vis[11];

// void detectCycle1(int node,int index){
//     if(vis[node]){
//         int sum=node;
//         for(int i=index-2;i>=0 && stack[i]!=node;i--){
//             sum+=stack[i];
//         }
//         if(sum<minCycleSum){
//             idx=0;
//             ans[idx++]=node;
//             for(int i=index-2;i>=0 && stack[i]!=node;i--){
//                 ans[idx++]=stack[i];
//             }
//         }
//         return;
//     }
//     else{
//         vis[node]=1;
//         for(int i=1;i<=n;i++){
//             if(adj[node][i]==1){
//                 stack[index]=i;
//                 detectCycle1(i,index+1);
//             }
//         }
//         vis[node]=0;
//     }
// }

// void solve1(){
//     cin>>n>>m;
//     memset(&adj[0][0],0,(n+1)*(n+1)*sizeof(int));
//     memset(vis,0,(n+1)*sizeof(int));
//     for(int i=0;i<m;i++){
//         int u,v; cin>>u>>v;
//         adj[u][v]=1;
//     }
//     for(int i=1;i<=n;i++){
//         stack[0]=i;
//         detectCycle1(i,1);
//     }
//     sort(ans,ans+idx);
//     for(int i=0;i<idx;i++){
//         cout<<ans[i]<<" ";
//     }
//     // cout<<n<<m<<endl;
//     cout<<endl;
// }

// // solution 2
// vector<vector<int>>adj;
// int n,m,idx,minCycleSum=200005;
// vector<int>vis,stack,ans;

// void detectCycle2(int node,int index){
//     if(vis[node]){
//         int sum=node;
//         for(int i=index-2;i>=0 && stack[i]!=node;i--){
//             sum+=stack[i];
//         }
//         if(sum<minCycleSum){
//             idx=0;
//             ans[idx++]=node;
//             for(int i=index-2;i>=0 && stack[i]!=node;i--){
//                 ans[idx++]=stack[i];
//             }
//         }
//         return;
//     }
//     else{
//         vis[node]=1;
//         for(int num:adj[node]){
//             stack[index]=num;
//             detectCycle2(num,index+1);
//         }
//         vis[node]=0;
//     }
// }

// void solve2(){   
//     cin>>n>>m;
//     adj.resize(n+1);
//     vis.resize(n+1,0);
//     stack.resize(n+1);
//     ans.resize(n+1);
//     for(int i=0;i<m;i++){
//         int u,v; cin>>u>>v;
//         adj[u].pb(v);
//     }
//     for(int i=1;i<=n;i++){
//         stack[0]=i;
//         detectCycle2(i,1);
//     }
//     sort(ans.begin(),ans.begin()+idx);
//     for(int i=0;i<idx;i++){
//         cout<<ans[i]<<" ";
//     }
//     // cout<<n<<m<<endl;
//     cout<<endl;
// }

int n,m,min_sum;
vector<vector<int>>adj;
vector<int>ans;

void findWay(int idx,int mask){
    // cout<<idx<<" "<<mask<<" "<<(mask & (1<<idx))<<endl;
    if((mask & (1<<idx))!=0){
        // loop created
        int sum=0;
        vector<int>temp;
        for(int i=0;i<n;i++){
            if((mask & (1<<i))!=0) sum+=(i+1),temp.push_back(i+1);
        }
        if(sum<min_sum){
            min_sum=sum;
            ans=temp;
        }
        // cout<<"Found"<<endl;
        return;
    }
    for(int i=0;i<int(adj[idx].size());i++){
        findWay(adj[idx][i],(mask | (1<<idx)));
    }                                                         
}

void solve3() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>m;
    adj.resize(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
    }
    min_sum=1e9;
    for(int i=0;i<n;i++){
        findWay(i,0);
    }
    sort(ans.begin(),ans.end());
    // cout<<min_sum<<endl;
    for(int i=0;i<int(ans.size());i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // solve1();
    // solve2();
    solve3();
    return 0;
}