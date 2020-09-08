#include <vector>
#include <algorithm>
#include <iostream>

bool compare(int a, int b)
{
    return a > b;
}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long int> positive;
    vector<long long int> negative;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num > 0)
            positive.push_back(num);
        else
            negative.push_back(num);
    }
    sort(positive.begin(), positive.end(), compare);
    sort(negative.begin(), negative.end());

    long long int res = 0;
    // 양수들 계산
    for (int i = 0; i < positive.size(); i++)
    {
        if (i == positive.size() - 1)
        {
            res += positive[i];
        }
        else if (positive[i] > 1 && positive[i + 1] > 1)
        {
            res += positive[i] * positive[i + 1];
            i++;
        }
        else
        {
            res += positive[i];
        }
    }
    // 음수들 계산
    for (int i = 0; i < negative.size(); i++)
    {
        if (i == negative.size() - 1)
        {
            res += negative[i];
        }
        else if (negative[i + 1] == 0)
        {
            i++;
        }
        else
        {
            res += negative[i] * negative[i + 1];
            i++;
        }
    }
    cout << res;
    return 0;
}