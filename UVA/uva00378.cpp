#include <bits/stdc++.h>
using namespace std;
double A1, A2, B1, B2, C1, C2;
double x1, x2, x3, x4, yy1, y2, y3, y4;
double delta, deltax, deltay;
int main()
{
    int n;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while (n--)
    {
        cin >> x1 >> yy1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        A1 = y2 - yy1;
        B1 = x1 - x2;
        C1 = A1 * x1 + B1 * yy1;
        A2 = y4 - y3;
        B2 = x3 - x4;
        C2 = A2 * x3 + B2 * y3;
        double delta = A1 * B2 - A2 * B1;
        if (delta < 0.0000001 && delta > -0.0000001)
        {
            if (C2 == ((A2 * x1) + (B2 * yy1)))
            {
                cout << "LINE" << endl;
            }
            else
            {
                cout << "NONE" << endl;
            }
        }
        else
        {
            double ansx = (C1 * B2 - C2 * B1) / delta;
            double ansy = (A1 * C2 - A2 * C1) / delta;
            printf("POINT %.2lf %.2lf\n", ansx, ansy);
        }
    }
    cout << "END OF OUTPUT" << endl;
}