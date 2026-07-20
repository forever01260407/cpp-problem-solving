#include <bits/stdc++.h>
using namespace std;
int arr[4]; // CHON
void getstring(string s)
{
    char a = 'z';
    memset(arr, 0, sizeof(arr));
    int va = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (va != 0)
            {
                va--;
                if (a == 'C')
                    arr[0] += va;
                else if (a == 'H')
                    arr[1] += va;
                else if (a == 'O')
                    arr[2] += va;
                else if (a == 'N')
                    arr[3] += va;
                va = 0;
            }

            if (s[i] == 'C')
                arr[0]++;
            else if (s[i] == 'H')
                arr[1]++;
            else if (s[i] == 'O')
                arr[2]++;
            else if (s[i] == 'N')
                arr[3]++;
            va = 0;
            a = s[i];
        }
        else
        {
            if (va == 0)
                va = s[i] - '0';
            else
                va = (va * 10) + (s[i] - '0');
        }
        if (i == s.length() - 1 && va != 0)
        {
            va--;
            if (a == 'C')
                arr[0] += va;
            else if (a == 'H')
                arr[1] += va;
            else if (a == 'O')
                arr[2] += va;
            else if (a == 'N')
                arr[3] += va;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        getstring(s);
        double sum = 0;
        double total = 0;
        sum = sum + (arr[0] * 12.01) + (arr[1] * 1.008) + (arr[2] * 16) + (arr[3] * 14.01);
        printf("%.3f\n", sum);
    }
}