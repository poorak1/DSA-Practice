class Solution {
public:
    bool valid(int capacity, vector<int> &weights, int days){
        int days_used = 1;
        int curr_load = 0;

        for(int w : weights){
            if(curr_load + w <= capacity){
                curr_load += w;
            } else {
                days_used++;
                curr_load = w;
            }

            if(days_used > days) return false;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(valid(mid, weights, days)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};