class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        int i=0;
        string final="";
        
        while(i<s.size()){
            if(s[i] == '.'){
                i++;
                continue;
            }
            string word = "";
            while(i < s.size() && s[i] != '.'){
                word += s[i];
                i++;
            }
            if(final.empty()){
                final = word;
            } else {
                final = word + '.' + final;
            }
        }
        
        return final;
    }
};