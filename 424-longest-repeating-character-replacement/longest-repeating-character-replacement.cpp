class Solution {
public:
    int max_repeating_char(unordered_map<char, int> &mpp){
        int max_freq=0;
        for(auto &pair: mpp){
            max_freq = max(max_freq, pair.second);
        }
        return max_freq;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;

        int result = 0;
        int ptr1 = 0;
        int ptr2 = 0;

        while(ptr2<s.size()){
            mpp[s[ptr2]]++;
            if((ptr2-ptr1+1) - max_repeating_char(mpp)> k){
                mpp[s[ptr1]]--;
                ptr1++;
            }else{
                result = max(result, ptr2-ptr1+1);
            }
            ptr2++;
        }

        return result;
    }
};