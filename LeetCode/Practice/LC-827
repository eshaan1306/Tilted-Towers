class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findUpar(parent[u]);
    }
    void unionBySize(int u,int v){
        int upu=findUpar(u);
        int upv=findUpar(v);
        if(upu==upv){
            return;
        }
        if(size[upu]>=size[upv]){
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
        else{
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
    }
};

class Solution {
public:

    int convert(int r,int c,int n){
        return r*n+c;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int di[4]={0,1,0,-1};
        int dj[4]={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==1){
                    int ix=convert(i,j,n);
                    for(int k=0;k<4;k++){
                        int ni=i+di[k];
                        int nj=j+dj[k];
                        if (ni>=0 && nj>=0 && ni<n && nj<n){
                            if (grid[ni][nj]==1){
                                int nix=convert(ni,nj,n);
                                ds.unionBySize(ix,nix);
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==1){
                    int ix=convert(i,j,n);
                    ans=max(ans,ds.size[ix]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j]==0){
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int ni=i+di[k];
                        int nj=j+dj[k];
                        if (ni>=0 && nj>=0 && ni<n && nj<n){
                            if (grid[ni][nj]==1){
                                int nix=convert(ni,nj,n);
                                st.insert(ds.findUpar(nix));
                            }
                        }
                    }
                    int sz=1;
                    for(auto &x:st){
                        sz+=ds.size[x];
                    }
                    ans=max(ans,sz);
                }
            }
        }
        return ans;
    }
};
