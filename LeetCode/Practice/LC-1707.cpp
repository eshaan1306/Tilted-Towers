class Solution {
public:
    struct node{
        node* links[2];
        node(){
            links[0]=links[1]=nullptr;
        }
        bool containsKey(int bit){
            return links[bit]!=nullptr;
        }
        void put(int bit,node* newNode){
            links[bit]=newNode;
        }
        node* get(int bit){
            return links[bit];
        }
    };

    class trie{
    private:
        node* root;
    public:

        trie(){
            root=new node();
        }
        void insert(int num){
            node* cur=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(!cur->containsKey(bit)){
                    cur->put(bit,new node());
                }
                cur=cur->get(bit);
            }
        }
        int getMaxXor(int num){
            node* cur=root;
            int ans=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(cur->containsKey(1-bit)){
                    ans|=(1<<i);
                    cur=cur->get(1-bit);
                }
                else{
                    cur=cur->get(bit);
                }
            }
            return ans;
        }
    };

    vector<int> maximizeXor(vector<int>& nums,
                            vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> offline;
        for(int i=0;i<queries.size();i++){
            offline.push_back({
                queries[i][1], 
                queries[i][0], 
                i              
            });
        }
        sort(offline.begin(),offline.end());
        trie tr;
        int idx=0;
        int n=nums.size();
        vector<int> ans(queries.size());
        for(auto &q:offline){
            int m=q[0];
            int x=q[1];
            int pos=q[2];
            while(idx<n && nums[idx]<=m){
                tr.insert(nums[idx]);
                idx++;
            }
            if(idx==0){
                ans[pos]=-1;
            }
            else{
                ans[pos]=tr.getMaxXor(x);
            }
        }
        return ans;
    }
};
