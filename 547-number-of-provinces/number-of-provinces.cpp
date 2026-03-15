class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj_li, vector<int> &vis){
        vis[node] = 1;

        for(int i=0; i<adj_li[node].size(); i++){
            if(!vis[adj_li[node][i]]){
                dfs(adj_li[node][i], adj_li, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj_li(isConnected.size());
        vector<int> vis(isConnected.size(), 0);
        int final=0;

        int m = isConnected.size(); 
        int n = isConnected[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((isConnected[i][j] == 1) && (i!=j)){
                    adj_li[i].push_back(j);
                    adj_li[j].push_back(i);
                }
            }
        }

        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                final++;
                dfs(i, adj_li, vis);
            }
        }

        return final;
        
    }
};