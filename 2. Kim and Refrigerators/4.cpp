#include<iostream>
#include<cmath>
using namespace std;

int a[20];
int b[10][2];
int min_cost=99999999;
int homex,officex,homey,officey;

void permutate(int a[], int size, int n){
    if(size==1){
        int cost=abs(officex-b[a[0]-1][0]) + abs(officey-b[a[0]-1][1]);
        for(int i=0;i<n-1;i++){
            cost+=abs(b[a[i]-1][0]-b[a[i+1]-1][0]) + abs(b[a[i]-1][1]-b[a[i+1]-1][1]);
          //  cout<<a[i]<<" ";
        }
        cost+=abs(homex-b[a[n-1]-1][0]) + abs(homey-b[a[n-1]-1][1]);
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
    t=10;
    int p=t;
    int arr[10][2];

    while(t--){
        min_cost=99999999;
        cin>>n;
    
    for(int i=1;i<=n;i++)
        a[i-1]=i;

        cin>>officex>>officey;
        cin>>homex>>homey;
    for(int i=0;i<n;i++){
            cin>>b[i][0]>>b[i][1];
    }

    permutate(a,n,n);
    cout<<"# "<<p-t<<" "<<min_cost<<endl;
    }

    return 0;
    
}
