class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> final;
        auto i = lower_bound(nums.begin(), nums.end(), target);
        auto j = upper_bound(nums.begin(), nums.end(), target);
        int index_i = distance(nums.begin(), i);
        int index_j = distance(nums.begin(), j); 
        if(i==j){
            final.push_back(-1);
            final.push_back(-1);
        }else{
            final.push_back(index_i);
            final.push_back(index_j-1);
        }
        return final;
    }
};