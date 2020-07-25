#include <bits/stdc++.h>
using namespace std;

bool w[105][105];
bool vis[105][105];
int col[] = {0, 1, 1, 1, 0, -1, -1, -1};
int row[] = {1, 1, 0, -1, -1, -1, 0, 1};
int n, m;
void find(int y, int x)
{
    vis[y][x] = 1;
    for (int i = 0; i < 8; ++i)
    {
        int xx = x + col[i];
        int yy = y + row[i];
        if (yy >= 0 && yy < n && xx >= 0 && xx < m && !vis[yy][xx] && w[yy][xx] == 1)
        {
            find(yy, xx);
        }
    }
   
}
int main()
{
    // freopen("data.inp", "r", stdin);
    // freopen("data.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char ch;
            cin >> ch;
            if (ch == 'W')
            {
                w[i][j] = 1;
                vis[i][j] = 0;
            }
            else
            {
                w[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (w[i][j] == 1 && !vis[i][j])
            {
                ++cnt;
                find(i, j);
            }
        }
    }
    cout << cnt << "\n";
}
