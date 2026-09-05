class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++){

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while(left < right){
            if (nums[left] + nums[right] + nums[i] == 0){
                v.push_back({nums[left],nums[right],nums[i]});
                left++;
                right--;
            while(left<right && left<nums.size()  && nums[left]==nums[left-1]){
                left++;
            }
            while(left<right && nums[right]==nums[right+1]){
                right--;
            }

            }

            else if(nums[left] + nums[right] + nums[i]  > 0){
                right --;
            }
            else{
                left++;
            }

        }
    }
        return v;
    }
};