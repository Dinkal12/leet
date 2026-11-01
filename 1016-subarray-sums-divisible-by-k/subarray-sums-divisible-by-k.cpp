class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        count[0] = 1;

        int sum = 0, ans = 0;

        for (int x : nums) {
            sum = (sum + x) % k;

            if (sum < 0) sum += k;

            ans += count[sum];
            count[sum]++;
        }

        return ans;
    }
};