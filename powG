ll powG(ll int x,ll int y )
{

  if(y==1)return x;
  if(y==0)return 1;

  ll int temp=powG(x,y/2);

  temp = fun(temp,temp);

  if(y&1)
    temp=fun(temp,x);
  
return temp;
}
