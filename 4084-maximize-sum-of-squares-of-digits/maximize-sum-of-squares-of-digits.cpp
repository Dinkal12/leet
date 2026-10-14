class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        int mines = sum/9;
        int reminder = sum%9;

        string ans;
        ans.append(mines,'9');
        if(reminder>0){
            ans+= char('0' + reminder);
        }
        ans.append(num - ans.size(), '0');
        return ans;
    }
};