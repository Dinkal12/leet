class Solution {
public:
    int maxLength(vector<int>& nums) {
         int n = nums.size(), ans = 1;
        int primes[] = {2, 3, 5, 7};

        for (int l = 0; l < n; l++) {
            int sum[4] = {}, mn[4] = {100, 100, 100, 100}, mx[4] = {};

            for (int r = l; r < n; r++) {
                for (int p = 0; p < 4; p++) {
                    int x = nums[r], count = 0;

                    while (x % primes[p] == 0) {
                        count++;
                        x /= primes[p];
                    }

                    sum[p] += count;
                    mn[p] = min(mn[p], count);
                    mx[p] = max(mx[p], count);
                }

                bool valid = true;

                for (int p = 0; p < 4; p++) {
                    if (sum[p] != mn[p] + mx[p]) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};