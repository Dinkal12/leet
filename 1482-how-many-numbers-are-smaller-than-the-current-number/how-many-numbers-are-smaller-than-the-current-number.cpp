class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> n = nums;
        sort(n.begin(), n.end());

        unordered_map<int, int> mp;

        for(int i = 0; i < n.size(); i++) {
            if(mp.find(n[i]) == mp.end()) {
                mp[n[i]] = i;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            nums[i]=mp[nums[i]];
        }
        return nums;

    }
};