#include <iostream>

using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    if (n2 > n1)
        swap(n1, n2);

    int G, L;

    int N1 = n1, N2 = n2;
    while (true)
    {
        int rem = n1 % n2;
        if (rem == 0)
        {
            G = n2;
            break;
        }
        else
        {
            n1 = n2;
            n2 = rem;
        }
    }
    for (int i = 1;; i++)
    {
        int temp = N1 * i;
        if (temp % N2 == 0)
        {
            L = temp;
            break;
        }
    }

    cout << G << '\n'
         << L << '\n';

    return 0;
}