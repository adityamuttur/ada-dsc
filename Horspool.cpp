#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define SIZE 100000
#define MAXCHAR 1000

int shiftTable[MAXCHAR], textLength, patternLength;
char text[SIZE], pattern[SIZE];

int main() {
    cin >> text >> pattern;
    
    //Shift Table
    textLength    = strlen(text);
    patternLength = strlen(pattern);
    for (int i = 0; i < MAXCHAR; i++)
        shiftTable[i] = patternLength;
    for (int i = 0; i < patternLength - 1; i++)
        shiftTable[pattern[i]] = patternLength - i - 1;
    
    //Matching string
    int i = patternLength-1, k;
    while (i < textLength) {
        k = 0;
        while(pattern[patternLength-k-1] == text[i-k] && k < patternLength)
            k++;
        if (k == patternLength) {
            cout << "Pattern Found At: " << i-k+2 << endl;
            return 0;
        }
        else
            i += shiftTable[text[i]];
    }
    cout << "Not Found" << endl;
    return -1;
}
