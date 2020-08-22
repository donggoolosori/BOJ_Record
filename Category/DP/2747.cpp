#include <iostream>

using namespace std;

int dp[46];

int fibo(int x)
{
    if (dp[x] != -1)
        return dp[x];
    return dp[x] = fibo(x - 1) + fibo(x - 2);
}
int main()
{
    int n;
    cin >> n;
    fill_n(dp, 46, -1);
    dp[0] = 0;
    dp[1] = 1;
    cout << fibo(n);

    return 0;
}