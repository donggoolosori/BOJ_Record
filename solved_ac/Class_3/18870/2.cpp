#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    vector<int> sortNums(nums);
    // 오름차순 정렬
    sort(sortNums.begin(), sortNums.end());
    // 중복제거
    sortNums.erase(unique(sortNums.begin(), sortNums.end()), sortNums.end());

    for (int i = 0; i < N; i++)
    {
        auto idx = lower_bound(sortNums.begin(), sortNums.end(), nums[i]);
        cout << idx - sortNums.begin() << ' ';
    }

    return 0;
}