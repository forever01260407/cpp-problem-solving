#include <bits/stdc++.h>
using namespace std;
bool used[18] = {false};
int point = 0;
int ans[18] = {-1};
int limit;
bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void dfs2()
{
    if (point == limit && isprime(ans[point] + ans[1]))
    {
        for (int i = 1; i <= limit; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 2; i <= limit; i++)
    {
        if ((used[i] == false) && isprime(ans[point] + i))
        {
            point++;
            ans[point] = i;
            used[i] = true;
            dfs2();
            ans[point] = -1;
            point--;
            used[i] = false;
        }
    }
}
int main()
{
    ans[1] = 1;
    used[1] = true;
    point = 1;
    int ck = 1;
    while (cin >> limit)
    {
        cout << "Case " << ck << ":" << endl;
        dfs2();
        cout << endl;
        ck++;
    }
}