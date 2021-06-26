#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

int n;
int graph[MAX][MAX];

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(vector<bool> &visit, int start)
{
    for (int i = 1; i < n + 1; i++)
    {
        if (graph[start][i] == 1 && !visit[i])
        {
            visit[i] = true;
            dfs(visit, i);
        }
    }
}

int main()
{
    init();
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        vector<bool> visit(n + 1, false);
        dfs(visit, i);

        for (int j = 1; j < n + 1; j++)
        {
            if (visit[j])
                graph[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}