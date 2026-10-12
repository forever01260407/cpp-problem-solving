#include <bits/stdc++.h>
using namespace std;
bool vis[10001] = {false};
vector<int> adj[10001];
int ans;
void dfs(int i)
{
    vis[i] = true;
    ans++;
    for (auto x : adj[i])
    {
        if (vis[x] == false)
            dfs(x);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ans = 0;
        for (int i = 0; i <= 10000; i++)
        {
            vis[i] = false;
            adj[i].clear();
        }
        int n, m, l;
        cin >> n >> m >> l;
        // cout << "BBB";
        // cout << "M is " << m << endl;
        for (int i = 0; i < m; i++)
        {
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
        }
        // cout << "HII";
        for (int i = 0; i < l; i++)
        {
            int start;
            cin >> start;
            if (vis[start] == false)
                dfs(start);
        }
        cout << ans << endl;
    }
}