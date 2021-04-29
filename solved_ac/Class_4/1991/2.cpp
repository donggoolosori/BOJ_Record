#include <iostream>

using namespace std;

int N;

struct Node
{
    char data;
    Node *left, *right;
};
Node *tree;

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree = (Node *)malloc(sizeof(Node) * N);

    char root, left, right;
    for (int i = 0; i < N; i++)
    {
        cin >> root >> left >> right;
        int num = root - 'A';
        tree[num].data = root;
        if (left != '.')
            tree[num].left = &tree[left - 'A'];
        if (right != '.')
            tree[num].right = &tree[right - 'A'];
    }

    preOrder(&tree[0]);
    cout << '\n';
    inOrder(&tree[0]);
    cout << '\n';
    postOrder(&tree[0]);

    free(tree);

    return 0;
}