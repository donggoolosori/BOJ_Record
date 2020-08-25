#include <iostream>
#include <algorithm>
#include <vector>

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
    cin >> n;

    vector<int> weight(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    sort(weight.begin(), weight.end(), compare);

    int maxW = weight[0];

    for (int i = 1; i < n; i++)
        maxW = max(maxW, weight[i] * (i + 1));

    cout << maxW;
    return 0;
}