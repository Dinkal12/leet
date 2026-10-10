class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        vector<long long> diff;
        long long operations = 1LL * k1 + k2;
        long long totalDiff = 0;
        int maxDiff = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            totalDiff += d;
            maxDiff = max(maxDiff, (int)d);
        }

        if (operations >= totalDiff) return 0;

        int low = 0, high = maxDiff;
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (long long d : diff) {
                if (d > mid) needed += d - mid;
            }

            if (needed <= operations)
                high = mid;
            else
                low = mid + 1;
        }

        long long level = low;
        long long used = 0;
        long long answer = 0;

        for (long long d : diff) {
            if (d > level) used += d - level;

            long long finalDiff = min(d, level);
            answer += finalDiff * finalDiff;
        }

        long long remaining = operations - used;
        answer -= remaining * (level * level - (level - 1) * (level - 1));

        return answer;
    }
};