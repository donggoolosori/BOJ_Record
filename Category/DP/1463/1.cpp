#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000000

using namespace std;

int cache[1000001];
int N;

int getMinOp(int num)
{
    if (num == 1)
        return 0;

    int &ret = cache[num];
    if (ret != -1)
        return ret;

    ret = MAX;
    if (num % 3 == 0)
        ret = min(ret, getMinOp(num / 3) + 1);
    if (num % 2 == 0)
        ret = min(ret, getMinOp(num / 2) + 1);
    ret = min(ret, getMinOp(num - 1) + 1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N;
    cout << getMinOp(N);
    return 0;
}