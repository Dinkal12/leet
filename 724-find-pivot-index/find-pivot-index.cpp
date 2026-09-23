class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        int n = nums.size();
        int leftSum = 0;

        for(int left = 0; left < n; left++){
            int rightSum = totalSum - leftSum - nums[left];
            if(leftSum == rightSum){
                return left;
            }
            leftSum += nums[left];
        }
        return -1;
    }
};