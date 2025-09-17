/*
Run Time: 0ms
Beats: 100 %ile
Time Complexity: O(n)

Memory Usage: 9.4MB
Beats: 60.61 %ile
Space Complexity: O(1)
*/
#include <iostream>
#include <string>

class Solution {
public:
    int maxFreqSum(std::string s) {
        int vowels[5] = {0};
        int consonants[21] = {0};

        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'a': vowels[0]++; break;
                case 'e': vowels[1]++; break;
                case 'i': vowels[2]++; break;
                case 'o': vowels[3]++; break;
                case 'u': vowels[4]++; break;
                case 'b': consonants[0]++; break;
                case 'c': consonants[1]++; break;
                case 'd': consonants[2]++; break;
                case 'f': consonants[3]++; break;
                case 'g': consonants[4]++; break;
                case 'h': consonants[5]++; break;
                case 'j': consonants[6]++; break;
                case 'k': consonants[7]++; break;
                case 'l': consonants[8]++; break;
                case 'm': consonants[9]++; break;
                case 'n': consonants[10]++; break;
                case 'p': consonants[11]++; break;
                case 'q': consonants[12]++; break;
                case 'r': consonants[13]++; break;
                case 's': consonants[14]++; break;
                case 't': consonants[15]++; break;
                case 'v': consonants[16]++; break;
                case 'w': consonants[17]++; break;
                case 'x': consonants[18]++; break;
                case 'y': consonants[19]++; break;
                case 'z': consonants[20]++; break;
            }
        }

        int max_1 = 0;
        for (int i = 0; i < 5; i++) {
            if (max_1< vowels[i]) {
                max_1 = vowels[i];
            }
        }

        int max_2 = 0;
        for (int i = 0; i < 21; i++) {
            if (max_2 < consonants[i]) {
                max_2 = consonants[i];
            }
        }

        return max_1 + max_2;
    }
};

int main() {
    Solution sol;

    // --- Test Cases ---
    std::string test1 = "i love programming";
    std::cout << "Input string: \"" << test1 << "\"" << std::endl;
    std::cout << "Max Frequency Sum: " << sol.maxFreqSum(test1) << std::endl << std::endl;

    std::string test2 = "mississippi";
    std::cout << "Input string: \"" << test2 << "\"" << std::endl;
    std::cout << "Max Frequency Sum: " << sol.maxFreqSum(test2) << std::endl;

    return 0;
}