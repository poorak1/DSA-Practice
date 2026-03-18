class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c); 
        }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int length = s.length();
        for(int i=0; i<length/2; i++){
            if(s[i] != s[length-i-1]){
            return false;
        }
        }
        return true;
    }
};