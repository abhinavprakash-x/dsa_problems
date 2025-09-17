/*
Run Time: 0ms
Beats: 100 %ile
Time Complexity: O(log n)

Memory Usage: 8.6MB
Beats: 40.43 %ile
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long num = x, rev_num = 0;
        while (num > 0) {
            int digit = num % 10;
            rev_num = (rev_num * 10) + digit;
            num = num / 10;
        }
        return (x == rev_num);
    }
};

int main() {
    Solution sol;
    int test1 = 121;
    int test2 = -121;
    int test3 = 10;

    cout << test1 << " -> " << (sol.isPalindrome(test1) ? "true" : "false") << endl;
    cout << test2 << " -> " << (sol.isPalindrome(test2) ? "true" : "false") << endl;
    cout << test3 << " -> " << (sol.isPalindrome(test3) ? "true" : "false") << endl;
    return 0;
}
