#include <bits/stdc++.h>
using namespace std;
string preorder, inorder;
int pos = 0;
void dfs(int start, int end)
{
    if (start > end)
        return;
    int mid;
    char root = preorder[pos];
    pos++;
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == root)
        {
            mid = i;
            break;
        }
    }
    dfs(start, mid - 1);
    dfs(mid + 1, end);
    cout << root;
}
int main()
{
    while (cin >> preorder >> inorder)
    {
        pos = 0;
        dfs(0, inorder.length() - 1);
    }
}
