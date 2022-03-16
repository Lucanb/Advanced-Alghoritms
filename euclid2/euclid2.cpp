#include <fstream>
using namespace std;
unsigned long long euclid(unsigned long long x, unsigned long long y)
{
    unsigned long long r;
    if (x > y)
    {
        r = x % y;
        while (r >= 1)
        {
            x = y;
            y = r;
            r = x % y;
        }
        return y;
    }
    else
    {
        r = y % x;
        while (r >= 1)
        {
            y = x;
            x = r;
            r = y % x;
        }
        return x;
    }
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    unsigned long long n, x, y;
    f >> n;
    for (unsigned long long i = 1; i <= n; ++i)
    {
        f >> x >> y;
        g << euclid(x, y) << '\n';
    }
    f.close();
    g.close();
    return 0;
}