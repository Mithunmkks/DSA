#include <climits>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        // Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Parse digits
        long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // Clamp to INT_MAX or INT_MIN if overflow
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * num;
    }
};
