
#include <iostream>
using namespace std;
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (m == 0 && n == 0)
            break;
        long long arr[m] = {0};
        int ck = 0;
        int fp = m * n;
        while (ck < fp)
        {
            int temp;
            cin >> temp;
            arr[ck % m] += temp;
            ck++;
        }
        int ans = -1;
        int mx = -1;
        for (int i = 0; i < m; i++)
        {
            if (arr[i] >= mx)
            {
                ans = i;
                mx = arr[i];
            }
        }
        cout << ans + 1 << endl;
    }
}