#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> num;
int ans[9];
bool check[10001];

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

    for (int i = idx; i < num.size(); i++)
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
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (!check[x])
        {
            check[x] = true;
            num.push_back(x);
        }
    }
    sort(num.begin(), num.end());

    dfs(0, 0);

    return 0;
}