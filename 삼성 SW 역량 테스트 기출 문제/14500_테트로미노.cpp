#include <iostream>
#define max(a, b) a > b ? a : b

using namespace std;

int n, m;
int board[501][501];
bool check[501][501];
int ans;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

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
            cin >> board[i][j];
        }
    }
}

// ㅜ,ㅓ,ㅗ,ㅏ 모양 숫자 합 찾기
void findFxckShapeMax(int r, int c)
{
    int res = 0;
    // ㅜ 모양
    if (r + 1 < n && c + 2 < m)
    {
        res = max(res, board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r + 1][c + 1]);
    }
    // ㅓ 모양
    if (r + 2 < n && c - 1 >= 0)
    {
        res = max(res, board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 1][c - 1]);
    }
    // ㅗ 모양
    if (r - 1 >= 0 && c + 2 < m)
    {
        res = max(res, board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r - 1][c + 1]);
    }
    // ㅏ 모양
    if (r + 2 < n && c + 1 < m)
    {
        res = max(res, board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 1][c + 1]);
    }
    ans = max(ans, res);
}

void findTetroMax(int r, int c, int L, int sum)
{
    if (L == 3)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= n || nr < 0 || nc >= m || nc < 0)
            continue;
        if (check[nr][nc])
            continue;
        check[nr][nc] = true;
        findTetroMax(nr, nc, L + 1, sum + board[nr][nc]);
        check[nr][nc] = false;
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check[i][j] = true;
            findTetroMax(i, j, 0, board[i][j]);
            check[i][j] = false;
            findFxckShapeMax(i, j);
        }
    }
    cout << ans << '\n';
}

int main()
{
    input();
    solve();
    return 0;
}