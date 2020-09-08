#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int box[1001][1001];
queue<pair<int, int>> q;
void bfs()
{
    int cr, cc, nr, nc;
    while (!q.empty())
    {
        cr = q.front().first;
        cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m)
            {
                if (box[nr][nc] == 0)
                {
                    box[nr][nc] = box[cr][cc] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
                q.push({i, j});
        }
    }
    bfs();

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (box[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            if (res < box[i][j])
            {
                res = box[i][j];
            }
        }
    }
    cout << res - 1;

    return 0;
}