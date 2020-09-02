#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, n;
    cin >> r >> c >> n;
    vector<pair<int, int>> store_pos(n);
    for (int i = 0; i < n; i++)
        cin >> store_pos[i].first >> store_pos[i].second;
    int x[2];
    cin >> x[0] >> x[1];

    int sum = 0;
    int s_dir, s_dist;
    for (int i = 0; i < n; i++)
    {
        s_dir = store_pos[i].first;
        s_dist = store_pos[i].second;
        // 같은 선일 경우
        if (x[0] == s_dir)
        {
            sum += abs(s_dist - x[1]);
            continue;
        }
        // 경비가 북쪽일 경우
        if (x[0] == 1)
        {
            // 가게가 서쪽
            if (s_dir == 3)
                sum += x[1] + s_dist;
            // 동쪽
            else if (s_dir == 4)
                sum += (r - x[1]) + s_dist;
            // 남쪽
            else
                sum += c + min(x[1] + s_dist, r - x[1] + r - s_dist);
        }
        // 경비 남쪽
        else if (x[0] == 2)
        {
            // 가게가 서쪽
            if (s_dir == 3)
                sum += x[1] + c - s_dist;
            // 동쪽
            else if (s_dir == 4)
                sum += (r - x[1]) + c - s_dist;
            // 북쪽
            else
                sum += c + min(x[1] + s_dist, r - x[1] + r - s_dist);
        }
        // 경비 서쪽
        else if (x[0] == 3)
        {
            // 가게가 북쪽
            if (s_dir == 1)
                sum += x[1] + s_dist;
            // 남쪽
            else if (s_dir == 2)
                sum += (c - x[1]) + s_dist;
            // 동쪽
            else
                sum += r + min(x[1] + s_dist, c - x[1] + c - s_dist);
        }
        // 경비 동쪽
        else
        {
            // 가게가 북쪽
            if (s_dir == 1)
                sum += x[1] + r - s_dist;
            // 남쪽
            else if (s_dir == 2)
                sum += (c - x[1]) + r - s_dist;
            // 서쪽
            else
                sum += r + min(x[1] + s_dist, c - x[1] + c - s_dist);
        }
    }
    cout << sum;
    return 0;
}