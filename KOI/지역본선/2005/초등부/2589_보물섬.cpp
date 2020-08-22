#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dist[50][50];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c_row, c_col, n_row, n_col, s_row, s_col;
    int res = 0;
    int n, m;
    cin >> n >> m;
    string *treasure = new string[n];
    for (int i = 0; i < n; i++)
        cin >> treasure[i];

    queue<pair<int, int>> landQ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (treasure[i][j] == 'L')
                landQ.push(make_pair(i, j));
        }
    }

    while (!landQ.empty())
    {
        // 출발 좌표
        s_row = landQ.front().first;
        s_col = landQ.front().second;
        landQ.pop();

        memset(dist, 0, sizeof(dist));

        queue<pair<int, int>> q;
        q.push(make_pair(s_row, s_col));
        while (!q.empty())
        {
            c_row = q.front().first;
            c_col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                n_row = c_row + dr[i];
                n_col = c_col + dc[i];
                if (n_row < 0 || n_row >= n || n_col < 0 || n_col >= m)
                    continue;
                if (treasure[n_row][n_col] == 'W' || (n_row == s_row && n_col == s_col))
                    continue;

                if (!dist[n_row][n_col] || dist[n_row][n_col] > dist[c_row][c_col] + 1)
                {
                    dist[n_row][n_col] = dist[c_row][c_col] + 1;
                    q.push(make_pair(n_row, n_col));
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dist[i][j])
                    res = max(res, dist[i][j]);
    }
    cout << res;
    delete[] treasure;
    return 0;
}