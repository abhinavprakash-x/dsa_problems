/*
Run Time: 0ms
Beats: 100 %ile
Time Complexity: O(n)

Memory Usage: 10.1MB
Beats: 78.41 %ile
Space Complexity: O(1)
*/
#include <iostream>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int curr = value(s[i]);
            if (i + 1 < n && curr < value(s[i + 1])) {
                result -= curr;
            } else {
                result += curr;
            }
        }
        return result;
    }
    int value(char a) {
        switch (a) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

int main() {
    Solution sol;
    // --- Test Cases ---

    std::string test1 = "III";
    std::cout << "Roman: " << test1 << " -> Integer: " << sol.romanToInt(test1) << std::endl; // Expected: 3

    std::string test2 = "LVIII";
    std::cout << "Roman: " << test2 << " -> Integer: " << sol.romanToInt(test2) << std::endl; // Expected: 58

    std::string test3 = "MCMXCIV";
    std::cout << "Roman: " << test3 << " -> Integer: " << sol.romanToInt(test3) << std::endl; // Expected: 1994

    return 0;
}