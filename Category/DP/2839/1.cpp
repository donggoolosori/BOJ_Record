#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cache(5001, -1);
const int INF = 987654321;
int N;

int getMinBag(int w)
{
    if (w < 0)
        return INF;
    if (w == 0)
        return 0;

    int &ret = cache[w];
    if (ret != -1)
        return ret;

    return ret = min(getMinBag(w - 3), getMinBag(w - 5)) + 1;
}

int getMinBag2(int w)
{
    if (w > N)
        return INF;
    if (w == N)
        return 0;

    int &ret = cache[w];
    if (ret != -1)
        return ret;

    return ret = min(getMinBag2(w + 3), getMinBag2(w + 5)) + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int ans = getMinBag2(0);
    if (ans >= INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}