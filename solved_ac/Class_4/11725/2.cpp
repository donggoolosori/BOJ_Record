// bfs 사용
// 8050kb 44ms
#include <iostream>
#include <queue>

using namespace std;

int N;
int parent[100001];
vector<int> graph[100001];

void bfs()
{
    parent[1] = 1;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (const int &child : graph[curr])
        {
            if (parent[child] != 0)
                continue;
            parent[child] = curr;
            q.push(child);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();
    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';

    return 0;
}