#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int selected[9];
int num[9];
int visit[9];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
}

void dfs(int L)
{
    if (L == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << selected[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int before = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] || num[i] == before)
            continue;
        selected[L] = num[i];
        before = selected[L];
        visit[i] = true;
        dfs(L + 1);
        visit[i] = false;
    }
}

int main()
{
    input();
    dfs(0);

    return 0;
}