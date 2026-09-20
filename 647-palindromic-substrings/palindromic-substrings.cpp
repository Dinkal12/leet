class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            count += isPalindrome(s,i,i);
            count += isPalindrome(s,i,i+1);
        }
        return count;
    }
    private:
    int isPalindrome(string& s, int l, int r) {
        int count = 0;
        while(l >= 0 && r < s.size() && s[l]==s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }
};