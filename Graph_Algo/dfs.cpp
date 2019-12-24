class graph
{
    public: 
        int n_v,n_e;
        vector<vector<int>> adj_list;
        bool isDirected;

        void input(bool isDir=true)
        {
            cin>>n_v>>n_e;
            adj_list.resize(n_v);
            isDirected = isDir;
            int to,fro;
            for(int i=0;i<n_e;++i){
                cin>>to>>fro;
                addEdge(to,fro,isDir);
            }
        }

        void addEdge(int to,int fro,bool isDir=true)
        {
            adj_list[to].push_back(fro);
            if(isDir)
                adj_list[fro].push_back(to);
        }

}

void dfs(graph &g, bool* isVisited, int source)
{
    isVisited[source] = true;
    // cout<<source+1<<" "; 

    int i;
    rep(i,0,g.adj_list[source].size())
        if(!isVisited[g.adj_list[source][i]])
            dfs(g,isVisited,g.adj_list[source][i]);
}
