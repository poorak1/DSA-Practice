class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;

        int ptr_one = 0;
        int ptr_two = 0;
        int max_len = 0;

        while((ptr_two >= ptr_one) && (ptr_two < s.size()) && (ptr_one >= 0)){
            if(mpp.find(s[ptr_two]) == mpp.end()){
                mpp[s[ptr_two]] = ptr_two;
            }else{
                ptr_one = max(ptr_one, mpp[s[ptr_two]] + 1);
                mpp[s[ptr_two]] = ptr_two;
            }
            max_len = max(max_len, ptr_two-ptr_one+1);
            ptr_two++;
        }

        return max_len;
    }
};