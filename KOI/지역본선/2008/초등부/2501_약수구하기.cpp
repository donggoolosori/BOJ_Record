#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (n % i == 0)
            cnt++;
        if (cnt == k)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}