#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");
int n, m, i, j, c, a[200][200], inf = 99999999;
void roys()
{
    int k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][k] && a[k][j] && (a[i][j] > a[i][k] + a[k][j] || !a[i][j]) && i != j)
                    a[i][j] = a[i][k] + a[k][j];
}
int main()
{
    fin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            fin >> a[i][j];
    roys();
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                fout << "0" << " "; 
            else
                fout << a[i][j] << " ";
        }
        fout << endl;
    }
}
