#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;
int a[MAX][MAX];
void func(int x,int y,int c,int ra,int n,int m)
{
    //cout<<x<<" "<<y<<"\n";
    if(c>=ra)
        return;
    if(a[x][y]==1 ||a[x][y]==-1 && c<ra)
    {
        if(a[x][y]==1)
            a[x][y]=-1;
        if(x+1<n && abs(a[x+1][y])==1 || abs(a[x+1][y])==2 || abs(a[x+1][y])==4|| abs(a[x+1][y])==7)
            func(x+1,y,c+1,ra,n,m);
        if(x-1>=0 && abs(a[x-1][y])==1 || abs(a[x-1][y])==2 || abs(a[x-1][y])==6|| abs(a[x-1][y])==5)
            func(x-1,y,c+1,ra,n,m);
        if(y-1>=0 && abs(a[x][y-1])==1 || abs(a[x][y-1])==3 || abs(a[x][y-1])==5|| abs(a[x][y-1])==4)
            func(x,y-1,c+1,ra,n,m);
        if(y+1<m && abs(a[x][y+1])==1 || abs(a[x][y+1])==3 || abs(a[x][y+1])==6|| abs(a[x][y+1])==7)
            func(x,y+1,c+1,ra,n,m); 
    }
    else if(a[x][y]==2 ||a[x][y]==-2 && c<ra)
    {
        if(a[x][y]==2)
            a[x][y]=-2;
        if(x-1>=0 && abs(a[x-1][y])==1 || abs(a[x-1][y])==2 || abs(a[x-1][y])==6|| abs(a[x-1][y])==5)
            func(x-1,y,c+1,ra,n,m);
        if(x+1<n && abs(a[x+1][y])==1 || abs(a[x+1][y])==2 || abs(a[x+1][y])==4|| abs(a[x+1][y])==7)
            func(x+1,y,c+1,ra,n,m);

    }
    else if((a[x][y]==3 ||a[x][y]==-3) && c<ra)
    {
        if(a[x][y]==3)
            a[x][y]=-3;
        if(y-1>=0 && abs(a[x][y-1])==1 || abs(a[x][y-1])==3 || abs(a[x][y-1])==5|| abs(a[x][y-1])==4)
            func(x,y-1,c+1,ra,n,m);
        if(y+1<m && abs(a[x][y+1])==1 || abs(a[x][y+1])==3 || abs(a[x][y+1])==6|| abs(a[x][y+1])==7)
            func(x,y+1,c+1,ra,n,m);

    }
    else if(a[x][y]==4 ||a[x][y]==-4 && c<ra)
    {
        if(a[x][y]==4)
            a[x][y]=-4;
        if(x-1>=0 && abs(a[x-1][y])==1 || abs(a[x-1][y])==2 || abs(a[x-1][y])==6|| abs(a[x-1][y])==5)
            func(x-1,y,c+1,ra,n,m);
        if(y+1<m && abs(a[x][y+1])==1 || abs(a[x][y+1])==3 || abs(a[x][y+1])==6|| abs(a[x][y+1])==7)
            func(x,y+1,c+1,ra,n,m);        
    }
    else if(a[x][y]==5 ||a[x][y]==-5 && c<ra)
    {
        if(a[x][y]==5)
            a[x][y]=-5;
        if(y+1<m && abs(a[x][y+1])==1 || abs(a[x][y+1])==3 || abs(a[x][y+1])==6|| abs(a[x][y+1])==7)
            func(x,y+1,c+1,ra,n,m);
        if(x+1<n && abs(a[x+1][y])==1 || abs(a[x+1][y])==2 || abs(a[x+1][y])==4|| abs(a[x+1][y])==7)
            func(x+1,y,c+1,ra,n,m);        

    }
    else if(a[x][y]==6 ||a[x][y]==-6 && c<ra)
    {
        if(a[x][y]==6)
            a[x][y]=-6;
        if(y-1>=0 && abs(a[x][y-1])==1 || abs(a[x][y-1])==3 || abs(a[x][y-1])==5|| abs(a[x][y-1])==4)
            func(x,y-1,c+1,ra,n,m);
        if(x+1<n && abs(a[x+1][y])==1 || abs(a[x+1][y])==2 || abs(a[x+1][y])==4|| abs(a[x+1][y])==7)
            func(x+1,y,c+1,ra,n,m);
        
    }
    else if(a[x][y]==7 ||a[x][y]==-7 && c<ra)
    {
        if(a[x][y]==7)
            a[x][y]=-7;
        if(y-1>=0 && abs(a[x][y-1])==1 || abs(a[x][y-1])==3 || abs(a[x][y-1])==5|| abs(a[x][y-1])==4)
            func(x,y-1,c+1,ra,n,m);
        if(x-1>=0 && abs(a[x-1][y])==1 || abs(a[x-1][y])==2 || abs(a[x-1][y])==6|| abs(a[x-1][y])==5)
            func(x-1,y,c+1,ra,n,m);
    }
    else
        return;
}
int main() {
   int n,m,x,y,ra,t;
    cin>>t;
    while(t-->0)
    {
        cin>>n>>m>>x>>y>>ra;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        func(x,y,0,ra,n,m);
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(a[i][j]<0)
                    c++;
        }
        cout<<c<<"\n";
    }
    
    return 0;
}
