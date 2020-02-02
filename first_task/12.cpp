#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int changed = 0;
    for (auto i = 0; i < n && changed < k; ++i) {
        if (i == 0 && s[i] != '1') {
            s[i] = '1';
            changed++;
        }
        if (i != 0 && s[i] != '0') {
            s[i] = '0';
            changed++;
        }
    }
    if (n == 1 && k > 0) {
        s[0] = '0';
    }
    cout << s << endl;
}