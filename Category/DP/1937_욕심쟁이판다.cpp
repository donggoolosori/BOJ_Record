#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int ans = 0;
int bamboo[500][500];
int dp[500][500];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

int eat_bamboo(int y, int x)
{
    if (dp[y][x])
        return dp[y][x];

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if (bamboo[y][x] >= bamboo[ny][nx])
            continue;
        dp[y][x] = max(dp[y][x], eat_bamboo(ny, nx) + 1);
    }
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> bamboo[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, eat_bamboo(i, j));
        }
    }

    cout << ans;

    return 0;
}