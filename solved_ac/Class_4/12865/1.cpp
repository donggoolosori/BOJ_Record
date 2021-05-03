// 2408kb, 12ms
#include <algorithm>
#include <iostream>

using namespace std;

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

    int n, k;
    cin >> n >> k;

    int w, v;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        products[i] = {w, v};
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = k; j >= products[i].w; j--)
            cache[j] = max(cache[j], cache[j - products[i].w] + products[i].v);

    cout << cache[k];

    return 0;
}