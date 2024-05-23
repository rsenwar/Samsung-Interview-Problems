#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define MAX 500000
#define MOD 1000000007
#define INF INT_MAX
#define LINF LLONG_MAX
#define pi acos(-1.0)
#define F first
#define S second
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
int ab[MAX];
int bc[MAX];
int n,m;
int val=INT_MAX;
vector<pair<int,vector<int>>>ans;
void cycle(int s,vector<vector<int>>&v,vector<int>&vis,int cost,vector<int>&res){
    vis[s]=1;
    res.push_back(s);
    for(auto cld:v[s]){
        if(!vis[cld]){
            cycle(cld,v,vis,cost+cld,res);
        }
        else{
            ans.push_back({cost,res});
        }
    }
    vis[s]=0;
    res.pop_back();
}
void solve() {
    cin>>n>>m;
    vector<vector<int>>v(n+5);
    vector<int>vis(n+5,0);
    vector<int>tm;
    int cnt=0;
    for(int i=0;i<2*m;i++){
        int x;
        cin>>x;
        tm.push_back(x);
    }
    for(int i=1;i<2*m;i+=2){
        v[tm[i-1]].push_back(tm[i]);
    }
    vector<int>res;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cycle(i,v,vis,i,res);
        }
    }
    sort(ans.begin(),ans.end());
    vector<int>fin;
    fin=ans[0].S;
    sort(fin.begin(),fin.end());
    for(auto it:fin){
        cout<<it<<" ";
    }
    cout<<nline;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
