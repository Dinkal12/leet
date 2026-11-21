class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++)
            children[parent[i]].push_back(i);

        vector<int> newParent = parent;
        vector<int> order;
        vector<vector<int>> last(26);

        stack<pair<int, int>> st;
        st.push({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (state == 0) {
                if (u != 0 && !last[c].empty())
                    newParent[u] = last[c].back();

                last[c].push_back(u);
                order.push_back(u);

                st.push({u, 1});

                for (int v : children[u])
                    st.push({v, 0});
            } else {
                last[c].pop_back();
            }
        }

        vector<int> ans(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};