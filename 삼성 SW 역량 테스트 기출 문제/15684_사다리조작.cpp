#include <iostream>
#include <vector>
#define min(a, b) a < b ? a : b

using namespace std;

int n, m, h;
vector<vector<int>> line(11, vector<int>(31));
int ans = 10;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> h;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            line[i][j] = i;
        }
    }
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        line[b][a] = b + 1;
        line[b + 1][a] = b;
    }
}

bool checkLine()
{
    for (int i = 1; i <= n; i++)
    {
        int cur_line = i;
        for (int j = 1; j <= h; j++)
        {
            if (line[cur_line][j] != cur_line)
                cur_line = line[cur_line][j];
        }
        if (cur_line != i)
            return false;
    }
    return true;
}

void dfs(int L, int index)
{
    if (L > 3 || L >= ans)
    {
        return;
    }
    if (checkLine())
    {
        ans = min(ans, L);
        return;
    }
    for (int i = index; i < n; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            // 이미 다리가 놓아져있는 경우
            if (line[i][j] != i)
                continue;

            int right = i + 1;

            // 오른쪽 세로줄에 놓인 다리가 없다면 다리 놓기
            if (line[right][j] == right)
            {
                line[i][j] = right;
                line[right][j] = i;
                dfs(L + 1, i);
                line[i][j] = i;
                line[right][j] = right;
            }
        }
    }
}

void solve()
{
    if (checkLine())
        cout << 0 << '\n';
    else
    {
        dfs(0, 1);
        ans = ans == 10 ? -1 : ans;
        cout << ans << '\n';
    }
}

int main()
{
    input();
    solve();

    return 0;
}