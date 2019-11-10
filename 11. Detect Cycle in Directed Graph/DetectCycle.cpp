#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, graph[11][11], answer[11], answerSize = -1;
int stack[15], top = -1, visited[11], sumCycle = 999999;

void detectCycle(int current) {
    if(visited[current] == 1 && top != -1) {
        int i, localSum = stack[top];
        for(i=top-1;i>=0 && stack[i]!=current;i--) {
            localSum += stack[i];
        }
        // cout << i << " - " << localSum << endl;
        if(i != -1 && localSum < sumCycle) {
            answerSize = -1;
            sumCycle = localSum;
            answer[++answerSize] = stack[top];
            for(i=top-1;i>=0 && stack[i]!=current;i--) {
                answer[++answerSize] = stack[i];
                // cout << stack[i] << " ";
            }
            // cout << endl;
        }
        return;
    } else {
        int i;
        visited[current] = 1;
        for(i=1;i<=n;i++) {
            if(graph[current][i] == 1) {
                stack[++top] = i;
                // cout << "Pushing " << i << endl;
                detectCycle(i);
                top--;
                // cout << "Popping " << stack[top+1] << endl;
            }
        }
        visited[current] = 0;
    }
}

int main() {
    int i, j, t1, t2;
    cin >> n >> m;
    memset(&graph[0][0], 0, n*n*sizeof(int));
    memset(visited, 0, 11*sizeof(int));
    while(m--) {
        cin >> t1 >> t2;
        graph[t1][t2] = 1;
    }
    for(i=1;i<=n;i++) {
        if(visited[i] == 0) {
            stack[++top] = i;
            // cout << "Pushing " << i << endl;
            detectCycle(i);
            top--;
            // cout << "Popping " << stack[top+1] << endl;
        }
    }
    sort(answer, answer+answerSize+1);
    for(i=0; i<=answerSize; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}
