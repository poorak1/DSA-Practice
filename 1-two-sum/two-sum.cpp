class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            if(mpp.find(target - nums[i]) == mpp.end()){
                mpp[nums[i]] = i;
            }else{
                v.push_back(mpp.find(target - nums[i])->second);
                v.push_back(i);
                return v;
            }
        }
        return v;
    }
};