class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if (node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbyRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if (ulp_u==ulp_v) return;
        if (rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if (rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if (ulp_u==ulp_v) return;
        if (size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else if (size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
