class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        
        unordered_map<char, int> mpp;
        unordered_map<char, int> window; 

        for(char &c : t){
            mpp[c]++;
        }

        int have = 0;
        int need = mpp.size();
        int res = INT_MAX;
        int start = 0;
        
        int ptr1 = 0, ptr2 = 0;

        while(ptr2 < s.size() &&  (ptr1 <= ptr2)){
            window[s[ptr2]]++;

            if(mpp[s[ptr2]] == window[s[ptr2]]) have++;

            while(have == need){
                if(ptr2-ptr1+1 < res){
                    res = ptr2-ptr1+1;
                    start = ptr1;
                }

                window[s[ptr1]]--;

                if(mpp.find(s[ptr1]) != mpp.end() && window[s[ptr1]] < mpp[s[ptr1]]){
                    have--;
                }
                ptr1++;
            }
            ptr2++;
        }
        
        return res == INT_MAX? "": s.substr(start, res);
    }
};