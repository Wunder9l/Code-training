// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
    static const long long MAX_INT = 2147483647;  // 2 ^ 31
    
public:
    int myAtoi(string str) {
        size_t i = 0;
        while (i < str.size() && str[i] == ' ') {
            ++i;
        }
        if (i >= str.size()) {
            return 0;
        }
        
        bool isNegative = false;
        if (str[i] == '+' || str[i] == '-') {
            isNegative = str[i] == '-';
            ++i;
        }
        
        long long num = 0;
        for (; i < str.size(); ++i) {
            if (!std::isdigit(str[i])) {
                break;
            }
            num = num * 10 + (str[i] - '0');
            // cout << num << endl;
            if (num >= MAX_INT) {
                break;
            }
        }
        
        if (num > MAX_INT && isNegative) {
            num = -MAX_INT - 1;
        } else if (num >= MAX_INT && !isNegative) {
            num = MAX_INT;
        } else {
            num = (isNegative ? -1 : 1) * num;    
        }
        return static_cast<int>(num);
    }
    
};
