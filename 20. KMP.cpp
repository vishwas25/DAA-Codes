#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeLPS(string pattern, vector<int>& lps) {
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
     cout << "LPS table for " << pattern << ": ";
    for (int i = 0; i < m; ++i) {
        cout << lps[i] << " ";
    }
    cout << endl;
}

void kmpMatch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m);

    computeLPS(pattern, lps);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i-j << endl;
            j = lps[j-1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text;
    cout<<"Enter the text:";cin>>text;
    string pattern;
    cout<<"Enter the pattern:";cin>>pattern;

    kmpMatch(text, pattern);

    return 0;
}

//Enter the string: ababcabcabababd
//
//
//Enter the pattern: ababd
//
//
//The pattern is matched......
//
//The given pattern ababd is found at index: 10
