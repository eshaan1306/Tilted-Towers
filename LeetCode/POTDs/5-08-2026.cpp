class Solution {
public:

    void dfs(int u,vector<int> &vis,vector<vector<int>> &adj){
        vis[u]=1;
        for(auto &v:adj[u]){
            if (!vis[v]){
                dfs(v,vis,adj);
            }
        }
    }

    bool soln(int u,vector<int> &vis,vector<vector<int>> &adj,vector<int> &isSusp){
        vis[u]=1;
        for(auto &v:adj[u]){
            if (isSusp[v]){
                return false;
            }
            if (!vis[v]){
                if (!soln(v,vis,adj,isSusp)){
                    return false;
                }
            }
        }
        return true;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        /*
Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.
        */
        vector<vector<int>> adj(n);
        for(auto &inv:invocations){
            int a=inv[0];
            int b=inv[1];
            adj[a].push_back(b);
            // adj[b].push_back(a);
        }
        //find all the suspicious methods
        vector<int> ans(n,0);
        dfs(k,ans,adj);
        //all the marked ones are suspicious methods and should be removed
        //we have to check that does any method outside of it touches any of these methods
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if (!ans[i] && !vis[i]){
                bool flag = soln(i,vis,adj,ans);
                if (!flag){
                    vector<int> res;
                    for(int i=0;i<n;i++){
                        res.push_back(i);
                    }
                    return res;
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if (!ans[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};
