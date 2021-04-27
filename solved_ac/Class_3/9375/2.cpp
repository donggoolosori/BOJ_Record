#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        unordered_map<string, int> um;
        int n;
        string name, kind;
        cin >> n;
        while (n--)
        {
            cin >> name >> kind;
            um[kind]++;
        }
        int ans = 1;
        for (const auto &iter : um)
        {
            ans *= (iter.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }

    return 0;
}