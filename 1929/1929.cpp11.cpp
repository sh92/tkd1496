#include <cstdio>
typedef long long ll;

bool isPrime(ll num)
{
  if(num==1)
    return false;
  ll i;
  for(i=2;i*i<= num;i++)
    if(num %i==0)
      return false;
  return true;
}

int main(){
  
  ll a,b;
  scanf("%llu %llu", &a,&b);
    for(ll i=a;i<=b;i++)
    {
      if(isPrime(i))
      {
        printf("%llu\n", i);
      }
    }
  return 0;
}
