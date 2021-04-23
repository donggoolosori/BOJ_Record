#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visit[101];
vector<int> network[101];

int getInfected(int idx)
{
    visit[idx] = true;

    int cnt = 1;
    for (const auto &next : network[idx])
    {
        if (visit[next])
            continue;
        cnt += getInfected(next);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        network[a].push_back(b);
        network[b].push_back(a);
    }
    cout << getInfected(1) - 1 << '\n';

    return 0;
}