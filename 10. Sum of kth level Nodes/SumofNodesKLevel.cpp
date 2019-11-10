#include <iostream>
#include <cstring>
using namespace std;
int binaryTree[1050];
char str[1050];
bool visited[1050];
int main() {
    int i, k, counter = 0, l = 0, r = 1;
    cin >> k;
    memset(binaryTree, 0, 1050*sizeof(int));
    memset(visited, false, 1050);
    cin >> str;
    i = 1;
    counter = 1;
    while(str[i] != '\0') {
        if(str[i] == '(') {
            counter = 2 * counter;
            if(visited[counter] == true)
                counter++;
            visited[counter] = true;
        } else if(str[i] == ')') {
            counter = counter / 2;
        } else {
            int temp = binaryTree[counter];
            temp = temp*10 + (int)(str[i] - 48);
             binaryTree[counter] = temp;
        }
        // cout << counter << " ";
        i++;
    }
    // cout << endl;
    // for(i=1;i<=11;i++) {
    //     cout << binaryTree[i] << " ";
    // }
    // cout << endl;
    l = r = 1;
    while(k--) {
        l = l * 2;
    }
    counter = 0;
    r = l * 2;
    for(i=l;i<r;i++) {
        counter += binaryTree[i];
    }
    cout << counter << endl;
    return 0;
}
