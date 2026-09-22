class Solution {
public:

    struct Node{
        int prod;
        long long cnt[5];

        Node(){
            prod = 1;
            for(int i=0;i<5;i++){
                cnt[i] = 0;
            }
        }
    };

    int k,n;
    vector<Node> seg;

    Node merge(Node &left,Node &right){
        Node ans;

        ans.prod = (left.prod * right.prod)%k;

        //prefix completely inside left
        for(int i=0;i<k;i++){
            ans.cnt[i] += left.cnt[i];
        }

        //take entire left + prefix of right
        for(int i=0;i<k;i++){
            int rem = (left.prod*i)%k;
            ans.cnt[rem] += right.cnt[i];
        }

        return ans;
    }

    void build(vector<int>& nums,int node,int l,int r){
        if (l==r){
            int rem = nums[l]%k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }

        int mid = (l+r)/2;

        build(nums,2*node,l,mid);
        build(nums,2*node+1,mid+1,r);

        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }

    void update(int node,int l,int r,int indx,int val){
        if (l==r){
            for(int i=0;i<5;i++){
                seg[node].cnt[i] = 0;
            }

            val %= k;

            seg[node].prod = val;
            seg[node].cnt[val] = 1;
            return;
        }

        int mid = (l+r)/2;

        if (indx<=mid){
            update(2*node,l,mid,indx,val);
        }
        else{
            update(2*node+1,mid+1,r,indx,val);
        }

        seg[node] = merge(seg[2*node],seg[2*node+1]);
    }

    Node query(int node,int l,int r,int ql,int qr){
        if (ql<=l && r<=qr){
            return seg[node];
        }

        int mid = (l+r)/2;

        if (qr<=mid){
            return query(2*node,l,mid,ql,qr);
        }

        if (ql>mid){
            return query(2*node+1,mid+1,r,ql,qr);
        }

        Node left = query(2*node,l,mid,ql,qr);
        Node right = query(2*node+1,mid+1,r,ql,qr);

        return merge(left,right);
    }

    vector<int> resultArray(vector<int>& nums, int K, vector<vector<int>>& queries) {
        k = K;
        n = nums.size();

        seg.resize(4*n);

        build(nums,1,0,n-1);

        vector<int> result;

        for(auto &q:queries){
            int indx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            //this update persists
            update(1,0,n-1,indx,val);

            //after deleting nums[0...start-1]
            //we need prefixes of nums[start...n-1]
            Node curr = query(1,0,n-1,start,n-1);

            result.push_back(curr.cnt[x]);
        }

        return result;
    }
};
