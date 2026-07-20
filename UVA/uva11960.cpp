#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
void pre()
{
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= 1000000; i++)
    {
        int tp = i;
        int k = 1;
        while (tp * k <= 1000000)
        {
            arr[tp * k]++;
            k++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    pre();
    while (n--)
    {
        int inputs;
        cin >> inputs;
        int ans = 1;
        for (int i = 1; i <= inputs; i++)
        {
            if (arr[i] >= arr[ans])
                ans = i;
        }
        cout << ans << endl;
    }
}