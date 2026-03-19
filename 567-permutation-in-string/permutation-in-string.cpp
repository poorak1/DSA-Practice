class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        vector<int> freq_s2(26, 0);
        vector<int> freq_s1(26, 0);

        for(char &c: s1){
            freq_s1[c - 'a']++;
        }

        for(int i=0; i<s2.size(); i++){
            if(i>=s1.size()){
                freq_s2[s2[i-s1.size()] - 'a']--;
            }
            freq_s2[s2[i] - 'a']++;
            if(freq_s2 == freq_s1) return true;  
        }
        return false;
    }
};