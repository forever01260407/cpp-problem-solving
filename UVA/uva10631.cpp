#include <bits/stdc++.h>
using namespace std;
string st[5];
string ans = "";
void clears()
{
    for (int i = 0; i < 5; i++)
        st[i] = "";
    ans = "";
}
void wri(string s)
{
    int reg = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<' && reg == 0)
            reg = 1;
        if (s[i] == '>' && reg == 1)
            reg = 2;
        if (s[i] == '<' && reg == 2)
            reg = 3;
        if (s[i] == '>' && reg == 3)
            reg = 4;
        // check status...
        // cout << reg << endl;
        if (s[i] != '>' && s[i] != '<')
        {
            st[reg] = st[reg] + s[i];
            ans = ans + s[i];
        }
    }
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        // cout << s.length() << endl;
        clears();
        wri(s);
        // cout << st[0] << endl;
        // cout << st[1] << endl;
        // cout << st[2] << endl;
        // cout << st[3] << endl;
        // cout << st[4] << endl;
        cout << ans << endl;
        string v;
        getline(cin, v);
        string v2 = "";
        for (int i = 0; i < v.length() - 3; i++)
        {
            v2 = v2 + v[i];
        }
        v2 = v2 + st[3];
        v2 = v2 + st[2];
        // v2 = v2 + " ";
        v2 = v2 + st[1];
        v2 = v2 + st[4];
        cout << v2 << endl;
    }
}