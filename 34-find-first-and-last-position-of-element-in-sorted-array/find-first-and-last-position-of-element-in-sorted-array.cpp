class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> final;
        int low = 0;
        int high = nums.size();
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid] >= target) high = mid;
            else low = mid+1;
        }
        int lower_bound = low;
        low = 0;
        high = nums.size();
        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid] > target) high = mid;
            else low = mid+1;
        }
        if(lower_bound == high){
            final.push_back(-1);
            final.push_back(-1);
        }else{
            final.push_back(lower_bound);
            final.push_back(high-1);
        }
        return final;
    }
};