void build(int*a , int*tree , int s ,int e, int treeNode )
{
	if(s==e)
	{
		tree[treeNode]=a[s];
		return ;
	}

	int mid=(s+e)/2;

	build(a,tree,s,mid,2*treeNode);
	build(a,tree,mid+1,e,2*treeNode+1);

	//Change according to question
	tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}

void update(int*a,int*tree,int s,int e,int treeNode,int pos,int val)
{

	if(s==e)
	{
		a[pos]=val;
		tree[treeNode]=val;
		return ;
	}

	int mid=(s+e)/2;

	if(pos<=mid)
		update(a,tree,s,mid,2*treeNode,pos,val);
	
	else
		update(a,tree,mid+1,e,2*treeNode+1,pos,val);

	tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];


}

int query(int*a,int*tree,int s,int e,int treeNode,int l,int r)
{
	if(s>r||e<l)
		return 0;
	if(s>=l&&e<=r)
	{
		return tree[treeNode];
	}

	int mid=(s+e)/2;

	
	return (query(a,tree,s,mid,2*treeNode,l,r) + query(a,tree,mid+1,e,2*treeNode+1,l,r));

}
