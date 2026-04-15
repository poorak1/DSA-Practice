class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotonic queue which stores elements in descending order
        deque<int> q; // store index in q
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            while(!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1){
                result.push_back(nums[q.front()]);
            }

        }
        return result;
    }
};