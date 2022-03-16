// Cel mai lung subsir comun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
using namespace std;
int v[1025], w[1025], M[1025][1025], st[1025], nr;
int m, n;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
	int i, j;
	fin >> m >> n;
	for (i = 1; i <= m; i++)
		fin >> v[i];
	for (j = 1; j <= n; j++)
		fin >> w[j];
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (v[i] != w[j])
				M[i][j] = max(M[i - 1][j], M[i][j - 1]);
			else
				M[i][j] = M[i - 1][j - 1] + 1;
	fout << M[m][n]<<endl;
	i = m; j = n;
	nr = 0;
    while (M[i - 1][j] > 0 || M[i][j - 1] > 0) 
    {

        if (v[i] == w[j]) 
        {
            nr++;
            st[nr] = v[i];
        }

        if (M[i][j] == M[i - 1][j]) 
        {
            i--;
        }
        else 
         if (M[i][j] == M[i][j - 1]) 
         {
            j--;
         }
        else 
             if (M[i][j] == M[i - 1][j - 1] + 1) 
             {
              i--;
              j--;
             }
    }

    if (v[i] == w[j]) 
    {
        nr++;
        st[nr] = v[i];
    }

    for (int k = nr; k >= 1; k--) {
        fout << st[k] << " ";
    }
}