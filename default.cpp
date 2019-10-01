#include <bits/stdc++.h>
using namespace std;
#define             fi              first
#define             sec             second
#define             mod             1000000007
#define             mod9            1000000009
#define             ll              long long
#define             pii             pair<int ,int>
#define             pll             pair<ll,ll>
#define             pb              push_back
#define             rep(i,a,b)      for(i=a;i<b;i++)
#define             mp              make_pair
#define             t()             int t;cin>>t;while(t--)
#define             vll             vector<ll>


#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
