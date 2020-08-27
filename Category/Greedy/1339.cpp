#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> alpNum(26, 0);
    cin >> n;
    vector<string> sv(n);
    for (int i = 0; i < n; i++)
        cin >> sv[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sv[i].length(); j++)
        {
            int idx = sv[i][j] - 'A';
            int sqr = sv[i].length() - j - 1;
            alpNum[idx] += pow(10, sqr);
        }
    }
    sort(alpNum.begin(), alpNum.end(), compare);
    int mul = 9;
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        res += alpNum[i] * mul;
        mul--;
    }

    cout << res;
    return 0;
}