#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[50][50],n,m;
int vis[50][50]={0};

void DFS(int xpos,int ypos,int rem_len){
    if(xpos<0 || xpos>=n || ypos<0 || ypos>=m || rem_len==0)
        return;
    vis[xpos][ypos]=1;
    if(a[xpos][ypos] == 1){
        if((xpos!=0) && (a[xpos-1][ypos] ==2 || a[xpos-1][ypos] ==5 || a[xpos-1][ypos] ==6 || a[xpos-1][ypos] ==1))  //up
            DFS(xpos-1, ypos, rem_len-1);
        if((xpos!=n-1) && (a[xpos+1][ypos] ==2 || a[xpos+1][ypos] ==4 || a[xpos+1][ypos] ==7 || a[xpos+1][ypos] ==1)) //down
            DFS(xpos+1, ypos, rem_len-1);

        if((ypos!=0)&& (a[xpos][ypos-1] ==3 || a[xpos][ypos-1] ==4 || a[xpos][ypos-1] ==5 || a[xpos][ypos-1] ==1))     //left
            DFS(xpos, ypos-1, rem_len-1);
        if((ypos!=m-1) && (a[xpos][ypos+1] ==3 || a[xpos][ypos+1] ==6 || a[xpos][ypos+1] ==7 || a[xpos][ypos+1] ==1))   //right
            DFS(xpos, ypos+1, rem_len-1);
        
    }
    else if(a[xpos][ypos] == 2){
        if((xpos!=0) && (a[xpos-1][ypos] ==1 || a[xpos-1][ypos] ==5 || a[xpos-1][ypos] ==6 || a[xpos-1][ypos] ==2))    //up
            DFS(xpos-1, ypos, rem_len-1);
        if((xpos!=n-1) && (a[xpos+1][ypos] ==1 || a[xpos+1][ypos] ==4 || a[xpos+1][ypos] ==7 || a[xpos+1][ypos] ==2))  //down
            DFS(xpos+1, ypos, rem_len-1);
        
    }
    else if(a[xpos][ypos] == 3){
        if((ypos!=0)&& (a[xpos][ypos-1] ==1 || a[xpos][ypos-1] ==4 || a[xpos][ypos-1] ==5 || a[xpos][ypos-1] ==3))     //left
            DFS(xpos, ypos-1, rem_len-1);
        if((ypos!=m-1) && (a[xpos][ypos+1] ==1 || a[xpos][ypos+1] ==6 || a[xpos][ypos+1] ==7 || a[xpos][ypos+1] ==3))   //right
            DFS(xpos, ypos+1, rem_len-1);
        
    }
    else if(a[xpos][ypos] == 4){
        if((xpos!=0) && (a[xpos-1][ypos] ==1 || a[xpos-1][ypos] ==2 || a[xpos-1][ypos] ==5 || a[xpos-1][ypos] ==6))    //up
            DFS(xpos-1, ypos, rem_len-1);  
        if((ypos!=m-1) && (a[xpos][ypos+1] ==1 || a[xpos][ypos+1] ==3 || a[xpos][ypos+1] ==6 || a[xpos][ypos+1] ==7))   //right
            DFS(xpos, ypos+1, rem_len-1);
        
    }
    else if(a[xpos][ypos] == 5){
        if((xpos!=n-1) && (a[xpos+1][ypos] =1 || a[xpos+1][ypos] ==2 || a[xpos+1][ypos] ==7 || a[xpos+1][ypos] ==4))  //down
            DFS(xpos+1, ypos, rem_len-1);
        if((ypos!=m-1) && (a[xpos][ypos+1] ==1 || a[xpos][ypos+1] ==3 || a[xpos][ypos+1] ==6 || a[xpos][ypos+1] ==7))   //right
            DFS(xpos, ypos+1, rem_len-1);
        
    }
    else if(a[xpos][ypos] == 6){
        if((xpos!=n-1) && (a[xpos+1][ypos] ==1 || a[xpos+1][ypos] ==2 || a[xpos+1][ypos] ==7 || a[xpos+1][ypos] ==4))  //down
            DFS(xpos+1, ypos, rem_len-1);
        if((ypos!=0)&& (a[xpos][ypos-1] ==1 || a[xpos][ypos-1] ==3 || a[xpos][ypos-1] ==5 || a[xpos][ypos-1] ==4))     //left
            DFS(xpos, ypos-1, rem_len-1);
        
    }
    else if(a[xpos][ypos] == 7){
        if((xpos!=0) && (a[xpos-1][ypos] ==1 || a[xpos-1][ypos] ==2 || a[xpos-1][ypos] ==5 || a[xpos-1][ypos] ==6))    //up
            DFS(xpos-1, ypos, rem_len-1);
        if((ypos!=0)&& (a[xpos][ypos-1] ==1 || a[xpos][ypos-1] ==3 || a[xpos][ypos-1] ==4 || a[xpos][ypos-1] ==5))     //left
            DFS(xpos, ypos-1, rem_len-1);
        
    }
}


int main() {
    int t,i,j,k,x,y,l;
    cin>>t;
    while(t--){
        
       cin>>n>>m>>x>>y>>l;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                cin>>a[i][j];
        }
        
        DFS(x,y,l);
        int count=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
              //  cout<<vis[i][j]<<" ";
                if(vis[i][j]==1){
                     count++;
                    vis[i][j]=0;
                }
                   
            }
         //   cout<<endl;
        }
        cout<<count<<endl;
    }
    return 0;
}
