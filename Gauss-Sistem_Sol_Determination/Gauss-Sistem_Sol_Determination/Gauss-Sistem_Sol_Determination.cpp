
#include <iostream>
#include <fstream>
#include <iomanip>
#define EPS 0.0000001
using namespace std;
ifstream f("gauss.in");
ofstream g("gauss.out");
int n, m;
long double matr_gauss[401][401], rasp[401];
long double copie_matrice[401][401];
void citire()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            f >> matr_gauss[i][j];
            copie_matrice[i][j] = matr_gauss[i][j];
        }
    }
}
bool null(long double nr)
{
    if (-EPS < nr && nr < EPS)
        return true;
    return false;
}
void schimba_linii(int l1, int l2)
{
    for (int i = 1; i <= m + 1; i++)
        swap(matr_gauss[l1][i], matr_gauss[l2][i]);
}
void aflare_rasp()
{
    for (int i = 1; i <= n; i++)
    {
        long double suma = 0;
        //verificam suma pentru fiecare linie inmultind variabila cu coeficientul
        //in cazul in care suma nu e egala sistemul nu merge
        for (int j = 1; j <= m; j++)
        {
            suma += copie_matrice[i][j] * rasp[j];
        }
        if (!null(suma - copie_matrice[i][m + 1]))
        {
            g << "Imposibil";
            exit(0);
        }
    }

}
void afisare()
{
    for (int i = 1; i <= m; i++)
    {
        g << fixed << setprecision(10) << rasp[i] << " ";
    }
}
void calculare_sistem()
{
    for (int coloana = 1; coloana <= m; coloana++)
    {
        //cautam primul rand cu coloana nenula
        int coloana_nenula = coloana;
        for (int rand = coloana; rand <= n; rand++)
        {
            if (!null(matr_gauss[rand][coloana]))
            {
                coloana_nenula = rand;
                break;
            }
        }

        //vrem sa facem numerele de sub diagonala principala nule
        //unde coloana = rand deci putem folosi coloana pentru a vedea ce linii interschimbam
        schimba_linii(coloana_nenula, coloana);
        if (null(matr_gauss[coloana][coloana]))
            continue;

        //facem 1 primul element de pe linie
        long double primul_element = matr_gauss[coloana][coloana];
        for (int i = 1; i <= m + 1; i++)
        {
            matr_gauss[coloana][i] = (matr_gauss[coloana][i] * 1.00) / primul_element;

        }

        //facem primul element de pe urmatoarea si restul liniilor 0 si scadem ca la efectuarea unui sitem gauss
        for (int i = coloana + 1; i <= n; i++)
        {
            long double primul_element_pe_fiecare_linie = matr_gauss[i][coloana];
            for (int j = 1; j <= m + 1; j++)
            {
                matr_gauss[i][j] -= matr_gauss[coloana][j] * primul_element_pe_fiecare_linie;

            }
        }

        //facem primul element de pe anterioara si restul liniilor 0 si scadem ca la efectuarea unui sitem gauss
        //iar toata matricea va ramane pe fiecare linie cu varibila cu coeficientul 1 si raspunsul sau
        //deci pe fiecare linie pe coloana m+1 se va afla raspunsul pentru fiecare variabila
        for (int i = coloana - 1; i >= 1; i--)
        {
            long double primul_element_pe_fiecare_linie = matr_gauss[i][coloana];
            for (int j = 1; j <= m + 1; j++)
            {
                matr_gauss[i][j] -= matr_gauss[coloana][j] * primul_element_pe_fiecare_linie;

            }
        }


    }
}
int main()
{
    citire();
    calculare_sistem();
    for (int i = 1; i <= n; i++)
    {
        rasp[i] = matr_gauss[i][m + 1];
    }
    aflare_rasp();
    afisare();
}