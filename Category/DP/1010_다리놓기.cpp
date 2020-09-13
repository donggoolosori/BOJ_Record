#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int t;
    int n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<long long int>> bridge(n + 1, vector<long long int>(m + 1, 0));
        for (int i = 1; i < m + 1; i++)
            bridge[1][i] = i;

        for (int i = 2; i < n + 1; i++)
        {
            for (int j = i; j < m + 1; j++)
            {
                for (int k = j - 1; k > 0; k--)
                {
                    bridge[i][j] += bridge[i - 1][k];
                }
            }
        }
        cout << bridge[n][m] << '\n';
    }

    return 0;
}