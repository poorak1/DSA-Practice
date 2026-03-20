class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);

        for(int i = 0; i < n; i++){
            for(char c : words[i]){
                mask[i] |= (1 << (c - 'a'));
            }
        }

        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if((mask[i] & mask[j]) == 0){
                    maxi = max(maxi, (int)words[i].size() * (int)words[j].size());
                }
            }
        }

        return maxi;
    }
};