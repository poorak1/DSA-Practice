class Solution {
public:
    // int helper(vector<vector<int>> &grid, int i, int j, string &text1, string &text2){
    //     if(i >= text1.size() || j >= text2.size()) return 0;

    //     if(text1[i] == text2[j]) return 1 + helper(grid, i+1, j+1, text1, text2);
    //     return max(helper(grid, i, j+1, text1, text2), helper(grid, i+1, j, text1, text2));
    // }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));

        for(int i = text1.size()-1; i>=0; i--){
            for(int j = text2.size()-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};