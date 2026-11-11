class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        for (long long both : {0LL, 1LL * min(need1, need2),
                               1LL * max(need1, need2)}) {
            long long cost = both * costBoth;
            cost += max(0LL, 1LL * need1 - both) * cost1;
            cost += max(0LL, 1LL * need2 - both) * cost2;

            ans = min(ans, cost);
        }

        return ans;
    }
};