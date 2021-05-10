#include <iostream>
#include <algorithm>

using namespace std;

int map[100001][3], maxWindow[2][3], minWindow[2][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> map[i][0] >> map[i][1] >> map[i][2];

    for (int i = 0; i < 3; i++)
        maxWindow[0][i] = minWindow[0][i] = map[0][i];

    for (int i = 1; i < N; i++)
    {
        maxWindow[1][0] = map[i][0] + max(maxWindow[0][0], maxWindow[0][1]);
        maxWindow[1][1] = map[i][1] + max(maxWindow[0][0], max(maxWindow[0][1], maxWindow[0][2]));
        maxWindow[1][2] = map[i][2] + max(maxWindow[0][1], maxWindow[0][2]);

        minWindow[1][0] = map[i][0] + min(minWindow[0][0], minWindow[0][1]);
        minWindow[1][1] = map[i][1] + min(minWindow[0][0], min(minWindow[0][1], minWindow[0][2]));
        minWindow[1][2] = map[i][2] + min(minWindow[0][1], minWindow[0][2]);

        for (int i = 0; i < 3; i++)
        {
            swap(maxWindow[0][i], maxWindow[1][i]);
            swap(minWindow[0][i], minWindow[1][i]);
        }
    }
    int MAX = max(maxWindow[0][0], max(maxWindow[0][1], maxWindow[0][2]));
    int MIN = min(minWindow[0][0], min(minWindow[0][1], minWindow[0][2]));
    cout << MAX << ' ' << MIN << '\n';
    return 0;
}