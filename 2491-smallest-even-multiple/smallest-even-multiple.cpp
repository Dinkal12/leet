class Solution {
public:
    int smallestEvenMultiple(int n) {
        int out;
        if(n%2==1){
           out = n*2;
        }
        else {
           out = n;
        }
        return out;
    }
};