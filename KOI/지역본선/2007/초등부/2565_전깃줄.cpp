#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int LIS(int n, vector<pair<int, int>> line)
{
    vector<int> dp(n, 0);
    dp[0] = 1;
    int lis = 1;
    for (int i = 1; i < n; i++)
    {
        int MAX = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (line[j].second < line[i].second)
                MAX = max(MAX, dp[j]);
        }
        dp[i] = MAX + 1;
        lis = max(lis, dp[i]);
    }
    return lis;
}
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> line;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        line.push_back({a, b});
    }

    sort(line.begin(), line.end(), compare);
    // 최대 증가 수열 구하기
    int lis = LIS(n, line);
    int res = n - lis;
    cout << res;
    return 0;
}