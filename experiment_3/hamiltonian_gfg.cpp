class Solution {
  public:
    
    bool check(int n, int m, vector<vector<int>> edges) {
        
        vector<vector<int>> adj(n + 1);
        
        for (auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        function<bool(int, vector<bool>&, int)> dfs= [&](int u,vector<bool>& vis,int cnt) {
            if (cnt==n) return true;
            for (int v : adj[u]) {
                if (v!=vis[v]) {
                    vis[v] = true;
                    if (dfs(v, vis, cnt+=1)) return true;
                    vis[v] = false;
                }
            }
            return false;
            
        };
        
        for (int i=1; i<=n; i++) {
          vector<bool> vis(n+1,false);
          vis[i]=true;
          if(dfs(i,vis,0)) return true;
         
            
        }
        return false;
    }
};
