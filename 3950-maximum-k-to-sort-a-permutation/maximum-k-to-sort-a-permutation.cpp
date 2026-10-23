class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;
        bool alreadySorted = true;

        for(int i=0; i<nums.size(); ++i){
            if(nums[i] != i){
                alreadySorted = false;
                k&=nums[i];
            }
        }
        return alreadySorted ? 0 : k;
    }
};