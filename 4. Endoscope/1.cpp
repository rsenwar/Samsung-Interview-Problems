//Recursive
#include <iostream>
using namespace std;
int graph[1000][1000];
int visited[1000][1000];
int answer, n, m;
void explore(int r, int c, int lengthLeft) {
    if(lengthLeft == 0 || graph[r][c] == 0) {
        return;
    }
    // cout << r << "," << c << "  ";
    if(visited[r][c] == 0)
        answer += 1;
    visited[r][c] = 1;
    if(graph[r][c] == 1) {
        if(r-1 >= 0 && (graph[r-1][c]==1 || graph[r-1][c]==2 || graph[r-1][c]==5 || graph[r-1][c]==6))
            explore(r-1, c, lengthLeft-1);
        if(r+1 < n && (graph[r+1][c]==1 || graph[r+1][c]==2 || graph[r+1][c]==4 || graph[r+1][c]==7))
            explore(r+1, c, lengthLeft-1);
        if(c-1 >= 0 && (graph[r][c-1]==1 || graph[r][c-1]==3 || graph[r][c-1]==4 || graph[r][c-1]==5))
            explore(r, c-1, lengthLeft-1);
        if(c+1 < m && (graph[r][c+1]==1 || graph[r][c+1]==3 || graph[r][c+1]==6 || graph[r][c+1]==7))
            explore(r, c+1, lengthLeft-1);
    } else if(graph[r][c] == 2) {
        if(r-1 >= 0 && (graph[r-1][c]==1 || graph[r-1][c]==2 || graph[r-1][c]==5 || graph[r-1][c]==6))
            explore(r-1, c, lengthLeft-1);
        if(r+1 < n && (graph[r+1][c]==1 || graph[r+1][c]==2 || graph[r+1][c]==4 || graph[r+1][c]==7))
            explore(r+1, c, lengthLeft-1);
    } else if(graph[r][c] == 3) {
        if(c-1 >= 0 && (graph[r][c-1]==1 || graph[r][c-1]==3 || graph[r][c-1]==4 || graph[r][c-1]==5))
            explore(r, c-1, lengthLeft-1);
        if(c+1 < m && (graph[r][c+1]==1 || graph[r][c+1]==3 || graph[r][c+1]==6 || graph[r][c+1]==7))
            explore(r, c+1, lengthLeft-1);
    } else if(graph[r][c] == 4) {
        if(r-1 >= 0 && (graph[r-1][c]==1 || graph[r-1][c]==2 || graph[r-1][c]==5 || graph[r-1][c]==6))
            explore(r-1, c, lengthLeft-1);
        if(c+1 < m && (graph[r][c+1]==1 || graph[r][c+1]==3 || graph[r][c+1]==6 || graph[r][c+1]==7))
            explore(r, c+1, lengthLeft-1);
    } else if(graph[r][c] == 5) {
        if(r+1 < n && (graph[r+1][c]==1 || graph[r+1][c]==2 || graph[r+1][c]==4 || graph[r+1][c]==7))
            explore(r+1, c, lengthLeft-1);
        if(c+1 < m && (graph[r][c+1]==1 || graph[r][c+1]==3 || graph[r][c+1]==6 || graph[r][c+1]==7))
            explore(r, c+1, lengthLeft-1);
    } else if(graph[r][c] == 6) {
        if(r+1 < n && (graph[r+1][c]==1 || graph[r+1][c]==2 || graph[r+1][c]==4 || graph[r+1][c]==7))
            explore(r+1, c, lengthLeft-1);
        if(c-1 >= 0 && (graph[r][c-1]==1 || graph[r][c-1]==3 || graph[r][c-1]==4 || graph[r][c-1]==5))
            explore(r, c-1, lengthLeft-1);
    } else if(graph[r][c] == 7) {
        if(r+1 < n && (graph[r+1][c]==1 || graph[r+1][c]==2 || graph[r+1][c]==4 || graph[r+1][c]==7))
            explore(r+1, c, lengthLeft-1);
        if(c-1 >= 0 && (graph[r][c-1]==1 || graph[r][c-1]==3 || graph[r][c-1]==4 || graph[r][c-1]==5))
            explore(r, c-1, lengthLeft-1);
    }
}
int main() {
    int i, j, t, r, c, l;
    cin >> t;
    while(t--) {
        cin >> n >> m >> r >> c >> l;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                cin >> graph[i][j];
                visited[i][j] = 0;
            }
        }
        answer = 0;
        explore(r, c, l);
        cout << answer << endl;
    }
    return 0;
}

