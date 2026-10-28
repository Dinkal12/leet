class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;

        int water = 0;
        int lm = height[l]; 
        int rm = height[r];

        while(l < r){
            if(lm < rm){
                l++;
                lm = max(lm, height[l]);
                water += lm - height[l];
            }
            else{
                r--;
                rm = max(rm, height[r]);
                water += rm - height[r];
            }
        }
        return water;
    }
};