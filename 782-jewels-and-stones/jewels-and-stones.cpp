class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool isJewel[128] = {};
        
        for(char c : jewels)
            isJewel[c] = true;
        
        int count = 0;
        for(char c : stones)
            count += isJewel[c];
        
        return count;
    }
};