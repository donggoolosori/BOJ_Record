#include <vector>
#include <iostream>

using namespace std;

int getParent(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(vector<int> &parent, int x, int y)
{
    x = getParent(parent, x);
    y = getParent(parent, y);
    parent[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, P;
    cin >> G >> P;

    vector<int> parent(G + 1, 0);
    vector<int> g(P);
    for (int i = 0; i < P; i++)
        cin >> g[i];

    for (int i = 1; i < G + 1; i++)
        parent[i] = i;

    int cnt = 0;
    for (int i = 0; i < P; i++)
    {
        int empty_gate = getParent(parent, g[i]);
        if (empty_gate == 0)
            break;
        else
        {
            cnt++;
            unionParent(parent, empty_gate, empty_gate - 1);
        }
    }
    cout << cnt;

    return 0;
}