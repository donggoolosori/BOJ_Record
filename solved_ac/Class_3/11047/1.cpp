#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    vector<int> coin(N);
    for (int i = 0; i < N; i++)
        cin >> coin[i];

    sort(coin.begin(), coin.end(), greater<int>());
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cnt += K / coin[i];
        K %= coin[i];
        if (K == 0)
            break;
    }
    cout << cnt << '\n';
    return 0;
}