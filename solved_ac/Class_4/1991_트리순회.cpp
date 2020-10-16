#include <iostream>

using namespace std;

struct NODE{
    char left;
    char right;
};
NODE tree[27];

void preorder(char root)
{
    if(root=='.')
        return;
    cout<<root;
    preorder(tree[root-'A'].left);
    preorder(tree[root-'A'].right);
}

void inorder(char root)
{
    if(root=='.')
        return;
    inorder(tree[root-'A'].left);
    cout<<root;
    inorder(tree[root-'A'].right);
}

void postordre(char root)
{
    if(root=='.')
        return;
    postordre(tree[root-'A'].left);
    postordre(tree[root-'A'].right);
    cout<<root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    char a,b,c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        tree[a-'A'].left=b;
        tree[a-'A'].right=c;
    }
    preorder('A');
    cout<<'\n';
    inorder('A');
    cout<<'\n';
    postordre('A');

    return 0;
}