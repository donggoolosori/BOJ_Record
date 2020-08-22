#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res = 0;
    int paper[7];
    for (int i = 1; i < 7; i++)
    {
        cin >> paper[i];
    }

    // 6x6 색종이는 종이개수당 판 1개 필요
    res += paper[6];
    paper[6] = 0;

    while (paper[1] != 0 || paper[2] != 0 || paper[3] != 0 || paper[4] != 0 || paper[5] != 0)
    {
        // 5x5 색종이를 채운 후 1x1 색종이를 채워준다
        while (paper[5] != 0)
        {
            int plate = 36;
            paper[5]--;
            plate -= 25;
            if (paper[1] <= plate)
                paper[1] = 0;
            else
                paper[1] -= plate;
            res += 1;
        }
        // 4x4 -> 2x2 -> 1x1 순으로 채워준다.
        while (paper[4] != 0)
        {
            int plate = 36;
            paper[4]--;
            plate -= 16;
            // 2x2가 충분한 경우
            if (paper[2] > 5)
            {
                paper[2] -= 5;
                plate -= 20;
            }
            else
            {
                plate -= paper[2] * 4;
                paper[2] = 0;
            }
            // 1x1 채우기
            if (paper[1] <= plate)
                paper[1] = 0;
            else
                paper[1] -= plate;
            res += 1;
        }
        // 3x3 -> 2x2 -> 1x1
        while (paper[3] != 0)
        {
            int plate = 36;
            // 3x3 채우기
            if (paper[3] >= 4)
            {
                paper[3] -= 4;
                plate = 0;
            }
            else
            {
                plate -= 9 * paper[3];
                paper[3] = 0;
            }
            // 2x2 채우기
            if (plate == 27 && paper[2] >= 5)
            {
                paper[2] -= 5;
                plate -= 20;
            }
            else if (plate == 27 && paper[2] < 5)
            {
                plate -= paper[2] * 4;
                paper[2] = 0;
            }
            if (plate == 18 && paper[2] >= 3)
            {
                paper[2] -= 3;
                plate -= 12;
            }
            else if (plate == 18 && paper[2] < 3)
            {
                plate -= paper[2] * 4;
                paper[2] = 0;
            }
            if (plate == 9 && paper[2] >= 1)
            {
                paper[2]--;
                plate -= 4;
            }
            else if (plate == 9 && paper[2] < 1)
            {
                plate -= paper[2] * 4;
                paper[2] = 0;
            }
            // 1x1 채우기
            if (paper[1] <= plate)
                paper[1] = 0;
            else
                paper[1] -= plate;
            res += 1;
        }
        // 2x2 -> 1x1
        while (paper[2] != 0)
        {
            int plate = 36;
            if (paper[2] >= 9)
            {
                plate = 0;
                paper[2] -= 9;
            }
            else
            {
                plate -= paper[2] * 4;
                paper[2] = 0;
            }
            // 1x1 채우기
            if (paper[1] <= plate)
                paper[1] = 0;
            else
                paper[1] -= plate;
            res += 1;
        }
        while (paper[1] != 0)
        {
            int plate = 36;
            if (paper[1] <= plate)
                paper[1] = 0;
            else
                paper[1] -= plate;
            res += 1;
        }
    }
    cout << res;
    return 0;
}