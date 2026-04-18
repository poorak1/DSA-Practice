class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        ans = (ans == -1) ? nums.size():ans;
        return ans;
    }
};