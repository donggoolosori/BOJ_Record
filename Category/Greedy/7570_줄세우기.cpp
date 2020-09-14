#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> line(n);
    vector<int> index(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> line[i];
        index[line[i]] = i;
    }
    vector<int> LIS(n, 1);
    int s_lis = 1;
    for (int i = 0; i < n; i++)
    {
        int cur_idx, post_idx;
        cur_idx = index[line[i]];
        post_idx = index[line[i] - 1];
        if (post_idx < cur_idx)
        {
            LIS[i] = LIS[post_idx] + 1;
            s_lis = max(s_lis, LIS[i]);
        }
    }
    int res = n - s_lis;
    cout << res;
    return 0;
}