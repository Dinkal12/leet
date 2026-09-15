class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int i = 0; i<nums.size();i++){
            st.insert(nums[i]);
        }
        int x =0;
        for(int i : st) {
            nums[x]=i;
            x++;
        }
        return st.size();
    }
};