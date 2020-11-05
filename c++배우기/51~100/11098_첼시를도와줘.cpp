#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, p;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--)
    {
        cin >> p;
        priority_queue<pair<int, string>> pq;
        int price;
        string name;
        while (p--)
        {
            cin >> price >> name;
            pq.push({price, name});
        }
        cout << pq.top().second << '\n';
    }
}

int main()
{
    solve();

    return 0;
}