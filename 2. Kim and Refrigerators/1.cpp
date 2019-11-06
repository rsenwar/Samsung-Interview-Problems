//Recursion + Backtracking
#include<iostream>
#include<climits>
#include <cstdlib>
#define MAX 2000
using namespace std;
//int a[MAX][2];
int glb_min=INT_MAX;
void permute(int a[][2],int l, int r)
{
    if(l==r)
    {
        int c=0;
        c=c+abs(a[0][0]-a[2][0])+abs(a[0][1]-a[2][1]);
        c=c+abs(a[1][0]-a[r][0])+abs(a[1][1]-a[r][1]);
        for(int i=2;i<r;i++)
        {
            c=c+abs(a[i][0]-a[i+1][0])+abs(a[i][1]-a[i+1][1]);
        }
        glb_min=min(glb_min,c);
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a[i][0],a[l][0]);
            swap(a[i][1],a[l][1]);
            
            permute(a,l+1,r);
            swap(a[i][0],a[l][0]);
            swap(a[i][1],a[l][1]);
        }
    }
}
int main() {
    int t=1;
    while(t<=10)
    {
        int n;
        cin>>n;
        int a[n+2][2];
        cin>>a[0][0]>>a[0][1];
        cin>>a[1][0]>>a[1][1];
        for(int i=2;i<n+2;i++)
            cin>>a[i][0]>>a[i][1];
        glb_min=INT_MAX;
        permute(a,2,n+1);
        cout<<"# "<<t<<" "<<glb_min<<"\n";
        t++;
    }
    
    
    return 0;
}
