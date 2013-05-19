#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 19000000
using namespace std;

char pattern[MAX], text[MAX];
int f[MAX];

void generatePrefix () {
    int k, m;
    k = 0;
    f[1] = 0;
    m = strlen (pattern + 1);
    for (int i = 2; i <= m; i++) {
        while (k > 0 && pattern[k + 1] != pattern[i])
            k = f[k];
        if (pattern[k + 1] == pattern[i])
            k++;
        f[i] = k;
    }
}

int KMPMatcher () {
    int m, n, counter, k;

    k = counter = 0;
    m = strlen (pattern + 1);
    n = strlen (text + 1);
    
    for (int i = 1; i <= n; i++) {
        while (k > 0 && pattern[k + 1] != text[i])
            k = f[k];
        if (pattern[k + 1] == text[i])
            k++;
        if (k == m) {
            counter++;
            k = f[k];
        }
    }
    return counter;
}

int main () {
    int found;
    cin >> (text + 1) >> (pattern + 1);
    
    generatePrefix ();

    if (!(found = KMPMatcher ()))
        cout << "Pattern Not Found In Text" << endl;
    else
        cout << "Pattern Found " << found << " Times" << endl;
    return 0;
}
