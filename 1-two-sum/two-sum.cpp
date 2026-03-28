class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> final;
        for(int i=0; i<nums.size(); i++){
            auto found = mpp.find(target - nums[i]); 
            if(found != mpp.end()){
                final.push_back(mpp[target - nums[i]]);
                final.push_back(i);
                return final;
            }else{
                mpp[nums[i]] = i;
            }
        }
        return final;
    }
};