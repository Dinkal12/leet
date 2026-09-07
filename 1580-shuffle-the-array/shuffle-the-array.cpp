class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int left = 0;
        int right = n;
        vector<int>v;
        while(left < n){

            v.push_back(nums[left]);
            left++;
            v.push_back(nums[right]);
            right++;
            
        }
        return v;
    }
};