#include <iostream>
#include <fstream>
using namespace std;
int n, st[9], fol[9];
ifstream fin("permutari.in");
ofstream fout("permutari.out");
void afisare()
{
    for (int i = 1; i <= n; i++)
        fout << st[i] << ' ';
    fout << '\n';
}
void gen(int k)
{
    if (k == n + 1)
        afisare();
    for (int i = 1; i <= n; i++)
        if (fol[i] == 0)
        {
            st[k] = i;
            fol[i] = 1;
            gen(k + 1);
            fol[i] = 0;
        }
}
int main()
{
    fin >> n;
    gen(1);
}
