class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> final;
        int previous = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && (nums[i-1] == nums[i])){
                continue;
            }
            int left_ptr = i+1; 
            int right_ptr = nums.size()-1;
            while(right_ptr > left_ptr){
                if(nums[i] + nums[left_ptr] + nums[right_ptr] == 0){
                    vector<int> temp = {nums[i], nums[left_ptr], nums[right_ptr]};
                    final.push_back(temp);
                    int left_val = nums[left_ptr];
                    int right_val = nums[right_ptr];

                    while(left_ptr < right_ptr && nums[left_ptr] == left_val) left_ptr++;
                    while(left_ptr < right_ptr && nums[right_ptr] == right_val) right_ptr--;
                    // break;
                }else if(nums[i] + nums[left_ptr] + nums[right_ptr] > 0){
                    right_ptr-=1;
                }else{
                    left_ptr+=1;
                }
            }
        }

        return final;
    }
};