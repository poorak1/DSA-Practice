class Solution {
public:
    void helper(vector<string> &result, string &curr, int open, int close){
        if(open == 0 && close == 0){
            result.push_back(curr);
            return;
        }

        if(open > 0){
            curr.push_back('(');
            helper(result, curr, open - 1, close);
            curr.pop_back();
        }

        if(close > open){
            curr.push_back(')');
            helper(result, curr, open, close - 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        helper(result, curr, n, n);
        return result;
    }
};