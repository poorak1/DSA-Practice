class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        vector<int> freq(128, 0);

        // build freq map
        for(char c : t) freq[c]++;

        int required = t.size();  // total chars needed
        int ptr1 = 0;
        int min_len = INT_MAX;
        int start = 0;

        for(int ptr2 = 0; ptr2 < s.size(); ptr2++){
            if(freq[s[ptr2]] > 0) required--;

            freq[s[ptr2]]--;

            // valid window
            while(required == 0){
                if(ptr2 - ptr1 + 1 < min_len){
                    min_len = ptr2 - ptr1 + 1;
                    start = ptr1;
                }

                freq[s[ptr1]]++;

                if(freq[s[ptr1]] > 0) required++;

                ptr1++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};