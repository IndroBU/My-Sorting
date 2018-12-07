#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ct=1;
ll Aray[5000005];
ll Lower_bound(ll A[], ll Key)
{
    if(ct==0) ct=1;
    ll Begin=0,End=ct-1,Mid,Index=-1;
    while(Begin<=End)
    {
          Mid=(Begin+End)/2;
          if(Key==A[Mid])
          {
              Index=Mid;
              End=Mid-1;

          }
         else if(Key>A[Mid]) Begin=Mid+1;
         else if(Key<A[Mid]) End=Mid-1;

    }
    return Begin;
}
ll A[5000005];
ll Temp[5000005];
int main()
{
   ll n,i,num;
   while(scanf("%lld",&n)&&n>0){
   ll j,k;
   for(i=0; i<n; i++) scanf("%lld",&A[i]);
   Aray[0]=A[0];
   ct=0;
   ll lb=0;
   for(i=1; i<n; i++)
   {
        lb=Lower_bound(Aray,A[i]);
        if(lb>=ct)
        {
            Aray[ct++]=A[i];
        }
        else
        {
            ll ct1=0;
            for( j=lb; j<ct; j++)
            {
                Temp[ct1++]=Aray[j];
            }
            for( j=lb, k=0; j<ct, k<ct1; j++,k++)
            {
                Aray[j+1]=Temp[k];
            }
            Aray[lb]=A[i];
            ct = ct + 1;
        }
   }

   for(i=0; i<n-1; i++)
   {
      printf("%lld ",Aray[i]);
   }

   printf("%lld\n",Aray[n-1]);
   }
  return 0;
}
