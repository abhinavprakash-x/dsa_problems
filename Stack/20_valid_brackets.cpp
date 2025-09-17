/*
Run Time: 0ms
Beats: 100 %ile
Time Complexity: O(n)

Memory Usage: 8.6MB
Beats: 97.54 %ile
Space Complexity: O(n)
*/
#include <iostream>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        int n = s.length();
        if (n == 0) return true;
        char stack[n];
        int top = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                push(stack, top, s[i], n);
            } else {
                if (!pop(stack, top, s[i])) {
                    return false;
                }
            }
        }
        return (top == -1);
    }

    void push(char a[], int &top, char b, int size) {
        if (top < size - 1) {
            top++;
            a[top] = b;
        }
    }

    bool pop(char a[], int &top, char b) {
        if (top == -1) return false;

        if ((a[top] == '(' && b == ')') ||
            (a[top] == '{' && b == '}') ||
            (a[top] == '[' && b == ']')) {
            top--;
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    // --- Test Cases ---
    std::string s1 = "()[]{}";
    std::cout << "Input: \"" << s1 << "\" -> Is Valid? " << std::boolalpha << sol.isValid(s1) << std::endl;

    std::string s2 = "([{}])";
    std::cout << "Input: \"" << s2 << "\" -> Is Valid? " << std::boolalpha << sol.isValid(s2) << std::endl;

    std::string s3 = "(]";
    std::cout << "Input: \"" << s3 << "\" -> Is Valid? " << std::boolalpha << sol.isValid(s3) << std::endl;

    std::string s4 = "([)]";
    std::cout << "Input: \"" << s4 << "\" -> Is Valid? " << std::boolalpha << sol.isValid(s4) << std::endl;

    std::string s5 = "{[}";
    std::cout << "Input: \"" << s5 << "\" -> Is Valid? " << std::boolalpha << sol.isValid(s5) << std::endl;

    std::string s6 = "(((";
    std::cout << "Input: \"" << s6 << "\" -> Is Valid? " << std::boolalpha << sol.isValid(s6) << std::endl;

    std::string s7 = ")";
    std::cout << "Input: \"" << s7 << "\" -> Is Valid? " << std::boolalpha << sol.isValid(s7) << std::endl;

    return 0;
}