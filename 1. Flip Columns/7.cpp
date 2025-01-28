// Solution with Bitmasking
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k,ans;
vector<vector<int>>mat;

void print(){
    cout<<"mat: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void flip(int index){
    for(int i=0;i<n;i++){
        mat[i][index]^=1;
    }
}

void check(int mask,int k){
    // cout<<"mask: "<<mask<<" "<<k<<endl;
    if(k==0){
        // print();
        int count=0;
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) flag=false;
            }
            if(flag) count++;
        }
        ans=max(count,ans);
        // cout<<"ans: "<<ans<<endl;
        return;
    }
    else{
        for(int j=0;j<m;j++){
            // if((mask & (1<<j))==0){
                flip(j);
                check(mask|(1<<j),k-1);
                flip(j);
            // }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>m>>k;
    mat.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    ans=0;
    for(int j=0;j<m;j++){
        flip(j);
        check(1<<j,k-1);
        flip(j);
    }
    cout<<ans<<endl;
    return 0;
}
