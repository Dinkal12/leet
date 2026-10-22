class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int start = nums[0];
        
        bool increasingRotation = true;
        for(int i = 0; i<n; ++i){
            if(nums[i] != (start + i)%n){
                increasingRotation = false;
                break;
            }
        }
        if(increasingRotation){
            return min((n - start) % n, start + 2);
        }
        int k = (n - 1 - nums[0] + n)%n;
        bool decreasingRotation = true;

        for(int i = 0; i < n; ++i){
            int excepted = (n - 1 - k - i + 2 * n) % n;
            if(nums[i]!=excepted){
                decreasingRotation = false;
                break;
            }
        }
        if(!decreasingRotation) return -1;
        return 1 + min(k,n-k);
    }
};