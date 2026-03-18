class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> map1(256, -1);
        vector<int> map2(256, -1);

        for(int i = 0; i < s.size(); i++){
            unsigned char c1 = s[i];
            unsigned char c2 = t[i];

            if(map1[c1] == -1 && map2[c2] == -1){
                map1[c1] = c2;
                map2[c2] = c1;
            }
            else if(map1[c1] != c2 || map2[c2] != c1){
                return false;
            }
        }

        return true;
    }
};