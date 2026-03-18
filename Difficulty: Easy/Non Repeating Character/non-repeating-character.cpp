
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        unordered_map<char, int> mpp;
        
        for(char &c: s){
            mpp[c]++;
        }
        
        for(char &c: s){
            if(mpp[c] == 1) return c;
        }
        
        return '$';
    }
};