class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> vis(adj.size(), 0);
        vector<int> final;
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        final.push_back(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i<adj[node].size(); i++){
                if(!vis[adj[node][i]]){
                    final.push_back(adj[node][i]);
                    vis[adj[node][i]] = 1;
                    q.push(adj[node][i]);
                }
            }
        }
        return final;
    }
};