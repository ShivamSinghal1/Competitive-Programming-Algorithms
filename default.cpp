#include "bits/stdc++.h"
//#include <boost/math/common_factor.cpp>
using namespace std;
using namespace std::chrono; 
#define     mod             1000000007
#define     mod9            1000000009
#define     MOD             998244353
#define     en              "\n"
#define     MAX             1e9
#define     N               2*1000000+5
#define     ll              long long
#define     int             long long
#define     F               first
#define     S               second
#define     pb              push_back
#define     mp              make_pair
#define     mt              make_tuple
#define     all(p)          p.begin(), p.end()
#define     rep(i,a,b)      for(i=a;i<b;i++)
#define     repr(i,a,b)     for(i=a;i>=b;i--)
#define     t()             int test;cin>>test;while(test--)
#define     setbits(x)      __builtin_popcountll(x)
typedef     set<int>        si;              
typedef     vector<int>     vi;             
typedef     pair<int,int>   pii; 
typedef     priority_queue <int> que_max;     
typedef     priority_queue <int, vi, greater<int>> que_min;
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
int NofDigit(int n){
    return floor(log10(n)) + 1;
}
bool isPowerOfTwo(int x){    
    return x && (!(x&(x-1))); 
}
template <class T1,class T2> 
void input (T1*a,T2 n){ for(int i=0;i<n;i++) cin>>a[i]; }
template <class T1,class T2>
void print (T1*a,T2 n){ for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<en; }
template <class T1>
void print (T1&a){ for(auto i:a) cout<<i<<" "; cout<<en; }

//All Functions below this
 
//Main Function 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start = high_resolution_clock::now();
    //cout<<"Hello Coder!!"<<endl;
    //Code Start



    //Code End
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << (long double)duration.count()<< endl; 
    return 0;
}
/*  
    Waste Code - Not essential that it is waste...

*/
