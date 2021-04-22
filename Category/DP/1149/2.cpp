#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int cost[1001][3], cache[1001][3];
int N;

int getMinCost(int y, int x)
{
    if (y == N - 1)
        return cost[y][x];

    int &ret = cache[y][x];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = 0; i < 3; i++)
    {
        if (i == x)
            continue;
        ret = min(ret, getMinCost(y + 1, i) + cost[y][x]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];

    int ans = INF;
    for (int i = 0; i < 3; i++)
        ans = min(ans, getMinCost(0, i));
    cout << ans << '\n';

    return 0;
}