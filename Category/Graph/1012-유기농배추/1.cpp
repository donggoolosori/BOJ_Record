#include <iostream>
#include <vector>

using namespace std;

int dc[4] = {-1, 0, 1, 0};
int dr[4] = {0, 1, 0, -1};
int m, n;

bool checkRange(int r, int c)
{
    return (0 <= r && r < n && 0 <= c && c < m);
}

void dfs(int r, int c, vector<vector<int>> &field)
{
    field[r][c] = 0;
    int nr, nc;
    for (int i = 0; i < 4; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if (checkRange(nr, nc) && field[nr][nc] == 1)
        {
            dfs(nr, nc, field);
        }
    }
}

int countBug(int n, int m, vector<vector<int>> &field)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 1)
            {
                cnt++;
                dfs(i, j, field);
            }
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> m >> n >> k;
        int x, y;
        vector<vector<int>> field(n, vector<int>(m, 0));
        while (k--)
        {
            cin >> x >> y;
            field[y][x] = 1;
        }
        int cnt = countBug(n, m, field);
        cout << cnt << '\n';
    }
    return 0;
}