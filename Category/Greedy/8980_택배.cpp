#include <algorithm>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct delivery
{
    int fr, to, vol;
};

bool compare(delivery a, delivery b)
{
    if (a.to == b.to)
        return a.fr < b.fr;
    return a.to < b.to;
}

int main()
{
    int n, c, m;
    cin >> n >> c >> m;
    vector<delivery> fedex(m);         // 배송정보 저장 벡터
    vector<int> truck_state(n + 1, c); // 택배 받는 마을에 따른 현재 싣고있는 상자개수

    for (int i = 0; i < m; i++)
        cin >> fedex[i].fr >> fedex[i].to >> fedex[i].vol;

    sort(fedex.begin(), fedex.end(), compare);

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int min_vol = c;
        for (int j = fedex[i].fr; j < fedex[i].to; j++)
        {
            min_vol = min(min_vol, truck_state[j]);
        }
        int vol = fedex[i].vol;
        if (vol > min_vol)
            vol = min_vol;
        ans += vol;
        for (int j = fedex[i].fr; j < fedex[i].to; j++)
        {
            truck_state[j] -= vol;
        }
    }
    cout << ans;
    return 0;
}