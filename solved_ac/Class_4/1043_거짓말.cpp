#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int parent[51];
vector<int> knowing; // 이야기를 아는 사람 벡터
vector<vector<int>> party(50);

int Find(int x)
{
    if (parent[x] == x)
        return x;
    return x = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n,m,k 입력
    cin >> n >> m >> k;
    // parent 초기화
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    int x;
    // 이야기 아는사람 입력
    while (k--)
    {
        cin >> x;
        knowing.push_back(x);
    }
    // party 명단 입력
    int p, num, prev;
    for (int i = 0; i < m; i++)
    {
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            if (j >= 1)
            {
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else
                cin >> num;
            party[i].push_back(num);
        }
    }
}

int answer()
{
    int res = m;
    for (const auto &people : party)
    {
        bool flag = false;
        for (const auto &person : people)
        {
            if (flag)
                break;
            for (const auto &know : knowing)
            {
                if (Find(person) == Find(know))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            res--;
    }

    return res;
}

int main()
{
    input();
    cout << answer() << '\n';
    return 0;
}