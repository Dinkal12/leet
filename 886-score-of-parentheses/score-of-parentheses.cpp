class Solution {
public:
    int scoreOfParentheses(string s) {
        int d=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') d++;
            else{
                d--;
                if(s[i-1] == '('){
                    cnt+=pow(2,d);
                }
            }
        }
        return cnt;
    }
};