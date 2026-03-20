class Solution {
public:
    bool is_palindrome(string &str){
        int n = str.size();
        for(int i=0; i<(n/2); i++){
            if(str[i] !=  str[n-1-i]) return false;
        }
        return true;
    }

    void helper(string s, vector<string> &partitions, vector<vector<string>> &results){
        if(s.size() == 0){ 
            results.push_back(partitions);
            return; 
        }

        for(int i = 0; i<s.size(); i++){
            string tmp = s.substr(0, i+1);
            if(is_palindrome(tmp)){
                partitions.push_back(tmp);
                helper(s.substr(i+1), partitions, results);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> partitions;
        helper(s, partitions, results);

        return results;
    }
};