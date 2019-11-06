#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int minCost = 1000000, n;
int matrix[15][15];

void explore(int current, int *visited, int cost, int nodeLeft) {
    if(nodeLeft == 0) {
        cost += matrix[current][0];
        if(cost < minCost)
            minCost = cost;
        return;
    }

    for(int i=1;i<n;i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            explore(i, visited, cost + matrix[current][i], nodeLeft - 1);
            visited[i] = 0;
        }
    }
}
int main() {
    int i, j, t;
    cin >> t;
    while(t--) {
        cin >> n;
        minCost = 1000000;

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                cin >> matrix[i][j];
            }
        }
        int visited[15];
        memset(visited, 0, 15*sizeof(int));
        visited[0] = 1;
        explore(0, visited, 0, n-1);
        cout << minCost << endl;
    }
    return 0;
}

