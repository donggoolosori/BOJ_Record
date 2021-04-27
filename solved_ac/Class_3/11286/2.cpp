#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Node
{
    int absVal, val;
};
struct compare
{
    bool operator()(Node a, Node b)
    {
        if (a.absVal == b.absVal)
            return a.val > b.val;
        return a.absVal > b.absVal;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<Node, vector<Node>, compare> pq;
    int N, op;
    cin >> N;
    while (N--)
    {
        cin >> op;

        // 절대값 가장 작은 값 출력 및 삭제
        if (op == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top().val << '\n';
                pq.pop();
            }
        }
        // 값 넣기
        else
            pq.push({abs(op), op});
    }
    return 0;
}