#include<iostream>
using namespace std;
int worm[20][5],n,sx,sy,dx,dy,ans;
int distance(int sx,int sy,int dx,int dy)
{
    int xd=(sx>dx)?(sx-dx):(dx-sx);
    int yd=(sy>dy)?(sy-dy):(dy-sy);
    return xd+yd;
}
void process(int sx,int sy,int dx,int dy,int used,int value )
{
    ans=min(ans,distance(sx,sy,dx,dy)+value);
    if(used==0)
    return;
    for(int i=0;i<n;i++)
    {
        if(used & (1<<i))
        {
            int x=distance(sx,sy,worm[i][0],worm[i][1])+worm[i][4];
            int y=distance(sx,sy,worm[i][2],worm[i][3])+worm[i][4];
            if(x<y)
            {
                process(worm[i][2],worm[i][3],dx,dy,(used ^( 1<<i)),value+x);
            }
            else
            {
                
                process(worm[i][0],worm[i][1],dx,dy,(used ^ (1<<i)),value+y);
            }
            
        }
    }

}

int main()
{
    int t,index=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>sx>>sy>>dx>>dy;
        for(int i=0;i<n;i++)
        {
            cin>>worm[i][0]>>worm[i][1]>>worm[i][2]>>worm[i][3]>>worm[i][4];
        }
        ans=99999;
        process(sx,sy,dx,dy,((1<<n)-1),0);
        cout<<ans<<endl;
    }
    return 0;
}
