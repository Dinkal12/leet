class Solution {
public:
    int minSwaps(vector<int>& nums) {
    int n = nums.size();
        vector<pair<pair<int, int>, int>> order;

        for (int i = 0; i < n; ++i) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            order.push_back({{sum, nums[i]}, i});
        }

        sort(order.begin(), order.end());

        vector<int> perm(n);
        for (int i = 0; i < n; ++i) {
            perm[i] = order[i].second;
        }

        int swaps = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (visited[i] || perm[i] == i) continue;

            int cycleLength = 0;
            int cur = i;

            while (!visited[cur]) {
                visited[cur] = true;
                cur = perm[cur];
                ++cycleLength;
            }

            swaps += cycleLength - 1;
        }

        return swaps;
    }    
    
};