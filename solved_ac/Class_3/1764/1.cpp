#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int cnt;
int n, m;
vector<string> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<string> notListened(n);
    for (int i = 0; i < n; i++)
        cin >> notListened[i];
    sort(notListened.begin(), notListened.end());

    string s;
    while (m--)
    {
        cin >> s;
        if (binary_search(notListened.begin(), notListened.end(), s))
        {
            cnt++;
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}