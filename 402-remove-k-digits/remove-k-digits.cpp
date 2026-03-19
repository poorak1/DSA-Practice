class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";

        string st; 

        for(char c : num){
            while(!st.empty() && st.back() > c && k > 0){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        while(k > 0){
            st.pop_back();
            k--;
        }

        int i = 0;
        while(i < st.size() && st[i] == '0') i++;

        string result = st.substr(i);

        return result.empty() ? "0" : result;
    }
};