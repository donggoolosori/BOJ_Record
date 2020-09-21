#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
long long int n, m, b;

struct Ans
{
    int h, t;
    bool can_build;
};
int land[501][501];

Ans count_time(int h)
{
    int time = 0;
    int usable_block = b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == h)
                continue;
            else if (land[i][j] < h)
            {
                usable_block -= (h - land[i][j]);
                time += h - land[i][j];
            }
            else
            {
                time += (land[i][j] - h) * 2;
                usable_block += (land[i][j] - h);
            }
        }
    }
    if (usable_block < 0)
        return {h, time, false};
    else
    {
        return {h, time, true};
    }
}
int main()
{
    cin >> n >> m >> b;
    int low = 256, high = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
            low = min(low, land[i][j]);
            high = max(high, land[i][j]);
        }
    }
    int ans_h = 0;
    int ans_t = INT_MAX;
    for (int h = low; h < high + 1; h++)
    {
        Ans ans = count_time(h);
        if (!ans.can_build)
            continue;
        else if (ans_t >= ans.t)
        {
            ans_t = ans.t;
            ans_h = ans.h;
        }
    }
    cout << ans_t << ' ' << ans_h << '\n';
    return 0;
}