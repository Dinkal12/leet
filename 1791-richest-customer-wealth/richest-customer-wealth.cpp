class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for(auto &customer : accounts){
            int sum = 0;
            for(int money : customer){
                sum += money;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};