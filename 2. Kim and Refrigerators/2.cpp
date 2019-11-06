//Recursion + Backtracking
#include <iostream>
#include <math.h>
using namespace std;

int n, sourceX = 0, sourceY = 0, destinationX = 100, destinationY = 100, shortestRoute;
int X[10], Y[10], visited[10];

int getDistance(int x1, int y1, int x2, int y2) {
    int x = x2 - x1;
    int y = y2 - y1;
    int result = abs(x) + abs(y);
    return result;
}

void explore(int current, int cost, int nodeLeft) {
    int i;
    if(nodeLeft <= 1) {
        if(cost + getDistance(X[current], Y[current], destinationX, destinationY) < shortestRoute)
            shortestRoute = cost + getDistance(X[current], Y[current], destinationX, destinationY);
        return;
    }
    // cout << current << ", " << cost << ", " << shortestRoute << endl;
    visited[current] = 1;
    for(i=0;i<n;i++) {
        if(visited[i] == 0)
            explore(i, cost + getDistance(X[current], Y[current], X[i], Y[i]), nodeLeft-1);
    }
    visited[current] = 0;
}

int main() {
    int i, t = 10;
    while (t--) {
        cin >> n;
        cin >> sourceX >> sourceY >> destinationX >> destinationY;
        for(i=0;i<n;i++) {
            cin >> X[i] >> Y[i];
            visited[i] = 0;
        }
        shortestRoute = 1000000;
        for(i=0;i<n;i++) {
            explore(i, getDistance(X[i], Y[i], sourceX, sourceY), n);
        }
        cout << "# " << (10-t) << " " << shortestRoute << endl;
    }
    return 0;
}

