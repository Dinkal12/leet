class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n-k+1);
        deque<int> deque;

        for(int r = 0; r < n; r++){
            while(!deque.empty() && deque.front() <= r-k){
                deque.pop_front();
            }
            while(!deque.empty()  && nums[deque.back()] < nums[r]){
                deque.pop_back();
            }
            deque.push_back(r);
            if(r >= k - 1){
                result[r-k+1] = nums[deque.front()];
            }
        }
        return result;
    }
};