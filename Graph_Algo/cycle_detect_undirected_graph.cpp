

/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclicUtil(vector<int> g[], int V, bool visited[], int i, int p)
{
    visited[i] = true;
    
    for(auto it : g[i])
    {
        if(!visited[it])
        {
            if(isCyclicUtil(g, V, visited, it, i))
                return true;
        }
        else if(p != it)
            return true;
    }
    
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
   bool visited[V];
   
   memset(visited, false, sizeof(visited));
   
   for(int i = 0; i < V; i++)
   {
       if(!visited[i])
       {
           if(isCyclicUtil(g, V, visited, i, -1))
                return true;
       }
   }
   
   return false;
}