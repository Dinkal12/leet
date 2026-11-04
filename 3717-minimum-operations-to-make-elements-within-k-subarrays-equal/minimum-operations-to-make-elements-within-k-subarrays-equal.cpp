class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<int> mv = nums;

        multiset<int> low, high;
        long long lowSum = 0, highSum = 0;

        auto balance = [&](){
            while(low.size() > high.size() + 1){
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                lowSum -= v;
                high.insert(v);
                highSum += v;
            }
            while(low.size() < high.size()){
                int v = *high.begin();
                high.erase(high.begin());
                highSum -= v;
                low.insert(v);
                lowSum += v;
            }
        };
        auto add = [&](int v) {
            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                lowSum += v;
            } else {
                high.insert(v);
                highSum += v;
            }
            balance();
        };
        auto remove = [&](int v) {
            auto it = low.find(v);

            if (it != low.end()) {
                lowSum -= v;
                low.erase(it);
            } else {
                it = high.find(v);
                highSum -= v;
                high.erase(it);
            }

            balance();
        };
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(mv[i]);

        auto getCost = [&]() {
            long long median = *low.rbegin();
            return median * low.size() - lowSum +
                   highSum - median * high.size();
        };

        cost[0] = getCost();

        for (int r = x; r < n; r++) {
            remove(mv[r - x]);
            add(mv[r]);
            cost[r - x + 1] = getCost();
        }

        const long long INF = 4e18;
        vector<long long> prev(n + 1, 0), curr(n + 1, INF);

        for (int blocks = 1; blocks <= k; blocks++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(curr[i],
                                  prev[i - x] + cost[i - x]);
                }
            }

            swap(prev, curr);
        }

        return prev[n];
    }
};