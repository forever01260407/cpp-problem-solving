#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ad;
vector<vector<int>> dp;
void dfs(int u, int fa)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int v : ad[u])
    {
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
        dp[u][0] = dp[u][0] + dp[v][1];
        dp[u][1] = dp[u][1] + min(dp[v][1], dp[v][0]);
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        int origin, num;
        char t;
        ad.resize(n);
        dp.resize(n, vector<int>(2, 0));
        cin >> origin >> t >> t >> num >> t;
        ad.clear();
        dp.clear();
        for (int i = 0; i < num; i++)
        {
            int temp;
            cin >> temp;
            ad[origin].push_back(temp);
            ad[temp].push_back(origin);
        }
        // test case
        dfs(0, -1);
        cout << min(dp[0][0], dp[0][1]) << endl;
    }
}
