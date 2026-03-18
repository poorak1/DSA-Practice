class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> final;
        if(p.size()>s.size()) return final;
        vector<int> freq_p(26, 0), freq_s(26, 0);

        for(char c : p) freq_p[c - 'a']++;
        for(int i=0; i<s.size(); i++){
            if(i>=p.size()){
                freq_s[s[i-p.size()] - 'a']--;
            }
            freq_s[s[i] - 'a']++;
            if(freq_p == freq_s) final.push_back(i-p.size()+1);
        }

        return final;
    }
};