#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int total = N + M;

    map<string, int> nameList;

    string s;
    while (total--)
    {
        cin >> s;
        nameList[s]++;
    }

    int cnt = 0;
    vector<string> result;
    for (const auto &iter : nameList)
    {
        if (iter.second >= 2)
        {
            cnt++;
            result.push_back(iter.first);
        }
    }
    cout << cnt << '\n';
    for (const string &name : result)
        cout << name << '\n';

    return 0;
}