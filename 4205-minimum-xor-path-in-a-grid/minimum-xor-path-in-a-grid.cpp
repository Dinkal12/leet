class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<bitset<1024>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<1024> next;

                if (i == 0 && j == 0) {
                    next[grid[i][j]] = 1;
                } else {
                    for (int x = 0; x < 1024; x++) {
                        if (i > 0 && dp[j][x])
                            next[x ^ grid[i][j]] = 1;

                        if (j > 0 && dp[j - 1][x])
                            next[x ^ grid[i][j]] = 1;
                    }
                }

                dp[j] = next;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) return x;
        }

        return -1;
    }
};