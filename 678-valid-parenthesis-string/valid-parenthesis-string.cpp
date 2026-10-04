class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stLeft;
        stack<int> stStar;

        int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') stLeft.push(i);
            else if(s[i] == '*') stStar.push(i);

            else{
                if(!stLeft.empty()) stLeft.pop();
                else if(!stStar.empty()) stStar.pop();
                else return false;
            }
        }
        while(!stLeft.empty() && !stStar.empty()){
            if(stLeft.top() > stStar.top()) return false;
            stLeft.pop();
            stStar.pop();
        }
        return stLeft.empty();
    }
};