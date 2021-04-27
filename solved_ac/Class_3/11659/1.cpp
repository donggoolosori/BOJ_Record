#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> numbers(N + 1);
    int sum = 0, num;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        sum += num;
        numbers[i] = sum;
    }

    int fr, to;
    while (M--)
    {
        cin >> fr >> to;
        cout << numbers[to] - numbers[fr - 1] << '\n';
    }

    return 0;
}