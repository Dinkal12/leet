class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int largestElement = candies[0];
        
        for(int i = 1; i<n; i++){
            if( largestElement < candies[i]){
                largestElement = candies[i];
            }
        }
        vector<bool> ans;
        for(int i = 0; i<n; i++){
            int c = candies[i] + extraCandies;
            if(c >=largestElement){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;

    }
};