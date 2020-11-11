#include <iostream>
#include <vector>
#define max(a, b) a > b ? a : b

using namespace std;

int n, m;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
vector<vector<int>> map(9, vector<int>(9));
int ans;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
}

void spreadVirus(int r, int c, vector<vector<int>> &temp)
{
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= n || nr < 0 || nc >= m || nc < 0)
            continue;
        if (temp[nr][nc] == 0)
        {
            temp[nr][nc] = 2;
            spreadVirus(nr, nc, temp);
        }
    }
}

void countSateArea()
{
    vector<vector<int>> temp(map);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 2)
            {
                spreadVirus(i, j, temp);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}

void setWall(int L)
{
    if (L == 3)
    {
        countSateArea();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                setWall(L + 1);
                map[i][j] = 0;
            }
        }
    }
}

void solve()
{
    setWall(0);
    cout << ans << '\n';
}

int main()
{
    input();
    solve();
    return 0;
}