class Solution {
public:
    int expand(string &s, int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
                left-=1;
                right+=1;
            }
        return right-left-1;
    }

    string longestPalindrome(string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        string longest_pal="";
        
        for(int i=0; i<s.size(); i++){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);

            int temp_max = max(len1, len2);
            if(temp_max > max_len){
                max_len = temp_max;
                longest_pal = s.substr((i - (temp_max - 1) / 2), temp_max);
            }
        } 
        

        if(max_len == 0) return s.substr(0, 1);
        return longest_pal;
    }
};