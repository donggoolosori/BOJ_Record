#include <iostream>
#include <cstring>
#include <queue>
#define MAX 100001

using namespace std;

int subin, bro;
int cache[MAX];
struct Node
{
    int idx, dist;
    bool operator<(const Node &b) const
    {
        return idx > b.idx;
    }
};

// 다익스트라 알고리즘
int getMinTime()
{
    // cache 초기화
    for (int i = 0; i < MAX; i++)
        cache[i] = MAX;
    cache[subin] = 0;
    // 오름차순 우선순위 큐
    priority_queue<Node> pq;
    pq.push({subin, 0});

    while (!pq.empty())
    {
        Node curr = pq.top();
        int idx = curr.idx, dist = curr.dist;
        pq.pop();
        if (dist > cache[idx])
            continue;

        int nIdx, nDist;
        // 2*x
        nIdx = idx * 2, nDist = dist;
        if (nIdx < MAX && nDist < cache[nIdx])
        {
            cache[nIdx] = nDist;
            pq.push({nIdx, nDist});
        }
        // x-1
        nIdx = idx - 1, nDist = dist + 1;
        if (nIdx >= 0 && nDist < cache[nIdx])
        {
            cache[nIdx] = nDist;
            pq.push({nIdx, nDist});
        }
        // x+1
        nIdx = idx + 1, nDist = dist + 1;
        if (nIdx < MAX && nDist < cache[nIdx])
        {
            cache[nIdx] = nDist;
            pq.push({nIdx, nDist});
        }
    }

    // 수빈 -> 동생까지의 최소경로 반환
    return cache[bro];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> subin >> bro;

    // 수빈이가 동생보다 앞에 있다면 -1로 밖에 이동할 수 없다
    if (subin >= bro)
    {
        cout << subin - bro << '\n';
        return 0;
    }

    cout << getMinTime();

    return 0;
}