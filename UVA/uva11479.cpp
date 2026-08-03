#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long int arr[3];
        for (int j = 1; j <= 3; j++)
            cin >> arr[j - 1];
        sort(arr, arr + 3);
        cout << "Case " << i << ": ";
        if (arr[0] + arr[1] <= arr[2])
        {
            cout << "Invalid" << endl;
        }
        else
        {
            if ((arr[0] == arr[1]) && (arr[1] == arr[2]))
                cout << "Equilateral" << endl;
            else if ((arr[0] == arr[1]) || (arr[1] == arr[2]))
                cout << "Isosceles" << endl;
            else
                cout << "Scalene" << endl;
        }
    }
}