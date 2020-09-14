#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    int mod = 10007;
    cin >> n >> k;
    vector<vector<long long int>> pascal(1001, vector<long long int>(1001, 1));
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % mod;
        }
    }
    cout << pascal[n][k] % mod;

    return 0;
}