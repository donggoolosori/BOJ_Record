#include <iostream>
#define MAX 100001

using namespace std;

int N;
int indexs[MAX], in[MAX], post[MAX];

void printPreOrder(int is, int ie, int ps, int pe)
{
    if (is > ie || ps > pe)
        return;
    int mid = indexs[post[pe]];
    cout << in[mid] << ' ';

    int l_size = mid - is, r_size = ie - mid;

    // 왼쪽 서브트리 탐색
    printPreOrder(is, mid - 1, ps, ps + l_size - 1);
    // 오른쪽 서브트리 탐색
    printPreOrder(mid + 1, ie, ps + l_size, pe - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> in[i];
        indexs[in[i]] = i;
    }
    for (int i = 0; i < N; i++)
        cin >> post[i];

    printPreOrder(0, N - 1, 0, N - 1);

    return 0;
}