#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    array<int, 4> a;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(), a.end());

    if (a[3] == a[0] + a[1] + a[2] || a[3] + a[0] == a[1] + a[2]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}