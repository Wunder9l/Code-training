// https://leetcode.com/problems/palindrome-number/
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int maxDegree = getMaxDegree(x);
        while (x > 0) {
            if (x / maxDegree == x % 10) {
                x = x % maxDegree / 10;
                maxDegree = std::max(1, maxDegree / 100);
            } else {
                return false;
            }
            // std::cout << "isPalindrome"<< x << std::endl; 
        }
        return true;
    }
    
    int getMaxDegree(int x) {
        long long d = 1;
        long long lx = x;
        while (x > d * 10) {
            d = d * 10;
            // std::cout << "getMaxDegree"<< d << std::endl; 
        }
        return static_cast<int>(d);
    }
};
