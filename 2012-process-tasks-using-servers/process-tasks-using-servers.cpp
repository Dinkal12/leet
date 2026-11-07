class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > freeServers;

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > busyServers;

        for (int i = 0; i < servers.size(); i++)
            freeServers.push({servers[i], i});

        vector<int> ans(tasks.size());
        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            while (!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                auto [finish, weight, index] = busyServers.top();
                busyServers.pop();
                freeServers.push({weight, index});
            }

            if (freeServers.empty()) {
                time = get<0>(busyServers.top());

                while (!busyServers.empty() && get<0>(busyServers.top()) <= time) {
                    auto [finish, weight, index] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({weight, index});
                }
            }

            auto [weight, index] = freeServers.top();
            freeServers.pop();

            ans[i] = index;
            busyServers.push({time + tasks[i], weight, index});
        }

        return ans; 
    }
};