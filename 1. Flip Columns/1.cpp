//Recursion + Backtracking
#include<bits/stdc++.h>
using namespace std;

int n,m,k, a[51][51], ans;

void flip(int i) {
	for(int j=0;j<n;j++)
		if(a[j][i])
			a[j][i] = 0;
		else
			a[j][i] = 1;
}

void find(int kv) {
	if(kv==0) {
		int t_ans = 0;
		for(int i=0;i<n;i++) {
			int f = 0;
			for(int j=0;j<m;j++) {
				if(a[i][j]==0) {
					f = 1;
					break;
				}
			}
			if(f==0)
				t_ans++;
		}
		ans = max(t_ans, ans);
		return;
	}
	for(int i=0;i<m;i++) {
		flip(i);
		find(kv-1);
		flip(i);
	}
}
int main() {
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	find(k);
	cout<<ans;
}
