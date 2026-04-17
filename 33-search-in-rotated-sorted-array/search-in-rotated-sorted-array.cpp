class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        int mid = low;
        low = 0;
        high = nums.size()-1;
        if(target <= nums[high]){
            low = mid; // 2ND HALF
        }else{
            high = mid-1; // 1ST HALF
        }
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        } 

        return -1;
    }
};