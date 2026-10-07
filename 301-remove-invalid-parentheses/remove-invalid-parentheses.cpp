class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int removeOpen = 0, removeClose = 0;
        for(char ch:s){
            if(ch=='('){
                removeOpen++;
            }
            else if (ch == ')') {
                if (removeOpen > 0) {
                    removeOpen--;
                } else {
                    removeClose++;
                }
            }
        }
        unordered_set<string> result;
        string current;
        dfs(s, 0, 0, removeOpen, removeClose, current, result);
        return vector<string>(result.begin(), result.end());
    }

private:
    void dfs(const string& s, int index, int balance, int removeOpen, int removeClose, string& current, unordered_set<string>& result){
          
        if (index == s.size()) {
            if (balance == 0 && removeOpen == 0 && removeClose == 0) {
                result.insert(current);
            }
            return;
        }

         char ch = s[index];

        if (ch == '(') {
            if (removeOpen > 0) {
                dfs(s, index + 1, balance, removeOpen - 1, removeClose,
                    current, result);
            }

            current.push_back(ch);
            dfs(s, index + 1, balance + 1, removeOpen, removeClose,
                current, result);
            current.pop_back();

        } else if (ch == ')') {
            if (removeClose > 0) {
                dfs(s, index + 1, balance, removeOpen, removeClose - 1,
                    current, result);
            }

            if (balance > 0) {
                current.push_back(ch);
                dfs(s, index + 1, balance - 1, removeOpen, removeClose,
                    current, result);
                current.pop_back();
            }

        } else {
            current.push_back(ch);
            dfs(s, index + 1, balance, removeOpen, removeClose,
                current, result);
            current.pop_back();
        }
    }
};