#include <iostream>
#include <string>
using namespace std;
void NaiveStringMatch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i=0;i<=n-m;i++) {
        int j;
        for (j=0;j<m;j++) {
            if (text[i+j] != pattern[j])
                break;
        }
        if (j == m)
            cout << "Pattern found at index:  " << i << endl;
    }
}
int main() {
    string text;
    cout<<"Enter the text: ";cin>>text;
    string pattern;
    cout<<"Enter the Pattern to find: ";cin>>pattern;
    NaiveStringMatch(text, pattern);
    return 0;
}
