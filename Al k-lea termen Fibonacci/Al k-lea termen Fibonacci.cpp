#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("kfib.in");
ofstream fout("kfib.out");
long long m[4][4], f[4][4], sol[4][4], mod = 666013;
void matrice(long long a[4][4], long long b[4][4])
{
    long long s, i, j, k, c[4][4];
    for (i = 1; i <= 2; i++)
        for (j = 1; j <= 2; j++)
        {
            s = 0;
            for (k = 1; k <= 2; k++)
                s += a[i][k] * b[k][j];
            s %= mod;
            c[i][j] = s;
        }
    for (i = 1; i <= 2; i++)
        for (j = 1; j <= 2; j++)
            a[i][j] = c[i][j];
}

void lg(long long exp)
{
    while (exp != 0)
    {
        if (exp % 2 == 1)
            matrice(sol, m);
        exp /= 2;
        matrice(m, m);
    }
}

int main()
{
    long long  k;
    fin >> k;
    if (k == 0)
    {
        fout << 0 << '\n';
        exit(0);
    }
    m[1][2] = 1;
    m[2][1] = 1, m[2][2] = 1;
    f[1][1] = 1, f[1][2] = 1;
    sol[1][1] = 1, sol[2][2] = 1;
    lg(k - 1);
    matrice(f, sol);
    fout << f[1][1] << '\n';
    return 0;
}