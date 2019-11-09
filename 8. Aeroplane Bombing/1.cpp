#include<iostream>
using namespace std;

void maxCoins(int arr[][5],int crow,int ccol,int temp,int &ans,int bomb,int effect){
	if(crow == -1){
		if(temp > ans){
			ans = temp;
		}
		return;
	}
	for(int i=-1;i<=1;i++){
		if((ccol+i) < 0 || (ccol+i) > 4)
			continue;
		if(arr[crow][ccol+i] == 1 || arr[crow][ccol+i] == 0){//No enemy
			if(bomb == 0){
				maxCoins(arr,crow-1,ccol+i,temp+arr[crow][ccol+i],ans,bomb,effect-1);//If bomb has already been used, reduce its effect by 1
			}else{
				maxCoins(arr,crow-1,ccol+i,temp+arr[crow][ccol+i],ans,bomb,effect);
			}
			
		}else{//Enemy
			if(bomb == 0){
				if(effect > 0){
					maxCoins(arr,crow-1,ccol+i,temp,ans,bomb,effect-1);//Bomb already used so can pass but effect reduces by 1
				}
			}else{
				maxCoins(arr,crow-1,ccol+i,temp,ans,0,5); //Use bomb ans set effect for five rows
			}
		}
	}
	return;
}

int main(){
	int arr[20][5],ans,t,n;
	cin>>t;
	for(int _=1;_<=t;_++) {
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				cin >> arr[i][j];
			}
		}
	ans = 0;
	maxCoins(arr,n-1,2,0,ans,1,0);
	cout <<"#"<<_<<" "<< ans;
	}
	return 0;
}
