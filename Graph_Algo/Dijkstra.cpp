/*
Time complexity: O(ELogV))
*/

#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define pll pair<ll,ll>
#define f first
#define s second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inf 0x3f3f3f3f
using namespace std;
ll n;

void addEdge(vector<pair<ll,ll>>adj[], ll u, ll v, ll wt)
{ 
    adj[u].pb({v, wt}); 
    adj[v].pb({u, wt}); 
}

void dijkstra(vector<pair<ll,ll>>adj[], vector<ll>&dist, ll s)
{ 
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq; 
    pq.push({0,s}); 
    dist[s]=0; 
    while(!pq.empty())
    { 
        ll u=pq.top().second; 
        pq.pop();  
        for(auto x: adj[u])
        {
            ll v=x.f; 
            ll wt=x.s; 
            if(dist[v]>dist[u]+wt)
            { 
                dist[v]=dist[u]+wt; 
                pq.push({dist[v],v}); 
            } 
        } 
    } 
} 

int main()
{ 
    fio;
    n=9; 
    vector<pair<ll,ll>>adj[n+1]; 
    vector<ll>dist(n+1,inf); 
    addEdge(adj,0,1,4); 
    addEdge(adj,0,7,8); 
    addEdge(adj,1,2,8); 
    addEdge(adj,1,7,11); 
    addEdge(adj,2,3,7); 
    addEdge(adj,2,8,2); 
    addEdge(adj,2,5,4); 
    addEdge(adj,3,4,9); 
    addEdge(adj,3,5,14); 
    addEdge(adj,4,5,10); 
    addEdge(adj,5,6,2); 
    addEdge(adj,6,7,1); 
    addEdge(adj,6,8,6); 
    addEdge(adj,7,8,7); 
    dijkstra(adj,dist,0); 
    cout<<"Distance of vertex from node 0: \n";
    for(ll i=0;i<n;i++)
        cout<<i<<"->"<<dist[i]<<"\n";
    return 0; 
} 

/*
OUTPUT:                                                                     8     7   
  Distance of vertex from node 0:                                         1-----2-----3
  0->0                                                                4 /|    2|\    |\ 9
  1->4                                                                 / |11   | \ 14| \
  2->12                                                               0  |     8  \  |  4
  3->19                                                                \ |  7/ |  4\ | /
  4->21                                                               8 \|  / 6|    \|/ 10
  5->11                                                                  7-----6-----5
  6->9                                                                      1     2
  7->8                                                                     
  8->14                                                                     
*/
