/*
Run Time: 0ms
Beats: 100 %ile
Time Complexity: O(n)

Memory Usage: 29.4MB
Beats: 24.08 %ile
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonalSquared = 0.0;
        int maxArea = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int length = dimensions[i][0];
            int width  = dimensions[i][1];
            double currentDiagonalSquared = (double)length * length + (double)width * width;

            if (currentDiagonalSquared > maxDiagonalSquared) {
                maxDiagonalSquared = currentDiagonalSquared;
                maxArea = length * width;
            } else if (currentDiagonalSquared == maxDiagonalSquared) {
                int currentArea = length * width;
                if (currentArea > maxArea) {
                    maxArea = currentArea;
                }
            }
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> rectangles = {{3, 4}, {5, 12}, {8, 15}, {7, 24}, {10, 10}, {20, 5}};

    int result = sol.areaOfMaxDiagonal(rectangles);
    cout << "Area of rectangle with maximum diagonal: " << result << endl;

    return 0;
}