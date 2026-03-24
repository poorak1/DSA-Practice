class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // build LCS table
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(str1[i] == str2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        // reconstruct SCS
        int i = 0, j = 0;
        string res = "";

        while(i < n && j < m){
            if(str1[i] == str2[j]){
                res += str1[i];
                i++; j++;
            }
            else if(dp[i+1][j] > dp[i][j+1]){
                res += str1[i];
                i++;
            } else {
                res += str2[j];
                j++;
            }
        }

        // append leftovers
        while(i < n) res += str1[i++];
        while(j < m) res += str2[j++];

        return res;
    }
};