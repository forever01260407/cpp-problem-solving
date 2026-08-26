#include <bits/stdc++.h>
using namespace std;
int warning[50][50];
char af[4] = {'N', 'E', 'S', 'W'};
int nx, ny;
char a;
int x, y;
char sw(char &a, char turns)
{
    int pos = 0;
    for (int i = 0; i < 4; i++)
    {
        if (af[i] == a)
            pos = i;
    }
    if (turns == 'R')
        pos = (pos + 1) % 4;
    else if (turns == 'L')
        pos = (pos + 3) % 4;
    return af[pos];
}
void moves(int &nx, int &ny, char a)
{
    if (a == 'N')
        ny++;
    else if (a == 'S')
        ny--;
    else if (a == 'E')
        nx++;
    else if (a == 'W')
        nx--;
}
bool ee(int nx, int ny)
{
    if (nx > x || nx < 0 || ny > y || ny < 0)
        return true;
    return false;
}
int main()
{
    cin >> x >> y;
    int ox = 0, oy = 0;
    memset(warning, 0, sizeof(warning));
    while (cin >> nx >> ny >> a)
    {
        string s;
        cin >> s;
        int emengy = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R' || s[i] == 'L')
                a = sw(a, s[i]);
            else if (s[i] == 'F')
            {
                int oldx = nx;
                int oldy = ny;
                moves(nx, ny, a);
                if (ee(nx, ny) && warning[oldx][oldy] == 0)
                {
                    cout << oldx << " " << oldy << " " << a << " LOST" << endl;
                    warning[oldx][oldy] = 1;
                    emengy = 1;
                    break;
                }
                else if (ee(nx, ny) && warning[oldx][oldy] == 1)
                {
                    nx = oldx;
                    ny = oldy;
                }
            }
        }
        if (emengy == 0)
            cout << nx << " " << ny << " " << a << endl;
    }
}