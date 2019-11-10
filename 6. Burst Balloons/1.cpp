#include<iostream>
using namespace std;
int n,ar[20],visited[20],max_ans;
void fun(int shot,int ans)
{
    if(shot==n)
    {
        // cout<<ans<<"ans"<<endl;
        max_ans=max(max_ans,ans);
        return;
    }
    int cr_ans=ans;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
                visited[i]=1;
                int rf=0,lf=0,rightvalue=1,leftvalue=1;
                for(int j=i-1;j>=0;j--)
                {
                    if(visited[j]==0)
                    {
                        lf=1;
                        leftvalue=ar[j];
                        break;
                    }
                }
                for(int j=i+1;j<n;j++)
                {
                    if(visited[j]==0)
                    {
                        rf=1;
                        rightvalue=ar[j];
                        break;
                    }
                }
                if(lf==1 && rf==1)
                {
                    ans=ans+leftvalue*rightvalue;
                }
                else if(lf==0 && rf==1)
                {
                    ans=ans+rightvalue;
                }
                else if(lf==1 && rf==0)
                {
                    ans=ans+leftvalue;
                }
                else 
                {
                    ans=ans+ar[i];
                }
                fun(shot+1,ans);
                ans=cr_ans;
                visited[i]=0;
               
            
             
            
            
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        visited[i]=0;
    }
    max_ans=-99;
    fun(0,0);
    cout<<max_ans<<endl;
    return 0;
    
}
