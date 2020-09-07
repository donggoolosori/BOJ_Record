// 실패
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t, k;
    cin >> m >> n >> t >> k;
    vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));

    // 광석위치 입력
    int x, y;
    while (t--)
    {
        cin >> x >> y;
        for (int i = x; i >= x - k; i--)
        {
            if (i < 0)
                break;
            map[n - y][i] += 1;
        }
    }
    int max = 0;
    int max_x, max_y;
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < m - k + 1; j++)
        {
            int cnt = 0;
            for (int c = i; c <= i + k; c++)
                cnt += map[c][j];
            if (cnt >= max)
            {
                max = cnt;
                max_y = n - i, max_x = j;
            }
        }
    }
    cout << max_x << ' ' << max_y << '\n';
    cout << max << '\n';
    return 0;
}