#include <queue>
#include <algorithm>
#include <iostream>
#define MAX 1001

using namespace std;

int n, m;
const int dr[4] = {0, -1, 0, 1};
const int dc[4] = {1, 0, -1, 0};
char map[MAX][MAX];
int dist[MAX][MAX][2];

struct rcw
{
    int r, c, w;
};

int bfs()
{
    int r, c, w, nr, nc;
    queue<rcw> q; // {row,col,벽 부순 여부}

    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        r = q.front().r;
        c = q.front().c;
        w = q.front().w;

        q.pop();
        if (r == n - 1 && c == m - 1)
        {
            return dist[r][c][w];
        }
        for (int i = 0; i < 4; i++)
        {
            nr = r + dr[i];
            nc = c + dc[i];
            if (0 > nr || nr >= n || 0 > nc || nc >= m)
                continue;
            if (dist[nr][nc][w])
                continue;
            if (map[nr][nc] == '0')
            {
                dist[nr][nc][w] = dist[r][c][w] + 1;
                q.push({nr, nc, w});
            }
            else if (map[nr][nc] == '1' && w == 0)
            {
                dist[nr][nc][1] = dist[r][c][w] + 1;
                q.push({nr, nc, 1});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    int res = bfs();
    cout << res;

    return 0;
}