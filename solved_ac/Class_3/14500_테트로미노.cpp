#include <algorithm>
#include <iostream>
#include <cstring>

#define MAX 500
using namespace std;

int n, m;
int paper[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// ㅏ
void shape1(int y, int x)
{
    int sum = paper[y][x] + paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 2][x];
    ans = max(ans, sum);
}
// ㅗ
void shape2(int y, int x)
{
    int sum = paper[y][x] + paper[y][x + 1] + paper[y - 1][x + 1] + paper[y][x + 2];
    ans = max(ans, sum);
}
// ㅓ
void shape3(int y, int x)
{
    int sum = paper[y][x] + paper[y + 1][x] + paper[y + 1][x - 1] + paper[y + 2][x];
    ans = max(ans, sum);
}
// ㅜ
void shape4(int y, int x)
{
    int sum = paper[y][x] + paper[y][x + 1] + paper[y + 1][x + 1] + paper[y][x + 2];
    ans = max(ans, sum);
}

void dfs(int y, int x, int L, int sum)
{
    visited[y][x] = true;
    if (L == 3)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny, nx;
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (visited[ny][nx])
            continue;

        dfs(ny, nx, L + 1, sum + paper[ny][nx]);
        visited[ny][nx] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> paper[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memset(visited, false, sizeof(visited));
            dfs(i, j, 0, paper[i][j]);
            // ㅏ 모양
            if (i + 2 < n && j + 1 < m)
            {
                shape1(i, j);
            }
            // ㅗ 모양
            if (i - 1 >= 0 && j + 2 < m)
            {
                shape2(i, j);
            }
            // ㅓ 모양
            if (i + 2 < n && j - 1 >= 0)
            {
                shape3(i, j);
            }
            // ㅜ 모양
            if (i + 1 < n && j + 2 < m)
            {
                shape4(i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}