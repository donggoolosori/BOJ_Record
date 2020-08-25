#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

int dfs(vector<vector<int>> &map, vector<vector<int>> &dp, int r, int c)
{
    // 도착지에서 도착지로 가는 경우의 수는 1
    if (r == n - 1 && c == m - 1)
        return 1;
    // r,c를 방문한적이 있다면 r,c에서 도착지로 가는 경우의 수는
    // 이미 계산돼있으므로 그냥 반환해준다.
    if (dp[r][c] != -1)
        return dp[r][c];
    dp[r][c] = 0;
    // 4방향의 다음경로를 체크하며
    // dp에 다음경로에서 목적지로 가는 경우의 수인 dp[nr][nc]를 더한다.
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if ((0 <= nr && nr < n) && (0 <= nc && nc < m))
        {
            if (map[nr][nc] < map[r][c])
            {
                dp[r][c] += dfs(map, dp, nr, nc);
            }
        }
    }
    return dp[r][c];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    cout << dfs(map, dp, 0, 0);

    return 0;
}