#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

using i64 = long long;

i64 gcd(i64 m, i64 n, i64 mul = 1) {
    if (m == 0 || n == 0 || m == n) {
        return mul * max(m, n);
    }
    if (m == 1 || n == 1) {
        return mul;
    }
    if (m % 2 == 0 && n % 2 == 0) {
        return gcd(m >> 1, n >> 1, mul * 2);
    }
    if (m % 2 == 0) {
        return gcd(m >> 1, n, mul);
    }
    if (n % 2 == 0) {
        return gcd(m, n >> 1, mul);
    }
    if (n > m) {
        return gcd(m, (n - m) >> 1, mul);
    }
    return gcd(n, (m - n) >> 1, mul);
}

int main() {
    int n;
    cin >> n;
    array <i64, n> vertices;
    i64 s = 0;
    for (auto i = 0; i < n; ++i) {
        cin >> vertices[i];
        s  += vertices[i];
    }

    size_t a, b;
    for (auto i = 0; i < n-1; ++i) {
        cin >> a >> b;
    }

    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(), a.end());

    if (a[3] == a[0] + a[1] + a[2] || a[3] + a[0] == a[1] + a[2]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}