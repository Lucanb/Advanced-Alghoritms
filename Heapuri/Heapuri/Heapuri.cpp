#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

#define NMAX 200005

using namespace std;

set <int> heap;

int n, poz[NMAX], k, a, x;

ifstream in("heapuri.in");
ofstream out("heapuri.out");

int main()
{
    in >> n;
    for (int i = 1; i <= n; i++)
    {
        in >> x;
        if (x == 1)
        {
            in >> a;
            heap.insert(a);
            poz[++k] = a;
        }
        else if (x == 2)
        {
            in >> a;
            heap.erase(poz[a]);
        }
        else
            out << *heap.begin() << '\n';
    }
    return 0;
}