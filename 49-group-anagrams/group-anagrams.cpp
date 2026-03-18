class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(const string &str : strs){
            vector<int> freq(26, 0);

            for(char c : str){
                freq[c - 'a']++;
            }

            string key = "";
            for(int count : freq){
                key += "#" + to_string(count);
            }

            mpp[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto &p : mpp){
            result.push_back(p.second);
        }

        return result;
    }
};