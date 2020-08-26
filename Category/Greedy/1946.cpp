#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    int a, b;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        vector<pair<int, int>> recruiting;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            recruiting.push_back({a, b});
        }

        // 1번째 요소 순으로 오름차순 정렬
        sort(recruiting.begin(), recruiting.end(), compare);

        int cnt = 0;
        int smallest = n + 1;
        for (int j = 0; j < recruiting.size(); j++)
        {
            if (recruiting[j].second < smallest)
            {
                cnt++;
                smallest = recruiting[j].second;
            }
        }
        cout << cnt << '\n';
    }
}