#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
#define MAX 1001
using namespace std;

struct node
{
    int index, cost;
};
int n, m;
int s, e;
vector<node> city[MAX];
int route[MAX]; //경로 저장 배열

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int fr, to, cost;
    while (m--)
    {
        cin >> fr >> to >> cost;
        city[fr].push_back({to, cost});
    }
    cin >> s >> e;
}

void dijkstra()
{
    vector<int> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cur_cost = cur.first;
        int cur_index = cur.second;
        if (d[cur_index] < cur_cost)
            continue;

        for (const auto &i : city[cur_index])
        {
            int next_index = i.index;
            int next_cost = i.cost + cur_cost;
            if (next_cost < d[next_index])
            {
                route[next_index] = cur_index; // 어디서 왔는지를 저장
                d[next_index] = next_cost;
                pq.push({next_cost, next_index});
            }
        }
    }

    // 출력 부분
    cout << d[e] << '\n';
    vector<int> routeV;
    // start 인덱스에서 e가 0이 되어 while문 탈출
    while (e)
    {
        routeV.push_back(e);
        e = route[e];
    }
    cout << routeV.size() << '\n';
    for (int i = routeV.size() - 1; i >= 0; i--)
    {
        cout << routeV[i] << ' ';
    }
}

int main()
{
    input();
    dijkstra();

    return 0;
}