#include <iostream>
#include <limits.h>
using namespace std;

int a[12][12], n, ans = INT_MAX;

void find_min_path(int p[]) {
    int t_ans = 0;
    t_ans += a[0][p[0]];
    t_ans += a[p[n-2]][0];
    for(int i=0;i<n-2;i++)
        t_ans += a[p[i]][p[i+1]];
    ans = min(ans, t_ans);
}
void comb(int p[], int i, int j) {
    if(i==j) {
        find_min_path(p);
        return;
    } else {
        for(int q=i;q<=j;q++) {
            swap(p[q], p[i]);
            comb(p, i+1, j);
            swap(p[q], p[i]);
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    cin>>n;
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            cin>>a[i][j];
	    int p[n-1];
	    for(int i=0;i<n-1;i++) 
	        p[i] = i+1;
	   ans = INT_MAX;
	    comb(p, 0, n-2);
	    cout<<ans<<endl;
	}
	return 0;
}
