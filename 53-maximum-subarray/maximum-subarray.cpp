class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maxSum = nums[0];
        int cSum = 0;

        for (int num : nums) {
            cSum += num;
            maxSum = max(maxSum, cSum);

            if (cSum < 0) {
                cSum = 0;
            }
        }  
      return maxSum;
    }
};