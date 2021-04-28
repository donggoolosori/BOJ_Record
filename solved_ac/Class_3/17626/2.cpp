#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int sqrtN = sqrt(n);

    vector<int> cache(n + 1, 50000);
    for (int i = 1; i <= sqrtN; i++)
        cache[i * i] = 1;

    for (int i = 1; i <= sqrtN; i++)
        for (int j = 1; j <= n - i * i; j++)
            cache[j + i * i] = min(cache[j + i * i], cache[j] + 1);
    cout << cache[n] << '\n';
    return 0;
}