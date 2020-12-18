#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define MOD 1000000007
#define INF 1000000000000000000
#define endll "\n"
#define pb push_back
#define forn(i,n) for(i=0;i<n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define vpll vector<pair<ll,ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define ff first
#define ss second
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 vll SortCharacters(string& s)
 {
  vll order(s.length());
  ll count[27]={0},i;
  for(i=0;i<s.length()-1;i++)
  {
    count[s[i]-'A'+1]++;
  }
  count[0]++;
  for(i=1;i<27;i++)
  {
    count[i]=count[i]+count[i-1];
  }
  
  order[0]=s.length()-1;
  for(i=s.length()-2;i>=0;i--)
  {
    ll x=s[i]-'A'+1;
    count[x]-=1;
    order[count[x]]=i;
  }
  return order;
 }

 vll ComputeCharClasses(string& s, vll& order)
 {
  vll clss(s.length());
  ll i;
  clss[order[0]]=0;
  for(i=1;i<s.length();i++)
  {
    if(s[order[i]]!=s[order[i-1]])
      clss[order[i]]=clss[order[i-1]]+1;
    else
      clss[order[i]]=clss[order[i-1]];
  }
  return clss;
 }

 vll SortDoubled(string& s,ll len,vll& order,vll& clss)
 {
  ll count[s.length()]={0};
  ll i,start,cl;
  vll newOrder(s.length());
  for(i=0;i<s.length();i++)
  {
    count[clss[i]]++;
  }
  for(i=1;i<s.length();i++)
  {
    count[i]=count[i]+count[i-1];
  }
  for(i=s.length()-1;i>=0;i--)
  {
    start=(order[i]-len+s.length())%s.length();
    cl=clss[start];
    count[cl]-=1;
    newOrder[count[cl]]=start;
  }
  return newOrder;
 }

 vll UpdateClasses(vll& newOrder,vll& clss,ll len)
 {
  ll n=newOrder.size(),i,cur,prev,midprev,mid;
  vll newClass(n);
  newClass[newOrder[0]]=0;
  for(i=1;i<n;i++)
  {
    cur=newOrder[i];
    prev=newOrder[i-1];
    mid=(cur+len)%n;
    midprev=(prev+len)%n;
    if(clss[cur]!=clss[prev] || clss[mid]!=clss[midprev])
      newClass[cur]=newClass[prev]+1;
    else
      newClass[cur]=newClass[prev];
  }
  return newClass;
 }

int main()
{
  fast_io;
  string s;
  cin>>s;
  ll i;
  vll order=SortCharacters(s);
  vll clss=ComputeCharClasses(s,order);
  ll len=1;
  while(len<s.length())
  {
    order=SortDoubled(s,len,order,clss);
    clss=UpdateClasses(order,clss,len);
    len=2*len;
  }
  for(i=0;i<s.length();i++)
    cout<<order[i]<<" ";
  cout<<endl;
  return 0;
}

/* Example: AAA$
   Output: 3 2 1 0 */
