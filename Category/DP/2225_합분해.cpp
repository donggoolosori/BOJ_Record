#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<long long int>> dp(k + 1, vector<long long int>(n + 1, 0));

    // k가 1일 경우는 각 수의 경우의 수가 모두 1
    for (int i = 0; i < n + 1; i++)
    {
        dp[1][i] = 1;
    }

    // i: 사용한 수의 개수
    // j: 합으로 만드려는 수 (N)
    // m: 합으로 만든 수의 마지막 수
    for (int i = 2; i < k + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            for (int m = 0; m < j + 1; m++)
            {
                dp[i][j] += (dp[i - 1][j - m]) % 1000000000;
            }
        }
    }
    cout << dp[k][n] % 1000000000;

    return 0;
}