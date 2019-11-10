#include<iostream>
#include<queue>
#define qSize 100
using namespace std;
int arr[51][51];
int a[51][51];

struct positions
{
    int x, y;
};

positions Queue[qSize];

int front, rear;

void Push(int x, int y)
{
    Queue[rear].x = x;
    Queue[rear].y = y;
    rear++;
}
positions Pop()
{
    return Queue[front++];
}
int Up[8] = { 0, 1, 1, 0, 1, 0, 0, 1 };
int Down[8] = { 0, 1, 1, 0, 0, 1, 1, 0 };
int Left[8] = { 0, 1, 0, 1, 0, 0, 1, 1 };
int Right[8] = { 0, 1, 0, 1, 1, 1, 0, 0 };

int matrix[qSize][qSize], nodeDist[qSize][qSize];

int visited[qSize][qSize];

int row, col, startX, startY, length, maxVisitedCell;

int main(){
    int t,n,m,r,c,l,x;
    cin>>t;
    while(t--){
        cin>>row>>col>>startX>>startY>>length;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>matrix[i][j];
                visited[i][j] = nodeDist[i][j] = 0;
                }

            }
    front = rear = 0;
    maxVisitedCell = 0;
    if (matrix[startX][startY]!=0)
        {
            visited[startX][startY] = 1;
            nodeDist[startX][startY] = 1;
            Push(startX, startY);
        }

    while (!(front == rear))
        {
            positions curr = Pop();

            int x = curr.x;
            int y = curr.y;

            maxVisitedCell++;

            int dist = nodeDist[x][y] + 1;

            if (dist > length)
            {
                continue;
            }

            if (x - 1 >= 0 && Up[matrix[x][y]] && Down[matrix[x - 1][y]] && !visited[x - 1][y])
            {
                visited[x - 1][y] = 1;
                nodeDist[x - 1][y] = dist;
                Push(x - 1, y);
            }

            if (x + 1 < row && Down[matrix[x][y]] && Up[matrix[x + 1][y]] && !visited[x + 1][y])
            {
                visited[x + 1][y] = 1;
                nodeDist[x + 1][y] = dist;
                Push(x + 1, y);
            }

            if (y - 1 >= 0 && Left[matrix[x][y]] && Right[matrix[x][y - 1]] && !visited[x][y - 1])
            {
                visited[x][y - 1] = 1;
                nodeDist[x][y - 1] = dist;
                Push(x, y - 1);
            }

            if (y + 1 < col && Right[matrix[x][y]] && Left[matrix[x][y + 1]] && !visited[x][y + 1])
            {
                visited[x][y + 1] = 1;
                nodeDist[x][y + 1] = dist;
                Push(x, y + 1);
            }

        }
        cout<< maxVisitedCell<<endl;
    }

    return 0;
}

