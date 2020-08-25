#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = -1;

    int remain;
    for (int i = n / 5; i >= 0; i--)
    {
        remain = n - i * 5;
        if (remain % 3 == 0)
        {
            res = i + remain / 3;
            break;
        }
    }
    cout << res;

    return 0;
}