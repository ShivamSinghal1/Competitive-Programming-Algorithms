bool graph::toposort() //Returns 1 if there exists a toposort, 0 if there is a cycle
{
    indeg.resize(n_v); 
    fill(all(indeg),0);
    que_min pq;
    for(int i=0;i<n_v;i++)
        for(auto &it:adj_list[i])
            indeg[it]++;
    for(int i=0;i<n_v;i++)
        if(!indeg[i])
            pq.push(i);
    while(!pq.empty())
    {
        int u=pq.top();
        pq.pop();
        topo.push_back(u+1);
        for(auto &v:adj_list[u])
        {
            indeg[v]--;
            if(!indeg[v])
                pq.push(v);
        }
    }
    if(topo.size()<n_v)
        return 0;
    return 1;
}
