class Solution:
    def romanToInt(self, s: str) -> int:
        toInt = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        tmp = 0
        integer = 0
        for c in s:
            i = toInt[c]
            if tmp == 0:
                tmp = i
            elif tmp < i:
                integer += i - tmp
                tmp = 0
            else:
                integer += tmp
                tmp = i
        integer += tmp
        return integer
        
