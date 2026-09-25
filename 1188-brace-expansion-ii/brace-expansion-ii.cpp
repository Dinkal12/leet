class Solution {
public:

    set<string> merge(set<string> a, set<string> b){
        set<string> res;

        for(auto x : a){
            for(auto y : b){
                res.insert(x+y);
            }
        }
        return res;
    }

    set<string> solve(string &s, int &i){
        set<string> res;
        set<string> cur = {""};

        while(i<s.size() && s[i] != '}'){
            if(s[i] == '{'){
                i++;
                set<string> inside = solve(s,i);
                i++;
                cur = merge(cur,inside);
            }
            else if(s[i] == ','){
                for(auto x:cur)
                    res.insert(x);
                cur = {""};
                i++;    
            }
            else{
                set<string> letter = {string(1, s[i])};
                cur = merge(cur,letter);
                i++;
            }
         }
         for(auto x:cur)
             res.insert(x);
        return res;
    }


    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression,i);
        return vector<string>(ans.begin(), ans.end());
    }
};