class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> cnt(n + 1, 0);
        long long min_price = LLONG_MAX;

        for (const auto& item : items) {
            ++cnt[item[0]];
            min_price = min(min_price, static_cast<long long>(item[1]));
        }

        vector<long long> mult_cnt(n + 1, 0);
        for (int f = 1; f <= n; ++f) {
            for (int m = f; m <= n; m += f) {
                mult_cnt[f] += cnt[m];
            }
        }

        vector<pair<long long, long long>> bonus_pairs;
        bonus_pairs.reserve(n);
        for (const auto& item : items) {
            int f = item[0];
            long long p = item[1];
            long long bonus = mult_cnt[f] - 1;
            if (bonus > 0 && p < 2LL * min_price) {
                bonus_pairs.emplace_back(p, bonus);
            }
        }

        sort(bonus_pairs.begin(), bonus_pairs.end());

        long long rem = budget;
        long long base = 0;
        long long last_p = -1;

        for (const auto& [p, bonus] : bonus_pairs) {
            if (rem < p) break;
            long long k = min(bonus, rem / p);
            base += 2LL * k;
            rem -= k * p;
            last_p = p;
        }

        long long ans = base + rem / min_price;
        if (last_p != -1) {
            ans = max(ans, (base - 2) + (rem + last_p) / min_price);
        }

        return static_cast<int>(ans);
    }
};