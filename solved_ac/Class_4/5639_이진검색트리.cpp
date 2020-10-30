#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preV;

void input()
{
    int x;
    while (scanf("%d", &x) != EOF)
    {
        preV.push_back(x);
    }
}

void getPostOrder(int s, int e)
{
    if (s >= e)
        return;
    int upperIndex = distance(preV.begin(), upper_bound(preV.begin() + s + 1, preV.begin() + e, preV[s]));
    getPostOrder(s + 1, upperIndex);
    getPostOrder(upperIndex, e);
    printf("%d\n", preV[s]);
}
int main()
{
    input();
    getPostOrder(0, preV.size());

    return 0;
}