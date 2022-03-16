#include <iostream>
#include <fstream>
using namespace std;
ifstream in("submultimi.in");
ofstream out("submultimi.out");
int n, sol[20], m;
void afiseaza() {
    for (int i = 1; i <= m; ++i)
        out << sol[i] << " ";
    out <<'\n';
}
void submultimi(int k) {
    if (k == m + 1) {
        afiseaza();
        return;
    }
    for (int i = 1 + sol[k - 1]; i <= n - m + k; ++i) {
        sol[k] = i;
        submultimi(k + 1);
    }
}
int main() {
    in >> n;
    for (m = 1; m <= n; ++m)
        submultimi(1);
    return 0;
}