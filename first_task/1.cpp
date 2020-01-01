// https://leetcode.com/problems/two-sum/ 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> intToIndex;
        for (int i = 0; i < nums.size(); ++i) {
            if (intToIndex.count(target - nums[i])) {
                return {intToIndex[target - nums[i]], i};
            }
            intToIndex[nums[i]] = i;
        }
        return vector<int>();
    }
};
