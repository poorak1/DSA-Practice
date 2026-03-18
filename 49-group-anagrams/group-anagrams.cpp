class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> final;
        for(string str: strs){
            string sorted_parent = str;
            sort(sorted_parent.begin(), sorted_parent.end());
            mpp[sorted_parent].push_back(str);
        }

        for(auto &pair: mpp){
            final.push_back(pair.second);
        }

        return final;
    }
};