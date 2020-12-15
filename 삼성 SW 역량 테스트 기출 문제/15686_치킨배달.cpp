#include <iostream>
#include <vector>
#include <cmath>
#define min(a, b) a < b ? a : b

using namespace std;

struct Pos
{
    int r, c;
};
int n, m;
int map[51][51];
vector<Pos> chicken, house, Select;
int ans = 987654321;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                chicken.push_back({i, j});
            else if (map[i][j] == 1)
                house.push_back({i, j});
        }
    }
}

int getDistance()
{
    int sum = 0;
    for (const auto &h : house)
    {
        int r = h.r;
        int c = h.c;
        int d = 987654321;
        for (const auto &sC : Select)
        {
            int nr = sC.r;
            int nc = sC.c;
            int temp = abs(nr - r) + abs(nc - c);
            d = min(temp, d);
        }
        sum += d;
    }
    return sum;
}

void set_chicken(int L, int index)
{
    if (L == m)
    {
        ans = min(ans, getDistance());
        return;
    }
    for (int i = index; i < chicken.size(); i++)
    {
        Pos temp = chicken[i];
        Select.push_back({temp.r, temp.c});
        set_chicken(L + 1, i + 1);
        Select.pop_back();
    }
}

void solve()
{
    set_chicken(0, 0);
    cout << ans << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}