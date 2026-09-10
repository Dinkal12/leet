class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digits;

        while(n>0){
            digits.push_back(n%10);
            n/=10;
        }
        int sum =0;
        int  sign=1;
        for (int i = digits.size()-1; i>=0; i--){
            sum+=sign*digits[i];
            sign *= -1;
        }
        return sum;
    }
};