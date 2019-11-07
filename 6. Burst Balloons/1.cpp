#include <iostream>
using namespace std;

int n, B[20], maxScore = 0, visited[20];
void findScore(int p[]) {
    int i, t, l, r, score = 0;
    for(i=0;i<n;i++) {
        t = p[i];
        visited[t] = 1;
        r = t + 1;
        l = t - 1;
        while(r <= n) {
            if(r == n) {
                r = -1;
                break;
            } else if(visited[r] == 1) {
                r++;
            } else {
                r = B[r];
                break;
            }
        }
        while(l >= -1) {
            if(l == -1) {
                l = -1;
                break;
            } else if(visited[l] == 1) {
                l--;
            } else {
                l = B[l];
                break;
            }
        }
        if(l == -1 && r == -1)
            score += B[t];
        else if(l == -1) {
            score += r;
        } else if(r == -1) {
            score += l;
        } else {
            score += l * r;
        }
    }
    if(score > maxScore) {
        maxScore = score;
    }
}

void permute(int p[], int l, int r) {
    if(l == r) {
        findScore(p);
        for(int i=0;i<n;i++) {
            visited[i] = 0;
        }
        return;
    } else {
        for(int i=l;i<=r;i++) {
            swap(p[i], p[l]);
            permute(p, l+1, r);
            swap(p[i], p[l]);
        }
    }
}

int main() {
    cin >> n;
    int i, p[n];
    for(i=0;i<n;i++) {
        cin >> B[i];
        p[i] = i;
        visited[i] = 0;
    }
    permute(p, 0, n-1);
    cout << maxScore << endl;
    return 0;
}

