// Longest palindrome in a string in O(N)

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

#define SIZE 1000
#define MIN(M, N) ((M) < (N) ? (M) : (N))
#define MAX(M, N) ((M) > (N) ? (M) : (N))

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each
// end to avoid bounds checking
string precompute(string s) {

    int n = s.length();
    string ret = "^";

    if (n == 0)
        return "^$";

    for (int i = 0; i < n; i++)
        ret += "#" + s.substr(i, 1);
    ret += "#$";

    return ret;
}

string manacher(string s) {

    string T;
    int n, C, R, P[(2*SIZE) - 1], i_mirror;
    int max_pal_length, center_index;

    C = R = 0;
    T = precompute(s);
    n = T.length();
    for (int i = 1; i < n-1; i++) {
        i_mirror = C-(i-C);

        P[i] = (R > i) ? MIN(R-i, P[i_mirror]) : 0;

        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;

        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum element in P.
    max_pal_length = center_index = 0;
    for (int i = 1; i < n-1; i++) {
        if (P[i] > max_pal_length) {
            max_pal_length = P[i];
            center_index = i;
        }
    }

    return s.substr((center_index - 1 - max_pal_length)/2, max_pal_length);
}

int main() {

    string str;

    while(1) {
        cin >> str;
        assert(str.length() < SIZE);

        cout << "Longest Substring Is: " << manacher(str) << endl;
    }

    return 0;
}
