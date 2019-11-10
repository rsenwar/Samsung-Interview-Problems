#include<iostream>
using namespace std;

int a[20];
int b[20][20];
int min_cost=99999999;

void permutate(int a[], int size, int n){
    if(size==1){
        int cost=0;
        for(int i=0;i<n;i++){
            cost+=b[a[i]-1][a[(i+1)%n]-1];
          //  cout<<a[i]<<" ";
        }
        if(min_cost > cost)
            min_cost=cost;
        
      //  cout<<endl;
        return;
    }
    for(int i=0;i<size;i++){
        permutate(a,size-1,n);

        if(size%2!=0){
            int tem=a[0];
            a[0]=a[size-1];
            a[size-1]=tem;
        }
        else{
            int tem=a[i];
            a[i]=a[size-1];
            a[size-1]=tem;
        }
    }
}


int main()
{    
    int n,t;
    cin>>t;
    while(t--){
        min_cost=99999999;
    cin>>n;
    for(int i=1;i<=n;i++)
        a[i-1]=i;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>b[i][j];
    }

    permutate(a,n,n);
    cout<<min_cost<<endl;
    }

    return 0;
    
}
