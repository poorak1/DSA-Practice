class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        stack<char> st;

        for(char &c: num){
            while(!st.empty() && (st.top() > c) && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(k > 0){
        st.pop();
        k--;
        }

        string temp="";
        while(!st.empty()){
            temp+= st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        
        int i = 0;
        while(i < temp.size() && temp[i] == '0') i++;
        temp = temp.substr(i);
        return temp.empty() ? "0" : temp;
    }
};