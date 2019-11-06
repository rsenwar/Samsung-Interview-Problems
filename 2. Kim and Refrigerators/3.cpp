#include <iostream>
#include <limits.h>
using namespace std;

int a[15][2], n, ans = INT_MAX;

void find_min_path(int p[]) {
    int t_ans = 0;
		t_ans += abs(a[p[0]][0]-a[0][0]) + abs(a[p[0]][1]-a[0][1]);
    t_ans += abs(a[p[n-1]][0]-a[n+1][0]) + abs(a[p[n-1]][1]-a[n+1][1]);
    for(int i=1;i<n;i++)
					t_ans += abs(a[p[i]][0]-a[p[i-1]][0]) + abs(a[p[i]][1]-a[p[i-1]][1]);
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
    for(int i=0;i<10;i++) {
        cin>>n;
				cin>>a[0][0]>>a[0][1];
				cin>>a[n+1][0]>>a[n+1][1];
        for(int j=1;j<=n;j++)
           cin>>a[j][0]>>a[j][1];
        int p[n];
        for(int j=1;j<=n;j++) 
            p[j-1] = j;
       	ans = INT_MAX;
        comb(p, 0, n-1);
        cout<<"# "<<i+1<<" "<<ans<<endl;
    }
    return 0;
}
