#include <iostream>

using namespace std;

// 최대 공약수
int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소 공배수
int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int m, n, x, y;
    while (T--)
    {
        cin >> m >> n >> x >> y;
        int lim = LCM(m, n);
        bool flag = false;
        for (int i = x; i <= lim; i += m)
        {
            int temp = i % n == 0 ? n : i % n;
            if (temp == y)
            {
                cout << i << '\n';
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}