class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int min = nums1[0];

        for (int i = 1; i < n; i++) {
            if (nums1[i] < min) {
                min = nums1[i];
            }
        }

        if (min % 2 == 1) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};