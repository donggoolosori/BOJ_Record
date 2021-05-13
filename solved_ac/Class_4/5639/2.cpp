#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preOrder;

void printPostOrder(int s, int e)
{
    if (s >= e)
        return;
    int mid = distance(preOrder.begin(), upper_bound(preOrder.begin() + s + 1, preOrder.begin() + e, preOrder[s]));
    printPostOrder(s + 1, mid);
    printPostOrder(mid, e);
    printf("%d\n", preOrder[s]);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
        preOrder.push_back(n);

    printPostOrder(0, preOrder.size());

    return 0;
}