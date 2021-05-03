// 41000kb, 72ms
#include <iostream>
#include <cstring>

using namespace std;

int N, K;
struct Product
{
    int w, v;
};
Product products[100];
int cache[101][100001];

int getMaxValue(int idx, int curr_w)
{
    if (idx == N)
        return 0;
    int &ret = cache[idx][curr_w];
    if (ret != -1)
        return ret;

    // 물건을 배낭에 넣지 않은 경우
    ret = getMaxValue(idx + 1, curr_w);
    // 물건을 배낭에 넣은 경우
    if (curr_w >= products[idx].w)
        ret = max(ret, getMaxValue(idx + 1, curr_w - products[idx].w) + products[idx].v);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> products[i].w >> products[i].v;

    // 냅색 알고리즘
    cout << getMaxValue(0, K) << '\n';

    return 0;
}