#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num[5];
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> num[i];
        sum += num[i];
    }
    sort(num, num + 5);

    // 평균값
    int avg = sum / 5;
    // 중앙값
    int mid = num[2];
    cout << avg << "\n"
         << mid;
    return 0;
}