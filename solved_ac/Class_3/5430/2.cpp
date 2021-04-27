#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        deque<int> dq;
        string p, nums;
        int n;
        cin >> p >> n >> nums;

        // deque에 숫자 넣기
        string temp = "";
        for (int i = 0; i < nums.length(); i++)
        {
            if (!isdigit(nums[i]))
            {
                if (temp != "")
                    dq.push_back(stoi(temp));
                temp = "";
            }
            else
                temp += nums[i];
        }

        // p연산 수행
        bool isReversed = false, isError = false;

        for (const char &ch : p)
        {
            // 에러 발생한 경우 break
            if (isError)
                break;
            if (ch == 'R')
                isReversed = !isReversed;
            else
            {
                if (dq.empty())
                {
                    isError = true;
                    break;
                }
                if (isReversed)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (isError)
            cout << "error" << '\n';
        else
        {
            cout << '[';
            while (!dq.empty())
            {
                if (isReversed)
                {
                    cout << dq.back();
                    if (dq.size() != 1)
                        cout << ',';
                    dq.pop_back();
                }
                else
                {
                    cout << dq.front();
                    if (dq.size() != 1)
                        cout << ',';
                    dq.pop_front();
                }
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}