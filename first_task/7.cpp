// https://leetcode.com/problems/reverse-integer/
class Solution {
    static const long long MAX_INT = 2147483648; // 2^31
public:
    int reverse(int x) {
        long long y = x;
        long long res = 0;
        while(y) {
            res = res * 10 + y % 10;
            y /= 10;
        }
        if (res < -MAX_INT || res > MAX_INT-1) {
            res = 0;
        }
        return res;
    }
};