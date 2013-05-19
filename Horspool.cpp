#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;

int table[200];
char text[MAX], pattern[MAX];

int main() {
	int i, j, k, m, n;
	cin >> text >> pattern;
	
	m = strlen(pattern);
	n = strlen(text);
	for (int i = 0; i < 200; i++)
		table[i] = m;
	for (int p = 0; p < m-1; p++)
		table[pattern[p]] = m-p-1;
	
	i = m-1;
	while (i < n) {
		k = 0;
		while(k < m && text[i-k] == pattern[m-1-k])
			k++;
		if (k == m) {
			cout << "Pattern  Found at " << i-k+2 << endl;
			return 0;
		}
		i += table[text[i]];
	//	cout << table[text[i]] << endl;
	}
	cout << "Not Found" << endl;
	return -1;
}
