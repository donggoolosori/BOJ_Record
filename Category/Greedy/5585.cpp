#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int change = 1000 - n;
    int coin[] = {500, 100, 50, 10, 5, 1};

    int cnt = 0;
    for (int i = 0; i < 6; i++)
    {
        if (change == 0)
            break;
        int quo = change / coin[i];
        cnt += quo;
        change -= quo * coin[i];
    }
    cout << cnt;

    return 0;
}