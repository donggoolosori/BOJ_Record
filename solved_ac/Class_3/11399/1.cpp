#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> time(n);
    for (int i = 0; i < n; i++)
        cin >> time[i];
    sort(time.begin(), time.end());

    int sum = 0, answer = 0;
    for (int i = 0; i < n; i++)
    {
        sum += time[i];
        answer += sum;
    }
    cout << answer << '\n';

    return 0;
}