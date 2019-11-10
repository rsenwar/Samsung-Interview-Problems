#include <iostream>
using namespace std;
int n, m, map[10][10], visited[10][10], minDifficulty = 11;

// two moves - horizontal and vertical
void climbRock(int i, int j, int maxClimbTillNow) {
    if(i >= n || i < 0)
        return;
    else if(j >= m || j < 0)
        return;
    else if(map[i][j] == 3) {
        // cout << "Destination Reached." << endl;
        if(maxClimbTillNow < minDifficulty)
            minDifficulty = maxClimbTillNow;
    } else if(map[i][j] == 0)
        return;
    else if(visited[i][j] != 0)
        return;
    else {
        visited[i][j] = 1;
        // vertical move up
        int up = i+1, t1 = 0, down = i-1;
        while(up != n && map[up][j] == 0)
            up++;
        // cout << "Climbing Up " << i << " to " << up << " and maxClimbTillNow " << maxClimbTillNow << endl;
        if(up != n && visited[up][j] == 0 && map[up][j] != 0) {
            t1 = up - i;
            if(maxClimbTillNow > t1)
                t1 = maxClimbTillNow;
            // cout << "Climbing Up (" << i << ", " << j << ") to (" << up << ", " << j << ") = " << map[up][j] <<" and maxClimbTillNow " << t1 << endl;
            climbRock(up, j, t1);
        }
        //move down
        while(down != -1 && map[down][j] == 0)
            down--;
        // cout << "Climbing Up " << i << " to " << up << " and maxClimbTillNow " << maxClimbTillNow << endl;
        if(down != -1 && visited[down][j] == 0 && map[down][j] != 0) {
            t1 = i - down;
            if(maxClimbTillNow > t1)
                t1 = maxClimbTillNow;
            // cout << "Climbing Down (" << i << ", " << j << ") to " << down << " and maxClimbTillNow "<< t1 << endl;
            climbRock(down, j, t1);
        }
        //horizontal move
        if((j>=0&&j<m) && (map[i][j+1] == 1 || map[i][j+1] == 3) && (visited[i][j+1] == 0)) {
            climbRock(i, j+1, maxClimbTillNow);
        }
        if((j>=0&&j<m) && (map[i][j-1] == 1 || map[i][j-1] == 3) && (visited[i][j-1] == 0)) {
            climbRock(i, j-1, maxClimbTillNow);
        }
        visited[i][j] = 0;
    }
}

int main() {
    int i, j;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            map[i][j] = visited[i][j] = 0;
    }

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++)
            cin >> map[i][j];
    }
    climbRock(n-1, 0, 0);
    cout << minDifficulty << endl;

    return 0;
}

