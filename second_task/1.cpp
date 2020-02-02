// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        for (int right = 1; right  < height.size(); ++right) {
            for (int left = 0; left < right; ++left) {
                maxWater = max(maxWater, min(height[left], height[right]) * (right - left));
            }
        }
        return maxWater;
    }
};
