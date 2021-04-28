#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, k;
    cin >> T;
    while (T--)
    {
        cin >> k;
        vector<int> isValid(k);
        priority_queue<pair<int, int>> maxPQ;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;
        char op;
        int num;
        for (int i = 0; i < k; i++)
        {
            cin >> op >> num;
            if (op == 'I')
            {
                maxPQ.push({num, i});
                minPQ.push({num, i});
                isValid[i] = true;
            }
            else
            {
                if (num == 1)
                {
                    while (!maxPQ.empty() && !isValid[maxPQ.top().second])
                        maxPQ.pop();
                    if (!maxPQ.empty())
                    {
                        isValid[maxPQ.top().second] = false;
                        maxPQ.pop();
                    }
                }
                else
                {
                    while (!minPQ.empty() && !isValid[minPQ.top().second])
                        minPQ.pop();
                    if (!minPQ.empty())
                    {
                        isValid[minPQ.top().second] = false;
                        minPQ.pop();
                    }
                }
            }
        }
        while (!maxPQ.empty() && !isValid[maxPQ.top().second])
            maxPQ.pop();
        while (!minPQ.empty() && !isValid[minPQ.top().second])
            minPQ.pop();
        if (maxPQ.empty())
            cout << "EMPTY" << '\n';
        else
            cout << maxPQ.top().first << ' ' << minPQ.top().first << '\n';
    }

    return 0;
}