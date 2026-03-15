class Solution {
  public:
    void helper(int node, vector<vector<int>> &adj, vector<int> &final, vector<int> &vis){
        vis[node] = 1;
        final.push_back(node);
        
        for(int i=0; i<adj[node].size(); i++){
            if(!vis[adj[node][i]]){
                helper(adj[node][i], adj, final, vis);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(adj.size(), 0);
        vector<int> final;
        
        helper(0, adj, final, vis);
        
        return final;
    }
};