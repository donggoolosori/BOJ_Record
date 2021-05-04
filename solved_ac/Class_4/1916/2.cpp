#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, M, start, goal;
struct Node
{
    int cost, idx;
};
vector<Node> maps[1001];
vector<int> cache(1001, INF);

struct compare
{
    bool operator()(Node a, Node b)
    {
        return a.cost > b.cost;
    }
};

int getMinCost()
{
    priority_queue<Node, vector<Node>, compare> pq;
    pq.push({0, start});
    cache[start] = 0;

    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();

        for (const auto &next : maps[curr.idx])
        {
            if (curr.cost + next.cost >= cache[next.idx])
                continue;
            cache[next.idx] = curr.cost + next.cost;
            pq.push({curr.cost + next.cost, next.idx});
        }
    }
    return cache[goal];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int fr, to, cost;
    while (M--)
    {
        cin >> fr >> to >> cost;
        maps[fr].push_back({cost, to});
    }
    cin >> start >> goal;

    // 다익스트라
    cout << getMinCost() << '\n';

    return 0;
}