class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int final = 0;

        for(const int &num: st){
            if(st.find(num-1) == st.end()){
                int tmp = num;
                int curr_length = 1;
                while(st.find(tmp+1) != st.end()){
                    curr_length++;
                    tmp++;
                }
                final = max(final, curr_length);
            }
        }
        return final;
    }
};