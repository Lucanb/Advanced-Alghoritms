#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lgput.in");
ofstream out("lgput.out");
const long long mod = 1999999973;

long long Putere(long long n, long long p)
{
    if (p == 0)
        return 1;
    if (p % 2 == 0)
        return Putere(n * n % mod, p / 2);
    return Putere(n * n % mod, p / 2) * n % mod;
}
int main() 
{
    long long n, p;
    in >> n >> p;
    out << Putere(n, p) << '\n';
    return 0;
}