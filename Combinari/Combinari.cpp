#include <iostream>
#include <fstream>
using namespace std;
int n, m, st[20], fol[20];
ifstream fin("combinari.in");
ofstream fout("combinari.out");
void afisare()
{
    for (int i = 1; i <= m; i++)
        fout << st[i] << ' ';
    fout <<'\n';
}
void generare(int k)
{
    if (k == m + 1)
        afisare();
    else
        for (int i = 1; i <= n; i++)
            if (fol[i] == 0 && i > st[k - 1])
            {
                st[k] = i;
                fol[i] = 1;
                generare(k + 1);
                fol[i] = 0;
            }
}
int main()
{
    fin >> n >> m;
    generare(1);
}