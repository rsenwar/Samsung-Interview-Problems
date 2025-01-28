// Solution with Bitmasking
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<int>v;
int getScore(int idx,int mask){
    int prev=0,next=0;
    for(int i=idx-1;i>=0;i--){
        if((mask & (1<<i))==0){
            prev=v[i];
            break;
        }
    }
    for(int i=idx+1;i<n;i++){
        if((mask & (1<<i))==0){
            next=v[i];
            break;
        }
    }
    if(prev==0 && next==0) return v[idx];
    else{
        if(prev==0) return next;
        else if(next==0) return prev;
        else return next*prev;
    }
}
int ans,allone;

void find(int sum,int mask){
    if(allone==mask){
        ans=max(ans,sum);
        return;
    }
    for(int i=0;i<n;i++){
        if((mask & (1<<i))==0){
            int newmask=(mask | (1<<i));
            find(sum+getScore(i,newmask),newmask);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    allone=(1<<n)-1;
    for(int i=0;i<n;i++){
        int mask=(1<<i);
        int sum=getScore(i,mask);
        find(sum,mask);
    }
    cout<<ans<<endl;
    return 0;
}
