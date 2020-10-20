#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[9], ans[9];

void dfs(int L, int idx)
{
    if (L == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < n; i++)
    {
        ans[L] = num[i];
        dfs(L + 1, i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num + n);

    dfs(0, 0);
    return 0;
}