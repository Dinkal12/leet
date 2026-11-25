class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        vector<int> sa(n), rank(nums), temp(n);
        iota(sa.begin(), sa.end(), 0);

        for (int len = 1; len < n; len <<= 1) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b]) return rank[a] < rank[b];

                int ra = a + len < n ? rank[a + len] : -1;
                int rb = b + len < n ? rank[b + len] : -1;

                return ra < rb;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1], b = sa[i];

                bool diff = rank[a] != rank[b] ||
                    (a + len < n ? rank[a + len] : -1) !=
                    (b + len < n ? rank[b + len] : -1);

                temp[b] = temp[a] + diff;
            }

            rank = temp;

            if (rank[sa.back()] == n - 1) break;
        }

        vector<int> lcp(n);
        int common = 0;

        for (int i = 0; i < n; i++) {
            int r = rank[i];
            if (r == 0) continue;

            int j = sa[r - 1];

            while (i + common < n && j + common < n &&
                   nums[i + common] == nums[j + common]) {
                common++;
            }

            lcp[r] = common;
            if (common) common--;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            int same = 0;

            if (i > 0) same = max(same, lcp[i]);
            if (i + 1 < n) same = max(same, lcp[i + 1]);

            if (same < n - sa[i]) {
                ans = min(ans, same + 1);
            }
        }

        return ans;
    }
};