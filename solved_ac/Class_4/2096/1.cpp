#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[100001][3];
int maxWindow[2][3];
int minWindow[2][3];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }
}

void solve()
{
    for (int i = 0; i < 3; i++)
        maxWindow[0][i] = minWindow[0][i] = map[0][i];
    for (int i = 1; i < n; i++)
    {
        maxWindow[1][0] = map[i][0] + max(maxWindow[0][0], maxWindow[0][1]);
        maxWindow[1][1] = map[i][1] + max(maxWindow[0][0], max(maxWindow[0][1], maxWindow[0][2]));
        maxWindow[1][2] = map[i][2] + max(maxWindow[0][2], maxWindow[0][1]);

        minWindow[1][0] = map[i][0] + min(minWindow[0][0], minWindow[0][1]);
        minWindow[1][1] = map[i][1] + min(minWindow[0][0], min(minWindow[0][1], minWindow[0][2]));
        minWindow[1][2] = map[i][2] + min(minWindow[0][2], minWindow[0][1]);

        for (int j = 0; j < 3; j++)
        {
            maxWindow[0][j] = maxWindow[1][j];
            minWindow[0][j] = minWindow[1][j];
        }
    }
    int min_res = min(minWindow[0][0], min(minWindow[0][1], minWindow[0][2]));
    int max_res = max(maxWindow[0][0], max(maxWindow[0][1], maxWindow[0][2]));

    cout << max_res << ' ' << min_res;
}

int main()
{
    input();
    solve();

    return 0;
}