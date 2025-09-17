/*
Run Time: 0ms
Beats: 100 %ile
Time Complexity: O(n log n)

Memory Usage: 8.2MB
Beats: 61.98 %ile
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>

class Solution {
public:
    bool NoZero(int x){
        bool y;
        while(x>0){
            y = x%10 != 0;
            x = x/10;
            if(y == false){
                return false;
            }
        }
        return true;
    }

    std::vector<int> getNoZeroIntegers(int n) {
        int a, b;
        for (int i = 1; i < n; i++) {
            a = i;
            b = n - a;
            if (NoZero(a) && NoZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};

int main() {
    Solution sol;

    // --- Test Cases ---
    int n1 = 11;
    std::vector<int> result1 = sol.getNoZeroIntegers(n1);
    std::cout << "For n = " << n1 << ", found: [" << result1[0] << ", " << result1[1] << "]" << std::endl;

    int n2 = 1010;
    std::vector<int> result2 = sol.getNoZeroIntegers(n2);
    std::cout << "For n = " << n2 << ", found: [" << result2[0] << ", " << result2[1] << "]" << std::endl;

    int n3 = 2;
    std::vector<int> result3 = sol.getNoZeroIntegers(n3);
    std::cout << "For n = " << n3 << ", found: [" << result3[0] << ", " << result3[1] << "]" << std::endl;

    return 0;
}