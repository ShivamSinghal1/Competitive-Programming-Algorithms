struct DSU
{
    int connected;
    int*par,*sz;   

    DSU() {} 

    DSU(int n)              // n is no. of distinct values possible 
    {
        par=new int [n+1];
        sz=new int [n+1];

        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        connected=n;
    }

    int getPar(int k)               // top parent
    {
        while(k!=par[k])
        {
            par[k]=par[par[k]];//path compress
            k=par[k];
        }
        return k;
    }
    /*
    int getPar(int v)     
    {
        if (v == par[v])
        return v;
        return par[v] = find_set(par[v]); //path compress all(that come in way) assigned topmost
    }
    */
    int getSize(int k)              //size of compo        
    {
        return sz[getPar(k)];
    }

    void unite(int u, int v)        // unites two compo
    {
        int par1=getPar(u), par2=getPar(v);

        if(par1==par2)
            return;

        connected--;

        if(sz[par1]>sz[par2])   //rank by size in (if)
            swap(par1, par2); 

        sz[par2]+=sz[par1];
        sz[par1]=0;
        par[par1]=par[par2];
    }
};
