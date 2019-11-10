#include <iostream>
#include <math.h>
using namespace std;
int sourceX = 0, sourceY = 0, destinationX = 100, destinationY = 100, minTime;
int X[30], Y[30], X2[30], Y2[30], costWormhole[30], n;

int getDistance(int x1, int y1, int x2, int y2) {
    int result = abs(x1 - x2) + abs(y1 - y2);
    return result;
}

void find_min_path(int p[], int l2, int r) {
    int t_ans = 0;
    t_ans += getDistance(sourceX, sourceY, X[p[l2]], Y[p[l2]]);
    // cout << t_ans << " ";
    for(int i=l2;i<=r;i++) {
        // cout << i << " ";
        t_ans += costWormhole[i];
        if(i+1 <= r) {
            t_ans += getDistance(X2[p[i]], Y2[p[i]], X[p[i+1]], Y[p[i+1]]);
        }
    }
    t_ans += getDistance(X2[p[r]], Y2[p[r]], destinationX, destinationY);
    // cout << t_ans << endl;
    if(t_ans < minTime)
        minTime = t_ans;
}

void permute(int p[], int l, int r, int l2) {
    if(l > r) {
        return;
    }
    if(l == r) {
        find_min_path(p, l2, r);
        return;
    } else {
        for(int i=l;i<=r;i++) {
            swap(p[i], p[l]);
            permute(p, l+1, r, l2);
            swap(p[i], p[l]);
        }
    }
}

int main() {
    int t, i, j, k;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> sourceX >> sourceY >> destinationX >> destinationY;
        for(i=0;i<n;i++) {
            cin >> X[i] >> Y[i] >> X2[i] >> Y2[i] >> costWormhole[i];
        }
        for(; i<2*n;i++) {
            X[i] = X2[i-n];
            Y[i] = Y2[i-n];
            X2[i] = X[i-n];
            Y2[i] = Y[i-n];
            costWormhole[i] = costWormhole[i-n];
        }
        n = 2 * n;
        int p[n];
        for(i=0;i<n;i++)
            p[i] = i;

        minTime = getDistance(sourceX, sourceY, destinationX, destinationY);
        // first loop no of wormhole used
        for(i=1;i<=n;i++) {
            // second loop for chosing those wormhole
            // cout << "Wormhole Used " << i << " :  " << endl;
            for(j=0;j<n;j++) {
                if(j+i-1 < n) {
                    permute(p, j, j+i-1, j);
                }
            }
        }
        cout << minTime << endl;
    }
    return 0;
}

