class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    int atMost(vector<int>& nums, int k ){
        unordered_map<int,int> map;
        int count = 0;
        int l = 0;
        
        for(int r = 0; r < nums.size(); r++){
            map[nums[r]]++;
            while(map.size() > k){
                map[nums[l]]--;
                if(map[nums[l]] == 0 ){
                    map.erase(nums[l]);
                }
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
};