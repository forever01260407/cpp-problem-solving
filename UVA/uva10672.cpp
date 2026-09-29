#include <bits/stdc++.h>
using namespace std;
int marble[10005];
vector<int> child[10005];
bool hasParent[10005] = {false};
long long int ans = 0;
int dfs(int u)
{
    int balance = marble[u] - 1;
    for (auto x : child[u])
    {
        int childba = dfs(x);
        ans += abs(childba);
        balance += childba;
    }
    return balance;
}
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int nn = n;
        ans = 0;
        memset(marble, 0, sizeof(marble));
        memset(hasParent, false, sizeof(hasParent));
        for (int i = 1; i <= n; i++)
            child[i].clear();
        while (nn--)
        {
            int u, v, count;
            cin >> u >> v >> count;
            marble[u] = v;
            while (count--)
            {
                int x;
                cin >> x;
                child[u].push_back(x);
                hasParent[x] = true;
            }
        }
        int root = -1;
        for (int i = 1; i <= n; i++)
        {
            if (hasParent[i] == false)
                root = i;
        }
        dfs(root);
        cout << ans << endl;
    }
}