#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
    int r, c, d;
};
int n, m, sr, sc, dir;
int map[51][51];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int cnt;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> sr >> sc >> dir;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
}

int getLeftDir(int d)
{
    int leftDir = d - 1;
    leftDir = leftDir < 0 ? 3 : leftDir;
    return leftDir;
}

int getBackDir(int d)
{
    int backDir = d + 2;
    backDir = backDir > 3 ? backDir - 4 : backDir;
    return backDir;
}

void bfs()
{
    queue<Pos> q;
    q.push({sr, sc, dir});
    map[sr][sc] = 2;
    cnt++;

    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        int r = cur.r, c = cur.c, d = cur.d;
        int nr, nc, nd = d;
        for (int i = 0; i < 4; i++)
        {
            nd = getLeftDir(nd);
            nr = r + dr[nd];
            nc = c + dc[nd];
            if (map[nr][nc] == 0)
            {
                map[nr][nc] = 2;
                cnt++;
                q.push({nr, nc, nd});
                break;
            }
            if (i == 3)
            {
                nd = getBackDir(nd);
                nr = r + dr[nd];
                nc = c + dc[nd];
                if (map[nr][nc] == 1)
                    return;
                q.push({nr, nc, d});
            }
        }
    }
}

void solve()
{
    bfs();
    cout << cnt << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}