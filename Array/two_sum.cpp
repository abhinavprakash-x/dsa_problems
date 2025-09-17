#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for (i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int y = target - x;
            for (j = i + 1; j < nums.size(); j++) {
                if (y == nums[j]) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: ";
    for (int i : result) cout << i << " ";
    cout << endl;
    return 0;
}
