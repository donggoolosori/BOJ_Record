#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> timeTable;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    timeTable.resize(n);
    for (int i = 0; i < n; i++)
        cin >> timeTable[i].first >> timeTable[i].second;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    input();

    sort(timeTable.begin(), timeTable.end(), compare);

    int ans = 1;
    int nextStart = timeTable[0].second;
    for (int i = 1; i < timeTable.size(); i++)
    {
        if (timeTable[i].first < nextStart)
            continue;
        ans++;
        nextStart = timeTable[i].second;
    }
    cout << ans << '\n';
    return 0;
}