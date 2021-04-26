#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int five = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        five += n / i;
    }
    cout << five << '\n';

    return 0;
}