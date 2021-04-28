#include <iostream>
#include <cstring>

using namespace std;

int cache[1001];

int getCases(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;

    int &ret = cache[n];
    if (ret != -1)
        return ret;
    return ret = (getCases(n - 1) + 2 * getCases(n - 2)) % 10007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    int n;
    cin >> n;
    cout << getCases(n) << '\n';

    return 0;
}