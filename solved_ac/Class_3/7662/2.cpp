#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, K;
    cin >> T;

    while (T--)
    {
        multiset<int> ms;

        char op;
        int num;
        cin >> K;
        while (K--)
        {
            cin >> op >> num;
            if (op == 'I')
                ms.insert(num);
            else
            {
                if (ms.empty())
                    continue;
                // 최대 값 삭제
                if (num == 1)
                    ms.erase(--ms.end());
                // 최소 값 삭제
                else
                    ms.erase(ms.begin());
            }
        }

        // 결과 출력
        if (ms.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    }

    return 0;
}