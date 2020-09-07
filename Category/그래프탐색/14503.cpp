#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dir_left(int cur)
{
    int res = cur - 1;
    res = res < 0 ? 3 : res;
    return res;
}

int dir_back(int cur)
{
    if (cur < 2)
        return cur + 2;
    else
        return cur - 2;
}

int bfs(int d, int r, int c, int n, int m, vector<vector<int>> map)
{
    int cnt = 1;
    map[r][c] = 2;
    queue<pair<int, pair<int, int>>> q;
    q.push({d, {r, c}});

    int cr, cc;
    int nr, nc;
    int cd, nd;
    while (!q.empty())
    {
        cr = q.front().second.first;
        cc = q.front().second.second;
        cd = q.front().first;
        q.pop();
        nd = cd;
        for (int i = 0; i < 4; i++)
        {
            nd = dir_left(nd);
            nr = cr + dr[nd];
            nc = cc + dc[nd];
            if (map[nr][nc] == 0)
            {
                cnt++;
                map[nr][nc] = 2;
                q.push({nd, {nr, nc}});
                break;
            }
            if (i == 3)
            {
                nd = dir_back(nd);
                nr = cr + dr[nd];
                nc = cc + dc[nd];
                q.push({cd, {nr, nc}});
                if (map[nr][nc] == 1)
                    return cnt;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int r, c, d;
    cin >> r >> c >> d;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    cout << bfs(d, r, c, n, m, map);
    return 0;
}