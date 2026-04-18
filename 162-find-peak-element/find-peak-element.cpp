class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
		if(nums.size() == 1) return 0; // single element
        
        int n = nums.size();
        
		// check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
		
		// search in the remaining array
        int start = 1;
        int end = n-2;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid; // case 1 where mid is the peak
            else if(nums[mid] < nums[mid-1]) end = mid - 1; // case 2 where peak is on the left
            else if(nums[mid] < nums[mid+1]) start = mid + 1; // case 3 where peak is on the right
        }
        return -1; // dummy return 
    }
};