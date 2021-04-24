#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Time
{
    int start, end;
};

bool compare(Time a, Time b)
{
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Time> timeTable;
    int s, e;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e;
        timeTable.push_back({s, e});
    }

    sort(timeTable.begin(), timeTable.end(), compare);

    int cnt = 0, prev = 0;

    for (const auto &curr : timeTable)
    {
        if (curr.start >= prev)
        {
            cnt++;
            prev = curr.end;
        }
    }
    cout << cnt << '\n';

    return 0;
}