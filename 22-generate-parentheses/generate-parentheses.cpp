class Solution {
public:
    bool valid_parenthesis(string &curr_str){
        stack<int> st;
        for(char &c: curr_str){
            if(c == '(') st.push(')');
            else if(c == '{') st.push('}');
            else if(c == '[') st.push(']');
            else if(st.empty() || c!=st.top()) return false;
            else st.pop();
        }
        return st.empty();
    }

    void helper(vector<string> &result, string &curr_str, int curr_open, int curr_closed){
        if((!curr_open) && (!curr_closed)){
            if(valid_parenthesis(curr_str)) result.push_back(curr_str);
            return;    
        }

        if(curr_open == 0){
            curr_str = curr_str + string (curr_closed, ')');
            helper(result, curr_str, 0, 0);
            curr_str = curr_str.substr(0, curr_str.size() - curr_closed); 
            return;
        }

        if(curr_closed == 0){
            curr_str = curr_str + string (curr_open, '(');
            helper(result, curr_str, 0, 0);
            curr_str = curr_str.substr(0, curr_str.size() - curr_open); 
            return;
        }

        curr_str = curr_str + "(";
        helper(result, curr_str, curr_open-1, curr_closed);
        curr_str.pop_back();
        
        curr_str = curr_str + ")";
        helper(result, curr_str, curr_open, curr_closed-1);
        curr_str.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr_str;
        int open_braces = n;
        int closed_braces = n;

        helper(result, curr_str, open_braces, closed_braces);
        return result;
    }
};