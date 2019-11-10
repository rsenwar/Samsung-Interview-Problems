
#include<iostream>
using namespace std;

int row,col;
int a[100][100],sol[100][100];
int visited[100][100];

int absdiff(int x,int y) 
{
    int xd=(x>y)?(x-y):(y-x);
    return xd;
}

int fun(int x,int y) 
{
    
    int b=9999;
    int i,j,flag=0,diff=-1;
    
    visited[x][y]=1;
    
    if((y-1)>=0 && a[x][y-1]!=0) 
    {
        if(sol[x][y-1]!=9999) 
        {
            b=sol[x][y-1];
        }
        else if(visited[x][y-1]==0) 
        {
            b=fun(x,y-1);
        }
    }
    if(b<sol[x][y]) 
    {
        sol[x][y]=b;
    }
    
    if((y+1)<col && a[x][y+1]!=0) 
    {
        if(sol[x][y+1]!=9999) 
        {
            b=sol[x][y+1];
        }
        else if(visited[x][y+1]==0) 
        {
            b=fun(x,y+1);
        }
    }
    if(b<sol[x][y]) 
    {
        sol[x][y]=b;
    }
    
    flag=0;
    for(i=x-1;i>=0;i--)
    {
        if(a[i][y]!=0) 
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        diff=absdiff(x,i);
        if(sol[i][y]!=9999) 
        {
            b=sol[i][y];
        }
        else if(visited[i][y]==0) 
        {
            b=fun(i,y);
        }
        if(diff>b) 
        {
            b=diff;
        }
    }
    if(b<sol[x][y]) 
    {
        sol[x][y]=b;
    }
    
    flag=0;
    for(i=x+1;i<col;i++) 
    {
        if(a[i][y]!=0) 
        {
            flag=1;
            break;
        }
    }
    if(flag==1) 
    {
        diff=absdiff(x,i);
        if(sol[i][y]!=9999) 
        {
            b=sol[i][y];
        }
        else if(visited[i][y]==0)
        {
            b=fun(i,y);
        }
        if(diff>b) 
        {
            b=diff;
        }
    }
    if(b<sol[x][y]) 
    {
        sol[x][y]=b;
    }
    
    return sol[x][y];
}
int main() 
{
   
        cin>>row>>col;
        
        for(int i=0;i<row;i++) 
        {
            for(int j=0;j<col;j++) 
            {
                cin>>a[i][j];
                sol[i][j]=9999;
                visited[i][j]=0;
                if(a[i][j]==3) 
                {
                    sol[i][j]=0;
                }
            }
        }
        
        int ans=fun(row-1,0);
        cout<<ans<<endl;
    return 0;
}
