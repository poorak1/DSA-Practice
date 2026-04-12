class Solution {
public:
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void sortColors(vector<int>& nums) {
        int ptr0 = 0;
        int ptr1 = nums.size()-1;
        int i=0;
        while(i<=ptr1){
            if(nums[i] == 2){
                swap(nums, i, ptr1);
                ptr1--;
            }else{
                if(nums[i]==0){
                    swap(nums, ptr0, i);
                    ptr0++;
                }
                i++;
            }
        }
    }
};