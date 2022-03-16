using namespace std;
#include<iostream>
#include<fstream>

int m, n;
int a[1025], b[1025], dp[1025][1025], f[1025], nrf;

int main() {

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin >> m >> n;

    for (int i = 1; i <= m; i++) {
        fin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        fin >> b[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] != b[j]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    fout << dp[m][n] << endl;


    int i = m, j = n;
    nrf = 0;

    while (dp[i - 1][j] > 0 || dp[i][j - 1] > 0) {

        if (a[i] == b[j]) {
            nrf++;
            f[nrf] = a[i];
        }

        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            i--;
            j--;
        }
    }

    if (a[i] == b[j]) {
        nrf++;
        f[nrf] = a[i];
    }

    for (int k = nrf; k >= 1; k--) {
        fout << f[k] << " ";
    }


    fin.close();
    fout.close();

    return 0;
}