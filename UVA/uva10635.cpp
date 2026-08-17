#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ck = 0;
    while (n--)
    {
        ck++;
        int a, b, c;
        cin >> a >> b >> c;
        int q[a * a];
        int r[c + 1];
        vector<int> ans;
        memset(q, -1, sizeof(q));
        for (int i = 0; i < b + 1; i++)
        {
            int temp;
            cin >> temp;
            q[temp] = i;
        }
        for (int i = 0; i < c + 1; i++)
        {
            int temp;
            cin >> temp;
            temp = q[temp];
            if (temp != -1)
                ans.push_back(temp);
        }
        cout << endl;
        vector<int> lis;
        for (auto x : ans)
        {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }
        cout << "Case " << ck << ": ";
        cout << lis.size() << endl;
    }
}