#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[20][20];
int m,n,max_row=0;
void flip(int i){
    for(int j=0;j<n;j++){
        if(a[j][i]==0)
            a[j][i]=1;
        else
            a[j][i]=0;
    }
}

void solve(int k){
    if(k==0){
        int row_count=0;
        for(int x=0;x<n;x++){
            int count=0;
            for(int y=0;y<m;y++){
                if(a[x][y]==1)
                    count++;
            }
            if(count==m)
                row_count++;
        }
        if(row_count > max_row)
            max_row=row_count;
        return;
    }
    for(int i=0;i<m;i++){
        flip(i);
        solve(k-1);
        flip(i); //backtracking
    }
}

int main() {
    int k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    solve(k);
    cout<<max_row<<endl;
    return 0;
}
