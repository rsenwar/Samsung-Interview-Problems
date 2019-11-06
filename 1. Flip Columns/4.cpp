#include <iostream>
using namespace std;
int n,m,k,ans=0,temp[30][30],arr[30][30];
int flipcost(int prefix[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[i][j] = arr[i][j];
        }
    }
    for(int p=0;p<k;p++){
        for(int i=0;i<n;i++){
            if(temp[i][prefix[p]]==0)
            temp[i][prefix[p]] = 1;
            else temp[i][prefix[p]]=0;
        }
    }
    int cost =0;
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=0;j<m;j++){
           if(temp[i][j]==0){
           flag=false;
           break;
           }
        }
        if (flag==true)
        cost =cost+1;
    }
    return cost;
}
void maxrow(int ind[20],int index){
    if(k==index){
    int cost = flipcost(ind);
    ans = max(ans,cost);
    return;
    }
    for(int i = 0; i < m; i++){
        ind[index] = i;
        maxrow(ind,index+1);
    }
}
int main() {
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ind[k];
    maxrow(ind,0);
    cout<<ans<<endl;
    return 0;
}

