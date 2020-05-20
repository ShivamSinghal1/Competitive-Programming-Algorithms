template <typename T>
struct segmentTree
{
    int n;
    vector<T> a,tree;
    vector<bool> cLazy;
    vector<int> lazy;
    segmentTree(int n)
    {
        this->n = n;
        a.resize(n);
        tree.resize(4*n + 5);
        cLazy.assign(4*n + 5, false);
        lazy.assign(4*n + 5, 0);
    }
    void propagate(int node, int s, int e)
    {
        if(s != e)
        {
            cLazy[node*2] = 1;
            cLazy[node*2 + 1] = 1;
            lazy[node*2] = lazy[node];
            lazy[node*2 + 1] = lazy[node]; 
        }
        tree[node] = (e - s + 1) * lazy[node];
        cLazy[node] = 0;
    }
    T combine(T i1, T i2)
    {
        // Change this combine function
        // according to the question
        // Example - max , min, sum 
        // If T change this will change
        return i1 + i2;
    }
    void build(int s,int e,int node)
    {
        if(s==e)
            tree[node]=a[s];
        else
        {
            int mid=(s+e)/2;
            build(s,mid,2*node);
            build(mid+1,e,2*node+1);
            tree[node] = combine(tree[2*node] , tree[2*node + 1]);
        }
    }
    void update(int l, int r, int val ,int s ,int e ,int node)
    {
        if(cLazy[node])
            propagate(node, s, e);
        if(r<s || l>e)
            return;
        if(l<=s && e<=r)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, s, e);
            return;
        }
        int mid = (s + e)/2;
        update(l,r,val, s , mid, node*2);
        update(l,r,val, mid+1,e ,node*2 + 1);
        tree[node] = combine(tree[2*node] , tree[2*node + 1]);
    }
    T query(int l, int r, int s, int e, int node)
    {
        if(cLazy[node])
            propagate(node, s, e);
        if(s>r||e<l)
            // If T change this will change
            return 0;
        if(s>=l&&e<=r)
            return tree[node];
        int mid=(s+e)/2;
        T left_result = query(l, r, s, mid, 2*node) ;
        T right_result = query(l, r, mid+1, e, 2*node+1);
        return  combine(left_result ,right_result);
    }

    void build()
    {
        build(0,n-1,1);
    }
    void update(int pos,int val)
    {
        update(pos,pos, val , 0 , n-1,1);
    }
    void update(int l,int r,int val)
    {
        update(l,r, val , 0 , n-1,1);
    }
    T query(int l,int r)
    {
        return query(l,r,0,n-1,1);
    }
};
/* USE - 
segmentTree<int> seg(n) // n is the size of array 
seg.a = v // Array
seg.build() // Build the tree
seg.update(l,r,val) // a[l] = a[l+1] = ... = a[r] = val
seg.update(pos,val) // do a[pos] = val
seg.query(l,r) // get sum
*/
