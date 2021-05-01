#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string a, b;
int cache[1000][1000];

int getLCS(int aidx, int bidx)
{
    if (aidx < 0 || bidx < 0)
        return 0;
    int &ret = cache[aidx][bidx];
    if (ret != -1)
        return ret;

    if (a[aidx] == b[bidx])
        return ret = getLCS(aidx - 1, bidx - 1) + 1;
    else
        return ret = max(getLCS(aidx - 1, bidx), getLCS(aidx, bidx - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    int n = a.length(), m = b.length();
    // cache -1로 초기화
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cache[i][j] = -1;

    cout << getLCS(n - 1, m - 1);

    return 0;
}