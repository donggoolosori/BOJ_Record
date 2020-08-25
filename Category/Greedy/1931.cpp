#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long int, long long int>> time(n);

    for (int i = 0; i < n; i++)
        cin >> time[i].first >> time[i].second;

    sort(time.begin(), time.end(), compare);

    int res = 1;
    long long int s_time = time[0].second;
    for (int i = 1; i < time.size(); i++)
    {
        if (time[i].first >= s_time)
        {
            res++;
            s_time = time[i].second;
        }
    }
    cout << res;
    return 0;
}