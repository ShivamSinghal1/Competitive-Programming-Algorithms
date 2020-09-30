struct tree_node{
    int val;
    tree_node()
    {
        //default value
        val = 0;
    }
};
struct segmentTree
{
    int n;
    vector<int> a;
    vector<tree_node> tree;
    segmentTree(int n)
    {
        this->n = n;
        a.resize(n);
        tree.resize(4*n + 5);
    }
    tree_node combine(tree_node i1, tree_node i2)
    {
        // Change this combine function
        // according to the question
        // Example - max , min, sum 
        tree_node result;
        result.val = i1.val + i2.val;
        return result;
    }
    void build(int s,int e,int node)
    {
        if(s==e)
            tree[node].val = a[s];
        else
        {
            int mid=(s+e)/2;
            build(s,mid,2*node);
            build(mid+1,e,2*node+1);
            tree[node] = combine(tree[2*node] , tree[2*node + 1]);
        }
    }
    void update(int pos, int val ,int s ,int e ,int node)
    {
        if(pos<s || pos>e)
            return;
        if(s==e)
            tree[node].val = a[pos] = val;
        else
        {
            int mid = (s + e)/2;
            update(pos , val, s , mid, node*2);
            update(pos , val, mid+1,e ,node*2 + 1);
            tree[node] = combine(tree[2*node] , tree[2*node + 1]);
        }
    }
    tree_node query(int l, int r, int s, int e, int node)
    {
        if(s>r||e<l)
            return tree_node();
        if(s>=l&&e<=r)
            return tree[node];
        int mid=(s+e)/2;
        tree_node left_result = query(l, r, s, mid, 2*node) ;
        tree_node right_result = query(l, r, mid+1, e, 2*node+1);
        tree_node result = combine(left_result , right_result);
        return result;
    }

    void build()
    {
        build(0,n-1,1);
    }
    void update(int pos,int val)
    {
        update(pos, val , 0 , n-1, 1);
    }
    tree_node query(int l,int r)
    {
        return query(l,r,0,n-1,1);
    }
};
/* How to Use - 
segmentTree seg(n); // n is the size of array 
seg.a = v; // Array
seg.build(); // Build the tree
seg.update(pos,val); // do a[pos] = val
seg.query(l,r); // get sum
Zero Based Indexing in Array and 1 Based Indexing in Tree
*/
