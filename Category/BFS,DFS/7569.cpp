#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int box[101][101][101];
int m, n, h;
queue<pair<int, pair<int, int>>> q;
int dr[] = {-1, 0, 1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};

void bfs()
{
    int cur_h, cur_r, cur_c;
    int next_h, next_r, next_c;
    pair<int, pair<int, int>> cur;
    while (!q.empty())
    {
        cur = q.front();
        cur_h = cur.first;
        cur_r = cur.second.first;
        cur_c = cur.second.second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            next_h = cur_h + dh[i];
            next_r = cur_r + dr[i];
            next_c = cur_c + dc[i];
            if ((0 <= next_h && next_h < h) && (0 <= next_r && next_r < n) && (0 <= next_c && next_c < m))
            {
                if (box[next_h][next_r][next_c] == 0)
                {
                    box[next_h][next_r][next_c] = box[cur_h][cur_r][cur_c] + 1;
                    q.push({next_h, {next_r, next_c}});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> box[k][i][j];
                if (box[k][i][j] == 1)
                {
                    q.push({k, {i, j}});
                }
            }
        }
    }
    bfs();

    int res = 0;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (box[k][i][j] == 0)
                {
                    cout << -1;
                    return 0;
                }
                if (box[k][i][j] > res)
                    res = box[k][i][j];
            }
        }
    }
    cout << res - 1;
    return 0;
}