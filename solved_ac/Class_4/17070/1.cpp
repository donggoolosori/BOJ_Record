#include <iostream>

using namespace std;

int n, ans;
int house[17][17];

// 방향 : 오른쪽, 아래, 대각선
int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> house[i][j];
}

// type : 가로=0, 세로=1, 대각선=2
void dfs(int y, int x, int type)
{
    if (y == n && x == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        // 세로모양->오른쪽 이동 불가능, 가로모양 -> 아래로 이동 불가능
        if ((i == 0 && type == 1) || (i == 1 && type == 0))
            continue;

        int ny = y + dy[i];
        int nx = x + dx[i];

        // 벽 또는 범위를 벗어날 경우
        if (ny > n || nx > n || house[ny][nx] == 1)
            continue;

        // 대각선 이동할 경우 벽 체크
        if (i == 2 && (house[y + 1][x] == 1 || house[y][x + 1] == 1))
            continue;

        dfs(ny, nx, i);
    }
}

int main()
{
    input();
    dfs(1, 2, 0);

    cout << ans << '\n';

    return 0;
}