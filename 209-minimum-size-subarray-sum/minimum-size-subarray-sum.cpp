class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int count = 1e9;
        int n = nums.size();
        int ans = 0;
        for(int right = 0; right < n; right++){
            ans =  ans + nums[right];

            while(ans>=target){
                count = min(right-left+1,count);
                ans -= nums[left];
                left++;      
            }


        }
        if(count == 1e9){
            return 0;
        }
        return count;

    }
};