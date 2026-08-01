#include <bits/stdc++.h>
using namespace std;
bool ispal(string s)
{
    for (int i = 0; i < (s.length() / 2); i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}
char swit(char a)
{
    if (a == 'A' || a == 'H' || a == 'I' || a == 'M' || a == 'O' || a == 'T' || a == 'U' || a == 'V' || a == 'W' || a == 'X' || a == 'Y' || a == '1' || a == '8')
        return a;
    else if (a == 'E')
        return '3';
    else if (a == '3')
        return 'E';
    else if (a == 'J')
        return 'L';
    else if (a == 'L')
        return 'J';
    else if (a == 'S')
        return '2';
    else if (a == '2')
        return 'S';
    else if (a == 'Z')
        return '5';
    else if (a == '5')
        return 'Z';
    else
        return '*';
}
string initmir(string s)
{
    for (int i = s.length() / 2; (i < s.length()); i++)
    {
        s[i] = swit(s[i]);
    }
    return s;
}
bool ismir(string s)
{
    for (int i = 0; i < (s.length() / 2); i++)
    {
        if (s[i] != s[s.length() - 1 - i] || s[i] == '*' || s[s.length() - 1 - i] == '*')
            return false;
    }
    return true;
}
int main()
{
    string s;
    while (cin >> s)
    {
        bool pal = ispal(s);
        string s2 = initmir(s);
        bool mir = ismir(s2);
        cout << s;
        if (pal && mir)
            cout << " -- is a mirrored palindrome." << endl;
        else if (pal && !mir)
            cout << " -- is a regular palindrome." << endl;
        else if (!pal && mir)
            cout << " -- is a mirrored string." << endl;
        else
            cout << " -- is not a palindrome." << endl;
        cout << endl;
    }
}