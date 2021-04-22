#include <iostream>
#include <cstring>

using namespace std;

int cache[1001];

int getCases(int n)
{
    if (n == 1 || n == 2)
        return n;

    int &ret = cache[n];
    if (ret != -1)
        return ret;

    return ret = (getCases(n - 1) + getCases(n - 2)) % 10007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << getCases(n) << '\n';

    return 0;
}