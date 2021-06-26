#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int cnt;
int m, n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool checkNext(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(vector<vector<int>> &area, int y, int x)
{
    area[y][x] = 1;
    cnt++;
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (checkNext(nx, ny) && area[ny][nx] == 0)
        {
            dfs(area, ny, nx);
        }
    }
}
int main()
{
    int k;
    cin >> m >> n >> k;

    vector<vector<int>> area(m, vector<int>(n, 0));
    int area_cnt = 0;
    vector<int> res;
    while (k--)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int i = ly; i < ry; i++)
        {
            for (int j = lx; j < rx; j++)
            {
                area[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (area[i][j] == 0)
            {
                area_cnt++;
                cnt = 0;
                dfs(area, i, j);
                res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << area_cnt << '\n';
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}