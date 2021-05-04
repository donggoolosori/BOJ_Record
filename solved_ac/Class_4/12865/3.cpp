#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
struct Product
{
    int w, v;
};
Product products[100];
int cache[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> products[i].w >> products[i].v;

    // knapsack 알고리즘
    for (int i = 0; i < N; i++)
        // 물건을 하나씩만 담을 수 있으므로 역순으로 순환
        for (int j = K; j >= products[i].w; j--)
            cache[j] = max(cache[j], cache[j - products[i].w] + products[i].v);

    cout << cache[K] << '\n';
    return 0;
}