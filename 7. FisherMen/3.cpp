// Solution with Bitmasking
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<int>gate(3);
vector<int>people(3);
int allone,ans;

bool valid(int index){
    return 0<=index && index<n;
}

void distributeSeats(int gateNo,int gateMask,int peopleMask,int oldCost){
    // cout<<gateNo<<" "<<gateMask<<" "<<peopleMask<<" "<<oldCost<<endl;
    
    int presentCost=0;
    int index=gate[gateNo];
    int remains=people[gateNo];
    // cout<<"index: "<<index<<" "<<gateNo<<endl;
    if(valid(index) && (peopleMask & (1<<index))==0 && remains>0){
        remains--;
        peopleMask|=(1<<index);
        presentCost+=1;
        // cout<<"OK "<<index<<endl;
    }
    int r=index+1;
    int l=index-1;
    while(remains>0){
        // cout<<r<<": "<<valid(r)<<" "<<l<<": "<<valid(l)<<endl;
        if(valid(r) && remains>0){
            if((peopleMask & (1<<r))==0){
                remains--;
                peopleMask|=(1<<r);
                presentCost+=(1+r-index);   
                // cout<<"right"<<endl;
            }
            r++;
        }

        if(valid(l) && remains>0){
            if((peopleMask & (1<<l))==0){
                remains--;
                peopleMask|=(1<<l);
                presentCost+=(1+index-l);
                // cout<<"left"<<endl;
            }
            l--;
        }
    }
    
    if(gateMask==allone){
        // cout<<"Found"<<endl;
        ans=min(ans,oldCost+presentCost);
        return;
    }
    
    for(int i=0;i<3;i++){
        if((gateMask & (1<<i))==0) distributeSeats(i,(gateMask | (1<<i)),peopleMask,oldCost+presentCost);
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    for(int i=0;i<3;i++) cin>>gate[i],gate[i]--;
    for(int i=0;i<3;i++) cin>>people[i];
    allone=(1<<3)-1,ans=1e9;
    for(int i=0;i<3;i++){
        distributeSeats(i,(1<<i),0,0);
    }
    cout<<ans<<endl;
    return 0;
}
