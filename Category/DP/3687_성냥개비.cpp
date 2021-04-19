#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;

vector<ll> minCache(101);
int minNum[] = {0, 0, 1, 7, 4, 2, 0, 8, 10};

void findMin()
{
    for (int i = 0; i < 9; i++)
        minCache[i] = minNum[i];
    minCache[6] = 6;
    for (int i = 9; i <= 100; i++)
    {
        minCache[i] = minCache[i - 2] * 10 + minNum[2];

        for (int j = 3; j < 8; j++)
            minCache[i] = min(minCache[i], minCache[i - j] * 10 + minNum[j]);
    }
}

string getMax(int n)
{
    string ret = "";

    while (n)
    {
        if (n % 2 == 0)
        {
            ret += '1';
            n -= 2;
        }
        else
        {
            ret += '7';
            n -= 3;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    findMin();

    while (T--)
    {
        int n;
        cin >> n;
        cout << minCache[n] << ' ' << getMax(n) << '\n';
    }

    return 0;
}