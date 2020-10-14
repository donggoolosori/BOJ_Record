#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int parent[100001];

void dfs(int cur)
{
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int next = tree[cur][i];
        if (parent[next] == 0)
        {
            parent[next] = cur;
            dfs(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int x1, x2;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x1 >> x2;
        tree[x1].push_back(x2);
        tree[x2].push_back(x1);
    }
    parent[1] = 1;
    dfs(1);
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
    return 0;
}
