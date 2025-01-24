// Solution using bitmasking
#include <bits/stdc++.h>
using namespace std;
int mat[20][20];
int ans = 0, n, m;
int chk()
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            c++;
    }
    return c;
}
void show()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            mat[i][j] = x;
        }
    }
    for (int mask = 0; mask < (1 << m); mask++)
    {
        if (__builtin_popcount(mask) > k)
        {
            continue;
        }
        if (__builtin_popcount(mask) % 2 != k % 2)
        {
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            if ((mask >> i) & 1)
            {
                for (int kk = 0; kk < n; kk++)
                {
                    mat[kk][i] = !mat[kk][i];
                }
            }
        }
        ans = max(ans, chk());
        for (int i = 0; i < m; i++)
        {
            if ((mask >> i) & 1)
            {
                for (int kk = 0; kk < n; kk++)
                {
                    mat[kk][i] = !mat[kk][i];
                }
            }
        }
    }
    cout << ans << endl;
}