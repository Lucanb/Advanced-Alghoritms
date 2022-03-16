#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cautbin.in");
ofstream g("cautbin.out");
int v[100001], n, i, mij, x, quest, m, st, dr;
void cautare(int x)
{
    st = 1;
    dr = n;
    while (st <= dr) 
    {
        mij = (st + dr) / 2;
        if (v[mij] == x)
            break;
        else 
            if (v[mij] > x)
            dr = mij - 1;
        else 
            if (v[mij] < x)
            st = mij + 1;
    }
}
int main() 
{
    f >> n;
    for (i = 1; i <= n; i++)
        f >> v[i];
    f >> m;
    for (i = 1; i <= m; i++) 
    {
        f >> quest >> x;
        if (quest == 0)
        {
            cautare(x);
            if (v[mij] == x) 
            {
                while (v[mij + 1] == x)
                    mij++;
                g << mij << '\n';
            }
            else
                g << -1 << '\n';
        }
        if (quest == 1) 
        {
            cautare(x);
            if (v[mij] == x) 
            {
                while (v[mij + 1] == x)
                    mij++;
            }
            else 
                if (v[mij] > x)
                mij--;
            g << mij << '\n';
        }
        if (quest == 2) 
        {
            cautare(x);
            if (v[mij] == x)
            {
                while (v[mij - 1] == v[mij])
                    mij--;
            }
            else 
               if (v[mij] < x)
                mij++;
            g << mij << '\n';
        }
    }
}