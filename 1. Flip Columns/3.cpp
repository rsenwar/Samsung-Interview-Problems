//O(N^2) Solution using Hashing
#include<bits/stdc++.h>
using namespace std;

int a[1001][1001];

int getNum(int A[],int m)
{
    int sum = 0;
    int c = 0;
    for(int i=m-1;i>=0;i--)
    {
        sum = sum + A[i]*pow(2,c);
        c+=1;
    }
    sum += pow(2,c);
    return sum;
}
int getZeros(int x)
{
    int c = 0;
    
    while(x){
        if(x%2==0)
            c++;
        x/=2;
    }
    return c;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    int num[10001]={0};
    for(int i=0;i<n;i++)
    {
        int x = getNum(a[i],m);
        // cout << x << endl;
        num[x]++;
    }
    int ans = 0;
    for(int i=0;i<500;i++)
    {
        if(num[i]>0)
        {
            int x = getZeros(i);
            if( x<=k )
            {
                if(k%x==0)
                    ans = max(ans,num[i]);
            }
        }
    }
    cout << ans << endl;

}
