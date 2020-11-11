#include <iostream>
#define min(a, b) a < b ? a : b

using namespace std;

int n, ans = 987654321;
int stats[21][21];
int team[21]; // 0과 1로 팀 구분

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> stats[i][j];
        }
    }
}

int getDiff()
{
    int teamZero = 0, teamOne = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (team[i] == 0 && team[j] == 0)
                teamZero += stats[i][j];
            if (team[i] == 1 && team[j] == 1)
                teamOne += stats[i][j];
        }
    }
    return abs(teamZero - teamOne);
}

void combination(int L, int idx)
{
    if (L == n / 2 + 1)
    {
        int diff = getDiff();
        ans = min(ans, diff);
        return;
    }
    for (int i = idx; i <= n; i++)
    {
        if (team[i])
            continue;
        team[i] = 1;
        combination(L + 1, i);
        team[i] = 0;
    }
}

void solve()
{
    combination(1, 1);
    cout << ans << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}