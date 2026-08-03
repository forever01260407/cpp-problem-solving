#include <bits/stdc++.h>
using namespace std;
int arr[101][25];
int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int findidx(int n)
{
    for (int i = 0; i < 25; i++)
    {
        if (n == prime[i])
            return i;
    }
    return 999;
}
void init()
{
    memset(arr, 0, sizeof(arr));
    for (int i = 2; i <= 100; i++) // 2 1000000000
    {
        for (int j = 0; j < 25; j++) // 過去的已經做好了 就相加
            arr[i][j] = arr[i][j] + arr[i - 1][j];
        // 如果他是質數就加去質數表 如果不是就質數分解 對於I來說
        int temp = i;
        for (int j = 0; j < 25 && prime[j] <= temp; j++)
        {
            while (temp % prime[j] == 0)
            {
                arr[i][j]++;
                temp /= prime[j];
            }
        }
    }
}
int main()
{
    init();
    int n;
    while (cin >> n && n != 0)
    {
        cout << setw(3) << n << "! =";
        int last = 24;
        while (last >= 0 && arr[n][last] == 0)
            last--;
        for (int i = 0; i <= last; i++)
        {
            if (i == 15)
                cout << endl;
            cout << setw(3) << arr[n][i];
        }
        cout << endl;
    }
}