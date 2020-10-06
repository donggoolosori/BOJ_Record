#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 50
using namespace std;

struct Pos
{
    int y;
    int x;
};

int n, m;
int ans = 99999999;
int map[MAX][MAX];
bool Select[13];
vector<Pos> house, chicken, sV;

int dist()
{
    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int y = house[i].y;
        int x = house[i].x;
        int d = 99999999;
        for (int j = 0; j < sV.size(); j++)
        {
            int yy = sV[j].y;
            int xx = sV[j].x;
            int temp = abs(xx - x) + abs(yy - y);
            d = min(temp, d);
        }
        sum += d;
    }
    return sum;
}

void dfs(int idx, int L)
{
    if (L == m)
    {
        ans = min(ans, dist());
        return;
    }
    for (int i = idx; i < chicken.size(); i++)
    {
        if (Select[i])
            continue;
        Select[i] = true;
        sV.push_back(chicken[i]);
        dfs(i, L + 1);
        Select[i] = false;
        sV.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                house.push_back({i, j});
            else if (map[i][j] == 2)
                chicken.push_back({i, j});
        }
    }
    dfs(0, 0);
    cout << ans << '\n';

    return 0;
}