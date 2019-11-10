#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[6][5];

bool checkbit(int x, int y){
   // cout<<x<<y<<endl;
    if((x>>y)%2 == 1)
        return true;
    else
        return false;
}


int main() {
    
    int t,n,sx,sy,dx,dy,i,j,k;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>sx>>sy>>dx>>dy;
        for(i=0;i<n;i++){
          cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];  
        }
        for(i=n;i<2*n;i++){
          a[i][0]=a[i-n][2];
          a[i][1]=a[i-n][3];
          a[i][2]=a[i-n][0];
          a[i][3]=a[i-n][1];
          a[i][4]=a[i-n][4];
        }
        int q=2*n;
        int p=pow(2,q);
        //subset generation
        int min_dist=99999999;
        for(i=0;i<p;i++){
        int dist=0;
            int prevx=sx,prevy=sy;
            for(j=0;j<q;j++){
                if(checkbit(i,j)==true){
                    dist+=abs(a[j][0]-prevx) + abs(a[j][1]-prevy) + a[j][4];
                    prevx=a[j][2];
                    prevy=a[j][3];
                }
            }
            dist+=abs(prevx-dx)+abs(prevy-dy);
            if(min_dist > dist)
                min_dist=dist;
        }
        
        cout<<min_dist<<endl;
        
    }
    
    
    return 0;
}
