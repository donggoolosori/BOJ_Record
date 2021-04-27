#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / (gcd(a, b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, M, N, x, y;
    cin >> T;
    while (T--)
    {
        cin >> M >> N >> x >> y;
        int lim = lcm(M, N);
        bool flag = false;
        for (int i = x; i <= lim; i += M)
        {
            int temp = i % N == 0 ? N : i % N;
            if (temp == y)
            {
                cout << i << '\n';
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << -1 << '\n';
    }

    return 0;
}