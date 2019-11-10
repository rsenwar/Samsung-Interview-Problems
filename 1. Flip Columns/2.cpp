// O(N^3) Solution
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int i, j, k, n, m, maxMove;
    cin >> n >> m >> maxMove;
    int matrix[n][m];
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin >> matrix[i][j];
        }
    }
    int alreadyEqual = 0;
    int list[n];
    memset(list, 0, n*sizeof(int));
    for(i=0;i<n;i++) {
        int flag = 1;
        if(matrix[i][0] == 0) {
            flag = 0;
        } else {
            for(j=0;j<m;j++) {
                if(matrix[i][j] != matrix[i][0]) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1) {
            alreadyEqual++;
        }
    }

    for(i=0;i<n;i++) {
        if(list[i] == -1)
            continue;
        for(j=i+1;j<n;j++) {
            int flag = 1;
            for(k=0;k<m;k++) {
                if(matrix[i][k] != matrix[j][k]) {
                    flag = 0;
                }
                if(flag == 0)
                    break;
            }
            if(flag == 1) {
                // cout << "Row " << i << " and " << j << " are similiar" << endl;
                list[i]++;
                list[j] = -1;
            }
        }
    }

    for(i=0;i<n;i++) {
        // cout << list[i].size() << endl;
        int zero = 0, ones = 0;
        for(j=0;j<m;j++) {
            if(matrix[i][j] == 1)
                ones++;
        }
        zero = m - ones;
        if(list[i]+1 > alreadyEqual && (maxMove-zero)%2==0)
            alreadyEqual = list[i]+1;
    }
    cout << alreadyEqual << endl;

    return 0;
}
