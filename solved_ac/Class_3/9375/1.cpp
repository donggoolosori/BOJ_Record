#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int n;
    string catag, name;

    while (T--)
    {
        map<string, int> m;
        cin >> n;
        while (n--)
        {
            cin >> name >> catag;
            if (m.find(catag) == m.end())
            {
                m.insert({catag, 1});
            }
            else
                m[catag]++;
        }

        int ans = 1;
        for (auto i : m)
        {
            ans *= (i.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }

    return 0;
}